/********************************************
Program Name:	Animation Template for OpenGL
Author:			CaiyZ (Mr.IroN)
**********************************************/

#include <Windows.h>
#include <GL\glut.h>

#define FPS_PLANNED					40

DWORD time1, time2;

GLvoid glInit() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

GLvoid onReshape(GLint w, GLint h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

GLvoid updateScene() {
	// Update your scene here.
}

GLvoid paintScene() {
	// Paint your scene here.
}

GLvoid onDisplay() {
	DWORD dtime;
	long sleepTime;
	updateScene();
	glClear(GL_COLOR_BUFFER_BIT);
	paintScene();
	glutSwapBuffers();
	time2 = GetTickCount();
	dtime = time2 - time1;
	sleepTime = 1000 / FPS_PLANNED - dtime;
	if (sleepTime < 2) {
		sleepTime = 2;
	}
	Sleep(sleepTime);
	time1 = GetTickCount();
	glutPostRedisplay();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Animation Template");
	glutDisplayFunc(&onDisplay);
	glutReshapeFunc(&onReshape);
	glInit();
	time1 = GetTickCount();
	glutMainLoop();
	return 0;
}