#include<GL/glut.h>
#include "glsupport.h"
#include<stdio.h>
int rot_angle_car=0,i;
int rot_angle_plane=0;
int tcar=0,tcary=0;
float wh1y=0,wh2y=0,hump2=0;
void car_body()
{
	setcolor(MAGENTA);
	glRecti(0,10,200,30);
	setcolor(BLUE);
	glRecti(50,30,120,60);
	int front[6]={0,30,50,60,50,30};
	triangle(front);
	int back[6]={120,30,120,60,170,30};
	triangle(back);
}
void car_wheel()
{
	glLineStipple(1,0xAAAA);
	glEnable(GL_LINE_STIPPLE);
	glColor3f(1,0,0);
	pieslice(0,0,0,90,20);
	glColor3f(1,1,0);
	pieslice(0,0,90,80,20);
	glColor3f(0,1,0);
	pieslice(0,0,180,80,20);
	glColor3f(0,1,1);
	pieslice(0,0,270,80,20);
	glDisable(GL_LINE_STIPPLE);
}
void road()
{
	glLineStipple(1,0xAAAA);
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	setcolor(BLACK);
	for(i=0;i<7;i=i+2)
	{
		glVertex2i(-20,-20+i);
		glVertex2i(680,-20+i);
	}
	glEnd();
	glDisable(GL_LINE_STIPPLE);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	road();
	setcolor(BLACK);
	pieslice(350,-14,0,180,25);
	glPushMatrix();
	glTranslatef(tcar-40,tcary,0);
	car_body();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(tcar,wh2y,0.0f);
	glRotatef(rot_angle_car,0.f,0.f,1.f);
	car_wheel();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(tcar+120,wh1y,0.0f);
	glRotatef(rot_angle_car,0.f,0.f,1.f);
	car_wheel();
	glPopMatrix();
	glFlush();
}
void time_update(int value)
{
	if(tcar<590)
	{
		tcar++;
		if(tcar>180 && tcar<260)
		{
			tcary=20;
			wh1y=25;
		}
		else
		{
			wh1y=0;
		}
		if(tcar>300 && tcar<380)
		{
			tcary=20;
			wh2y=25;
		}
		else if(tcar>280)
		{
			tcary=0;
			wh2y=0;
		}
	}
	else
		tcar=0;
	if(rot_angle_car>0)
		rot_angle_car--;
	else
		rot_angle_car=360;
	glutPostRedisplay();
	glutTimerFunc(5,time_update,0);
}
int main(int argc,char *argv[])
{
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
	glutInitWindowSize(300,400);
	glutInitWindowPosition(10,10);
	glutCreateWindow("CAR MOVING");
	glClearColor(1,1,1,1);
	glViewport(0,0,800,800);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,800,-100,800);  
	glMatrixMode(GL_MODELVIEW);
	glutDisplayFunc(display);
	glutTimerFunc(25,time_update,0);
	glutMainLoop();
	return 0;
}

		
