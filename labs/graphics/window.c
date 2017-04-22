#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
float i=0,j=0.1;
void display()
{	while(i<1.0&&j<1.0)
	{
	glClearColor(i,0.2,0.7,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glutWireTeapot(0.5);
	glColor3f(0.5,0.0,j);
	glutSolidTeapot(0.25);
	glFlush();
	i+=0.001;

	j+=0.0001;
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