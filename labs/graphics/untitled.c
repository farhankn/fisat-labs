#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
void display()
{	float i=0.0,j=0.0;
	{
		while(i<1.0){
	glClearColor(0.0,0.2,0.2,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glPointSize(20);
	glBegin(GL_POINTS);
	glVertex2f(i,j);

	glEnd();

	glFlush();
		i+=0.0001;
	j+=0.0001;
}
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