/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <stdlib.h>


using namespace std;
static int slices = 16;
static int stacks = 16;
GLfloat win, r, g, b;
/* GLUT callback Handlers */
struct Point {
	GLint x;
	GLint y;
};
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}



static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,1,0);

  glPushMatrix();
       glTranslated(0,1.2,-6);
//       glRotated(60,1,0,0);
//       glRotated(a,0,0,1);
       glutSolidCube(0.5);
  glPopMatrix();

  glPushMatrix();
       glTranslated(-0.6,1.2,-6);
//       glRotated(60,1,0,0);
//       glRotated(a,0,0,1);
       glutSolidCube(0.5);
  glPopMatrix();

  glPushMatrix();
       glTranslated(-1.2,1.2,-6);
//       glRotated(60,1,0,0);
//       glRotated(a,0,0,1);
       glutSolidCube(0.5);
  glPopMatrix();

  glPushMatrix();
       glTranslated(-1.8,1.2,-6);
//       glRotated(60,1,0,0);
//       glRotated(a,0,0,1);
       glutSolidCube(0.5);
  glPopMatrix();

  glPushMatrix();
       glTranslated(0.6,1.2,-6);
//       glRotated(60,1,0,0);
//       glRotated(a,0,0,1);
       glutSolidCube(0.5);
  glPopMatrix();

  glPushMatrix();
       glTranslated(1.2,1.2,-6);
//       glRotated(60,1,0,0);
//       glRotated(a,0,0,1);
       glutSolidCube(0.5);
  glPopMatrix();

  glPushMatrix();
       glTranslated(1.8,1.2,-6);
//       glRotated(60,1,0,0);
//       glRotated(a,0,0,1);
       glutSolidCube(0.5);
  glPopMatrix();
glColor3d(1,0,0);
  glPushMatrix();
       glTranslated(2.4,1.2,-6);
//       glRotated(60,1,0,0);
//       glRotated(a,0,0,1);
       glutSolidCube(0.5);
  glPopMatrix();





    glutSwapBuffers();
}

void Desenha_Cubo(){
   glColor3f(0.5f, 0.5f, 0.5f);

	/* Desenha um triângulo na cor corrente */
	glBegin(GL_TRIANGLES);
		glVertex2i(300, 200);
		glVertex2i(350, 300);
		glVertex2i(400, 200);
	glEnd();

}
void keyboard(unsigned char key, int x, int y){
    switch(key){
        case '7':
           glutWireCube(1);
            break;

        case 'd':

            break;

        case 'r':

            break;

        case 'R':

            break;
    }
}
static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */
void mainMenuHandler(int choice) {
	Point p = {320, 240};	// draw_pixel
	Point p1 = {10, 100};	// draw_line
	Point p2 = {200, 100};	// --

	Point pC = {320, 240};	// Circle center point
	GLfloat radius = 200;	// Circle radius

	switch(choice) {
		case 1:	// Pixel
			Desenha_Cubo();
			break;


	}
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(940,780);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("MergeSort!!!");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutCreateMenu(mainMenuHandler);
	glutAddMenuEntry("Desenha Cubo", 1);
	glutAddMenuEntry("Line", 2);
	glutAddMenuEntry("Circle", 3);
	glutAddMenuEntry("Ellipse", 4);
	glutAddMenuEntry("Exit", 5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return EXIT_SUCCESS;
}
