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

#define WINDOW_TITLE_PREFIX "Template"

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
} Camera = {0.0, 10.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0};

void Initialize(int, char*[]);
void InitWindow(int, char*[]);
void ResizeFunction(int, int);
void RenderFunction(void);
void TimerFunction(int);
void IdleFunction(void);

int main(int argc, char* argv[]) {
  Initialize(argc, argv);

  glutMainLoop();

  exit(EXIT_SUCCESS);
}

void Initialize(int argc, char* argv[]) {
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
