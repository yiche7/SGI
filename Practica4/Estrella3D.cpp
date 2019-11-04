#include <iostream>
#include <gl\freeglut.h>

#define PI 3.1415

GLuint t;

void init()
{
	t = glGenLists(1);
	glNewList(t, GL_COMPILE);
	float radio1 = 0.7;
	float radio2 = 1.0;
	glBegin(GL_TRIANGLE_STRIP);
	//glColor3f(0.0, 0.0, 0.3);
	for (int i = 0; i < 4; i++) {
		glVertex3f(radio1*cos(i * 2 * PI / 3.0 + PI / 2), radio1*sin(i * 2 * PI / 3.0 + PI / 2), 0);
		glVertex3f(radio2*cos(i * 2 * PI / 3.0 + PI / 2), radio2*sin(i * 2 * PI / 3.0 + PI / 2), 0);
	}
	for (int i = 0; i < 4; i++) {
		glVertex3f(-radio1 * cos(i * 2 * PI / 3.0 + PI / 2), -radio1 * sin(i * 2 * PI / 3.0 + PI / 2), 0);
		glVertex3f(-radio2 * cos(i * 2 * PI / 3.0 + PI / 2), -radio2 * sin(i * 2 * PI / 3.0 + PI / 2), 0);
	}
	glEnd();
	glEndList();
}

void display()
{
	glClearColor(1.0, 1.0, 1.0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 5, 2, 0, 0, 0, 0, 1, 0);

	for (int i = 0; i < 6; i++) {
		glPushMatrix();
		glColor3f((float)1/i, (float)1/ i, 0.3);
		glRotatef(30 * i, 0, 1, 0);
		glCallList(t);
		glPopMatrix();
	}

	glPolygonMode(GL_FRONT, GL_FILL);

	glFlush();
}

void reshape(GLint w, GLint h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float razon = (float)w / h;

	gluPerspective(45, razon, 1, 10);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Estrella 3D");
	init();
	std::cout << "running" << std::endl;
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
}