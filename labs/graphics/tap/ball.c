#include<GL/glut.h>
#include "glsupport.h"
int transy=0,f1=0,ht=500,transx=0,transxw1=0,transyw1=0,rot_angle_car=0;
int water=0;
void bucket()
{
	setcolor(GREEN);

	glRecti(0,80,125,85);
	glRecti(117,73,125,80);
	glRecti(119,85,120,87);
	glRecti(115,87,124,94);

}
void tap()
{
	setcolor(BROWN);
	glRecti(115,0,160,50);
	glRecti(180,60,190,10);
//glRecti(115,0,160,50);
//glRecti(115,0,160,50);
}
void water1()
{
setcolor(CYAN);
glRecti(115,0,160,water);
}
void drop()
{
setcolor(CYAN);
long i;
for(i=119;i<124;i++)
{
long x=glrandom(50L);
line(i,x+18,i,x+25);
}
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	bucket();
	tap();
	
	glPushMatrix();
	drop();
	glPopMatrix();


		
	glPushMatrix();
	water1();
	glPopMatrix();


	glEnd();
	glFlush();
}
void time_update()
{
if(water<50)
{
water++;
}
if(water>=50)
{
water=0;
}
glutPostRedisplay();
glutTimerFunc(50,time_update,0);
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Water filling the bucket from tap");
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
	
