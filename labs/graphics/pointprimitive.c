#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
void display()
{	
	{
	glClearColor(0.0,0.2,0.2,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glPointSize(20);
	glBegin(GL_POINTS);
	glVertex2f(0.050,0.050);
	glVertex2f(0.050,0.100);
	glVertex2f(0.050,0.150);
	glVertex2f(0.050,0.200);
	glVertex2f(0.050,0.250);
	glVertex2f(0.050,0.300);
	glVertex2f(0.050,0.350);
	glVertex2f(0.050,0.400);	
	glVertex2f(0.050,0.450);
	glVertex2f(0.050,0.500);
	glVertex2f(0.100,0.500);
	glVertex2f(0.150,0.500);
	glVertex2f(0.200,0.500);
	glVertex2f(0.250,0.500);
	glVertex2f(0.300,0.500);
	glVertex2f(0.050,0.250);
	glVertex2f(0.100,0.250);
	glVertex2f(0.150,0.250);
	glEnd();
	

	glFlush();
	}
}
int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE |GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowSize(512,512);
	glutCreateWindow("My First Window");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}