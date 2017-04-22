#include<GL/glut.h>
#include "glsupport.h"
int i=168,flag=0;
float ht=-30;
void bucket()
{
	setcolor(YELLOW);
	//line(100,10,150,10);
	//line(90,100,160,100);
	//line(100,10,90,100);
	//line(150,10,160,100);
	glRecti(60,-30,160,80);
	
	
}
void tap()
{
	setcolor(GREEN);
	line(-100,190,50,190);
	line(-100,220,50,220);
	line(50,190,50,220);
	line(50,198,95,198);
	line(50,212,95,212);
	line(95,188,95,222);
	line(95,188,125,188);
	line(95,222,125,222);
	line(125,188,125,222);
	line(105,188,105,168);
	line(115,188,115,168);
	line(105,168,115,168);
	
}
void drop()
{
	setcolor(CYAN);
	for(float i=108;i<114;i=i+0.3)
	{
		long x=glrandom(147L);
		line(i,x+20,i,x+25);
	}
}
void fill()
{
	setcolor(CYAN);
	glRecti(60,-30,160,ht);
	
}
void time_update()
{
	if(ht>=-30 &&ht<80)
	{
	ht=ht+0.5;
	}
	if(ht==79)
	{
		flag=1;
	}
	glutPostRedisplay();
	glutTimerFunc(10,time_update,0);
}
void display(void)
{	
	
	
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	bucket();
	glPopMatrix();
	glPushMatrix();
	tap();
	glPopMatrix();	
	if(flag==0)
	{
	glPushMatrix();
	drop();
	glPopMatrix();
	}

	glPushMatrix();
	fill();
	glPopMatrix();	
	glEnd();
	glFlush();
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Bucket Filling");
	glClearColor(0,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,800,-100,800);
	glutDisplayFunc(display);
	glutTimerFunc(10,time_update,0);
	glutMainLoop();
	return 0;
}
