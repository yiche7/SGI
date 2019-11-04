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
	glColor3f(0.0, 0.0, 0.3);
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

	glPolygonMode(GL_FRONT, GL_FILL);
	glCallList(t);

	glFlush();
}

void reshape(GLint w, GLint h)
{

}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Estrella de David");
	init();
	std::cout << "running" << std::endl;
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
}