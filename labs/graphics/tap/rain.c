#include<GL/glut.h>
#include "glsupport.h"
int transy=0,f1=0,ht=500,transx=0,transxw1=0,transyw1=0,rot_angle_car=0;
int water=0;
void man()
{
	setcolor(GREEN);
	circle(50,50,5);
	line(50,30,50,45);
	line(50,40,60,50);
	line(50,40,40,40);
	
}

void rain()
{
setcolor(CYAN);
long i;
for(i=0;i<250;i++)
{
long x=glrandom(250L);
line(i,x+15,i-5,x+25);

}
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
 	glPushMatrix();
	rain();
	glPopMatrix();

		man();

		
	glPushMatrix();	
	glPopMatrix();


	glEnd();
	glFlush();
}
void time_update()
{

glutPostRedisplay();
glutTimerFunc(50,time_update,0);
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("man in rain");
	glClearColor(0.0,0.0,0.0,0.0);
	glViewport(0,100,0,100);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,200,0,200);
	glutDisplayFunc(display);
	glutTimerFunc(25,time_update,0);
	glutMainLoop();
	return 0;
}
	
