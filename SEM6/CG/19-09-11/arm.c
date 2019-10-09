#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <GL/freeglut.h>

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
} Window = {800, 600, ((double)800 / 600), 0, 0};

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
  double azimuth;
} Camera = {0.0, 10.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 90.0, 0.0};

struct ArmStruct {
  double AngleBottom;
  double AngleMiddle;
  double AngleTop;
} Arm = {90.0, 135.0, 135.0};

bool keyStates[256];

void Initialize(int, char*[]);
void InitWindow(int, char*[]);
void ResizeFunction(int, int);
void RenderFunction(void);
void TimerFunction(int);
void IdleFunction(void);
void KeyDownFunction(unsigned char, int, int);
void KeyUpFunction(unsigned char, int, int);
void KeyOperations(void);

int main(int argc, char* argv[]) {

  Initialize(argc, argv);

  glutMainLoop();

  exit(EXIT_SUCCESS);
}

void Initialize(int argc, char* argv[]) {
  for(int i = 0; i < 256; i++)
    keyStates[i] = false;
  
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

  glutReshapeFunc(ResizeFunction);
  glutDisplayFunc(RenderFunction);
  glutIdleFunc(IdleFunction);
  glutTimerFunc(0, TimerFunction, 0);
  glutKeyboardFunc(KeyDownFunction);
  glutKeyboardUpFunc(KeyUpFunction);
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
  glScalef(1.0, 0.0, 1.0);
  glColor3ub(100, 100, 100);
  glutSolidCube(50.0);
  glPopMatrix();

  glPushMatrix();
  glColor3ub(250, 50, 50);
  glutSolidSphere(5.0, 20, 20);
  glPopMatrix();

  glPushMatrix();
  glScalef(1.0, 10.0, 1.0);
  glTranslatef(0.0, 0.0, 0.0);
  glColor3ub(200, 75, 75);
  glutSolidCube(5.0);
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

void KeyDownFunction(unsigned char Key, int X, int Y) {
  keyStates[Key] = true;
}

void KeyUpFunction(unsigned char Key, int X, int Y) {
  keyStates[Key] = false;
}

void KeyOperations(void) {
  if(keyStates['w']) {
    Camera.eyeX = Camera.centerX;
    Camera.eyeY = Camera.centerY;
    Camera.eyeZ = Camera.centerZ;
    Camera.centerX =
      sin(DEG_TO_RAD * Camera.inclination) * cos(DEG_TO_RAD * Camera.azimuth) + Camera.eyeX;
    Camera.centerY =
      sin(DEG_TO_RAD * Camera.inclination) * sin(DEG_TO_RAD * Camera.azimuth) + Camera.eyeY;
    Camera.centerZ =
      cos(DEG_TO_RAD * Camera.inclination) + Camera.eyeZ;
  }
  // if(keyStates['s']) {
  //   Camera.eyeX = Camera.centerX - 2;
  // }
}