#include <iostream>
#include <gl\freeglut.h>
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
void reshape(GLint w, GLint h)
{
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 400);
	glutCreateWindow("Primer programa en OpenGL");
	std::cout << "Running" << std::endl;
	glClearColor(0.0,0.0,0.3,0.0);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
}