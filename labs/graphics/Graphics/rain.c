#include<GL/glut.h>
#include "glsupport.h"
int planex=-100,planey=0,flag=0,mx=-100,my=-100,start=0,rot_leg=0,rot_ang=0,headflag=0,fade=0,flag1=0,flag2=0;
void rain()
{
	setcolor(CYAN);
	for(float i=-100;i<1500;i=i+0.3)
	{
		long x=glrandom(800L);
		line(i,x+20,i,x+25);
	}
}
void man()
{
	setcolor(RED);
	pieslice(250,320,0,-360,10);
	line(250,320,250,255);
	line(250,290,220,260);
	line(300,310,250,290);
	
}
void man1()
{
	setcolor(RED);
	pieslice(250,320,0,-360,10);
	line(250,320,250,255);
	line(250,290,220,260);	
	setcolor(BROWN);
	pieslice(223,270,210,50,60);
	
}
void umbrella()
{
	setcolor(BROWN);
	line(300,300,300,350);
	pieslice(300,350,360,180,70);
	
	
}
void leg()
{
	setcolor(RED);
	line(247,255,220,225);
	line(247,255,265,225);
}
void display()
{
		glClear(GL_COLOR_BUFFER_BIT);
		if(flag1==1)
		{
		glPushMatrix();
		rain();
		glPopMatrix();
		}
		/*glPushMatrix();
		glTranslatef(mx+6,my,0);
		leg();
		glPopMatrix(); */
		glPushMatrix();
		glTranslatef(mx+6,my,0);
		glRotatef(rot_leg,0,0,1);
		leg();
		glPopMatrix();
		glPushMatrix();
		if(flag1==0)
		{
		glTranslatef(mx,my,0);
		man1();
		glPopMatrix();
		}
		else
		{
		glPushMatrix();
		glTranslatef(mx,my,0);
		man();
		glPopMatrix();
		}
		if(flag1==1)
		{
		glPushMatrix();
		glTranslatef(mx,my,0);
		umbrella();
		glPopMatrix();	
		}
		glEnd();
		glFlush();
}
void time_update()
{
	
	mx++;
	
	if(mx>=20)
		flag1=1;
	if(mx>=400)
		flag1=0;
	if(rot_ang>0)
		rot_ang--;
	else
		rot_ang=360;
	if(rot_leg>0)
		rot_leg=rot_leg-0.5;
	else
	{
		rot_leg=1;
	}
	glutPostRedisplay();
	glutTimerFunc(10,time_update,0);
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Rain");
	glClearColor(0.0,0.0,0.0,0.0);
	//glViewport(0,0,800,800);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,800,-100,800);
	glutDisplayFunc(display);
	glutTimerFunc(10,time_update,0);
	glutMainLoop();
	return 0;
}
