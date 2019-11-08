/*
  Luiza Torello Vieira    - 171044266
  Victor Azadinho Miranda - 171042191

  Camera:
    W, A, S, D      - Movimentam a câmera no espaço
    Setas/Mouse*    - Gira a câmera
    Barra de Espaço - Sobe a câmera
    Shift Esquerdo  - Desce a câmera
    F11             - Alterna o modo de tela inteira

    * Para ativar/desativar o mouse clique uma vez na janela
    
  Braço:
    Z, X, C, V      - Rotacionam a junta selecionada
    B               - Alterna entre as juntas
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <GL/freeglut.h>

#define INITIAL_WIDTH 800
#define INITIAL_HEIGHT 600

#ifndef DEG_TO_RAD
#define DEG_TO_RAD 0.017453292519943295769236907684886
#endif

#define WINDOW_TITLE_PREFIX "Braco mequanico"

struct WindowStruct {
  int CurrentWidth;
  int CurrentHeight;
  double CurrentRatio;
  int WindowHandle;
  unsigned FrameCount;
} Window = {INITIAL_WIDTH, INITIAL_HEIGHT, ((double)INITIAL_WIDTH / INITIAL_HEIGHT), 0, 0};

struct CameraStruct {
  double eyeX;
  double eyeY;
  double eyeZ;
  double centerX;
  double centerY;
  double centerZ;
  double upX;
  double upY;
  double upZ;
  double inclination;
  double rotation;
} Camera = {15.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 90.0, 180.0};

struct KeyboardStruct {
  bool keyStates[256];
  bool specialStates[256];
} Keyboard;

struct JointStruct {
  double inclination;
  double rotation;
  double positionX;
  double positionY;
  double positionZ;
};

enum JointEnum {
  BOTTOM,
  MIDDLE,
  TOP
};

struct ArmStruct {
  struct JointStruct JointA;
  struct JointStruct JointB;
  struct JointStruct JointC;
  enum JointEnum selection;
} Arm = {
  {0.0, 0.0, 0.0, 0.0, 0.0},
  {0.0, 0.0, 0.0, 0.0, 0.0},
  {0.0, 0.0, 0.0, 0.0, 0.0},
  BOTTOM
};

bool enableMouseMovement = false;

void Initialize(int, char*[]);
void InitWindow(int, char*[]);
void ResizeFunction(int, int);
void RenderFunction(void);
void TimerFunction(int);
void IdleFunction(void);
void UpdateCameraCenter(void);
void KeyDownFunction(unsigned char, int, int);
void KeyUpFunction(unsigned char, int, int);
void SpecialDownFunction(int, int, int);
void SpecialUpFunction(int, int, int);
void KeyOperations(void);
void MouseFunction(int, int, int, int);
void PassiveMotionFunction(int, int);

int main(int argc, char* argv[]) {
  Initialize(argc, argv);

  glutMainLoop();

  exit(EXIT_SUCCESS);
}

void Initialize(int argc, char* argv[]) {
  for(int i = 0; i < 256; i++) {
    Keyboard.keyStates[i] = false;
    Keyboard.specialStates[i] = false;
  }
  
  InitWindow(argc, argv);

  fprintf(
    stdout,
    "INFO: OpenGL version: %s\n",
    glGetString(GL_VERSION)
  );

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void InitWindow(int argc, char* argv[]) {
  glutInit(&argc, argv);

  // glutInitContextVersion(4, 0);
  // glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
  // glutInitContextProfile(GLUT_CORE_PROFILE);

  glutSetOption(
    GLUT_ACTION_ON_WINDOW_CLOSE,
    GLUT_ACTION_GLUTMAINLOOP_RETURNS
  );

  glutInitWindowSize(Window.CurrentWidth, Window.CurrentHeight);

  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

  Window.WindowHandle = glutCreateWindow(WINDOW_TITLE_PREFIX);

  if(Window.WindowHandle < 1) {
    fprintf(
      stderr,
      "ERROR: Could not create a new rendering window.\n"
    );
    exit(EXIT_FAILURE);
  }

  glEnable(GL_DEPTH_TEST);

  UpdateCameraCenter();

  glutReshapeFunc(ResizeFunction);
  glutDisplayFunc(RenderFunction);
  glutIdleFunc(IdleFunction);
  glutTimerFunc(0, TimerFunction, 0);
  glutKeyboardFunc(KeyDownFunction);
  glutKeyboardUpFunc(KeyUpFunction);
  glutSpecialFunc(SpecialDownFunction);
  glutSpecialUpFunc(SpecialUpFunction);
  glutMouseFunc(MouseFunction);
}

void ResizeFunction(int Width, int Height) {
  Window.CurrentWidth = Width;
  Window.CurrentHeight = Height;
  Window.CurrentRatio = ((double)Window.CurrentWidth / Window.CurrentHeight);
  glViewport(0, 0, Window.CurrentWidth, Window.CurrentHeight);
}

void RenderFunction(void) {
  ++Window.FrameCount;
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  KeyOperations();

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(
    (45.0 * Window.CurrentRatio),
    Window.CurrentRatio,
    Window.CurrentRatio,
    (100.0 * Window.CurrentRatio)
  );
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(
    Camera.eyeX,
    Camera.eyeY,
    Camera.eyeZ,
    Camera.centerX,
    Camera.centerY,
    Camera.centerZ,
    Camera.upX,
    Camera.upY,
    Camera.upZ
  );

  glPushMatrix();
  glScaled(1.0, 0.0, 1.0);
  glColor3ub(100, 100, 100);
  glutSolidCube(50.0);
  glPopMatrix();

  glPushMatrix();
  if(Arm.selection == BOTTOM)
    glColor3ub(17, 206, 158);
  else
    glColor3ub(206, 17, 65);
  glRotated(Arm.JointA.rotation, 0.0, 1.0, 0.0);
  glutSolidSphere(1.2, 20, 20);

  glRotated(Arm.JointA.inclination, 1.0, 0.0, 0.0);
  glScaled(1.0, 5.0, 1.0);
  glTranslated(0.0, 0.5, 0.0);
  glColor3ub(200, 75, 75);
  glutSolidCube(1.0);

  glScaled(1.0, 0.2, 1.0);
  glTranslated(0.0, 2.5, 0.0);
  if(Arm.selection == MIDDLE)
    glColor3ub(17, 206, 158);
  else
    glColor3ub(206, 17, 65);
  glRotated(Arm.JointB.rotation, 0.0, 1.0, 0.0);
  glutSolidSphere(1.2, 20, 20);

  glRotated(Arm.JointB.inclination, 1.0, 0.0, 0.0);
  glScaled(1.0, 5.0, 1.0);
  glTranslated(0.0, 0.5, 0.0);
  glColor3ub(200, 75, 75);
  glutSolidCube(1.0);

  glScaled(1.0, 0.2, 1.0);
  glTranslated(0.0, 2.5, 0.0);
  if(Arm.selection == TOP)
    glColor3ub(17, 206, 158);
  else
    glColor3ub(206, 17, 65);
  glRotated(Arm.JointC.rotation, 0.0, 1.0, 0.0);
  glutSolidSphere(1.2, 20, 20);

  glRotated(Arm.JointC.inclination, 1.0, 0.0, 0.0);
  glScaled(1.0, 3.0, 1.0);
  glTranslated(0.0, 0.5, 0.0);
  glColor3ub(200, 75, 75);
  glutSolidCube(1.0);
  glPopMatrix();
  
  glutSwapBuffers();
  glutPostRedisplay();
}

void IdleFunction(void) {
  glutPostRedisplay();
}

void TimerFunction(int Value) {
  if(Value != 0) {
    char *TempString = malloc(512 + strlen(WINDOW_TITLE_PREFIX));
    
    sprintf(
      TempString,
      "%s: %d Frames Per Second @ %d x %d",
      WINDOW_TITLE_PREFIX,
      Window.FrameCount * 4,
      Window.CurrentWidth,
      Window.CurrentHeight
    );

    glutSetWindowTitle(TempString);
    free(TempString);
  }

  Window.FrameCount = 0;
  glutTimerFunc(250, TimerFunction, 1);
}

void UpdateCameraCenter(void) {
  Camera.centerX =
    (sin(DEG_TO_RAD * Camera.inclination) * cos(DEG_TO_RAD * Camera.rotation) + Camera.eyeX);
  Camera.centerY =
    (cos(DEG_TO_RAD * Camera.inclination) + Camera.eyeY);
  Camera.centerZ =
    (sin(DEG_TO_RAD * Camera.inclination) * sin(DEG_TO_RAD * Camera.rotation) + Camera.eyeZ);
}

void KeyDownFunction(unsigned char Key, int X, int Y) {
  Keyboard.keyStates[Key] = true;

  switch(Key) {
    case 'b':
      if(Arm.selection < 2)
        Arm.selection++;
      else
        Arm.selection = 0;
      break;
  }
}

void KeyUpFunction(unsigned char Key, int X, int Y) {
  Keyboard.keyStates[Key] = false;
}

void SpecialDownFunction(int Key, int X, int Y) {
  Keyboard.specialStates[Key] = true;

  if(Keyboard.specialStates[GLUT_KEY_F11]) {
    glutFullScreenToggle();
  }
}

void SpecialUpFunction(int Key, int X, int Y) {
  Keyboard.specialStates[Key] = false;
}

void KeyOperations(void) {
  double aux;

  if(Keyboard.keyStates['w']) {
    Camera.eyeX = Camera.centerX;
    Camera.eyeY = Camera.centerY;
    Camera.eyeZ = Camera.centerZ;
    UpdateCameraCenter();
  }
  if(Keyboard.keyStates['s']) {
    Camera.rotation += 180;
    Camera.inclination = -(Camera.inclination - 90) + 90;
    UpdateCameraCenter();
    Camera.eyeX = Camera.centerX;
    Camera.eyeY = Camera.centerY;
    Camera.eyeZ = Camera.centerZ;
    Camera.rotation -= 180;
    Camera.inclination = -(Camera.inclination - 90) + 90;
    UpdateCameraCenter();
  }
  if(Keyboard.keyStates['a']) {
    aux = Camera.inclination;
    Camera.rotation -= 90;
    Camera.inclination = 90;
    UpdateCameraCenter();
    Camera.eyeX = Camera.centerX;
    Camera.eyeY = Camera.centerY;
    Camera.eyeZ = Camera.centerZ;
    Camera.rotation += 90;
    Camera.inclination = aux;
    UpdateCameraCenter();
  }
  if(Keyboard.keyStates['d']) {
    aux = Camera.inclination;
    Camera.rotation += 90;
    Camera.inclination = 90;
    UpdateCameraCenter();
    Camera.eyeX = Camera.centerX;
    Camera.eyeY = Camera.centerY;
    Camera.eyeZ = Camera.centerZ;
    Camera.rotation -= 90;
    Camera.inclination = aux;
    UpdateCameraCenter();
  }
  if(Keyboard.keyStates[' ']) {
    aux = Camera.inclination;
    Camera.inclination = 0;
    UpdateCameraCenter();
    Camera.eyeX = Camera.centerX;
    Camera.eyeY = Camera.centerY;
    Camera.eyeZ = Camera.centerZ;
    Camera.inclination = aux;
    UpdateCameraCenter();
  }

  if(Keyboard.specialStates[GLUT_KEY_LEFT]) {
    Camera.rotation--;
    if(Camera.rotation < 0)
      Camera.rotation = 359;
    UpdateCameraCenter();
  }
  if(Keyboard.specialStates[GLUT_KEY_RIGHT]) {
    Camera.rotation++;
    if(Camera.rotation > 359)
      Camera.rotation = 0;
    UpdateCameraCenter();
  }
  if(Keyboard.specialStates[GLUT_KEY_UP]) {
    if(Camera.inclination > 45)
      Camera.inclination--;
    UpdateCameraCenter();
  }
  if(Keyboard.specialStates[GLUT_KEY_DOWN]) {
    if(Camera.inclination < 135)
      Camera.inclination++;
    UpdateCameraCenter();
  }
  if(Keyboard.specialStates[GLUT_KEY_SHIFT_L]) {
    aux = Camera.inclination;
    Camera.inclination = 180;
    UpdateCameraCenter();
    Camera.eyeX = Camera.centerX;
    Camera.eyeY = Camera.centerY;
    Camera.eyeZ = Camera.centerZ;
    Camera.inclination = aux;
    UpdateCameraCenter();
  }

  switch(Arm.selection) {
    case BOTTOM:
      if(Keyboard.keyStates['z']) {
        if(Arm.JointA.inclination < 45)
          Arm.JointA.inclination++;
      }
      if(Keyboard.keyStates['x']) {
        if(Arm.JointA.inclination > -45)
          Arm.JointA.inclination--;
      }
      if(Keyboard.keyStates['c']) {
        Arm.JointA.rotation++;
        if(Arm.JointA.rotation > 359) 
          Arm.JointA.rotation = 0;
      }
      if(Keyboard.keyStates['v']) {
        Arm.JointA.rotation--;
        if(Arm.JointA.rotation < 0) 
          Arm.JointA.rotation = 359;
      }
      break;
    case MIDDLE:
      if(Keyboard.keyStates['z']) {
        if(Arm.JointB.inclination < 45)
          Arm.JointB.inclination++;
      }
      if(Keyboard.keyStates['x']) {
        if(Arm.JointB.inclination > -45)
          Arm.JointB.inclination--;
      }
      if(Keyboard.keyStates['c']) {
        Arm.JointB.rotation++;
        if(Arm.JointB.rotation > 359) 
          Arm.JointB.rotation = 0;
      }
      if(Keyboard.keyStates['v']) {
        Arm.JointB.rotation--;
        if(Arm.JointB.rotation < 0)
          Arm.JointB.rotation = 359;
      }
      break;
    case TOP:
      if(Keyboard.keyStates['z']) {
        if(Arm.JointC.inclination < 45)
          Arm.JointC.inclination++;
      }
      if(Keyboard.keyStates['x']) {
        if(Arm.JointC.inclination > -45)
          Arm.JointC.inclination--;
      }
      if(Keyboard.keyStates['c']) {
        Arm.JointC.rotation++;
        if(Arm.JointC.rotation > 359) 
          Arm.JointC.rotation = 0;
      }
      if(Keyboard.keyStates['v'])
        Arm.JointC.rotation--;
        if(Arm.JointC.rotation < 0)
          Arm.JointC.rotation = 359;
      break;
  }
}

void MouseFunction(int Button, int State, int X, int Y) {
  if(Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN)
    enableMouseMovement = !enableMouseMovement;
  
  if(enableMouseMovement) {
    glutPassiveMotionFunc(PassiveMotionFunction);
    glutSetCursor(GLUT_CURSOR_NONE);
    glutWarpPointer((Window.CurrentWidth / 2), (Window.CurrentHeight / 2));
  } else {
    glutPassiveMotionFunc(NULL);
    glutSetCursor(GLUT_CURSOR_INHERIT);
  }
}

void PassiveMotionFunction(int X, int Y) {
  static bool warped = false;
  int windowCenterX, windowCenterY;
  
  if(!warped) {
    windowCenterX = (Window.CurrentWidth / 2);
    windowCenterY = (Window.CurrentHeight / 2);
    Camera.rotation += (X - windowCenterX);
    Camera.inclination += (Y - windowCenterY);
    UpdateCameraCenter();
    warped = true;
    glutWarpPointer(windowCenterX, windowCenterY);
  } else
    warped = false;
}
