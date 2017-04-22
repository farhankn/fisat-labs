#include<GL/glut.h>
#include "glsupport.h"
int transyc=0,f1=0,ht=500,transxc=20,ang=0,transyw1=0,transyw2=0,transxw1=0,transxw2=0,rot_angle_car=0;
void road()
{
	setcolor(15);
	line(0,10,1000,10);
	
	
}
void car()
{
	setcolor(BROWN);
	glRecti(0,30,200,60);
	setcolor(BROWN);
	glRecti(50,60,120,90);
	setcolor(DARKGRAY);
	int front[6]={0,60,50,90,50,60};
	triangle(front);
	setcolor(DARKGRAY);
	int back[6]={120,60,120,90,170,60};
	triangle(back);
}
void hump()
{
	setcolor(DARKGRAY);
	pieslice(450,10,0,180,20);
}

void wheel()
{	setcolor(15);
	pieslice(0,0,0,80,20);
	//setcolor(LIGHTBLUE);
	pieslice(0,0,90,80,20);
	//setcolor(LIGHTCYAN);
	pieslice(0,0,180,80,20);
	//setcolor(LIGHTMAGENTA);
	pieslice(0,0,270,80,20);
}
void time_update()
{

	if(transxw1>=500)
	{
		transxw1=40;
	}
	else
	{
		transxw1=transxw1+2;
		transxw2=transxw1+70;
		transxc=transxw1-30;
		transyw1=40;
		transyw2=40;
		transyc=0;
	}
	if(transxw1>=420 && transxw1<=490)
		{
			transyw1=50;
			transyc=10;
		}
	if(transxw2>=390 && transxw2<=440)
		{
			transyw2=50;
			transyc=10;
		}
	if(rot_angle_car>0)
		rot_angle_car=rot_angle_car-4;
	else
		rot_angle_car=360;
	
	glutPostRedisplay();
	glutTimerFunc(15,time_update,0);
	
}
void display(void)
{	
	

	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(transxc,transyc+10,0);
	car();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(transxw1,transyw1,0);
	glRotatef(rot_angle_car,0.f,0.f,1.f);
	wheel();
	//glTranslatef(-40,-20,0);
	
	glPopMatrix();
	glPushMatrix();
	glTranslatef(transxw1+120,transyw2,0);
	glRotatef(rot_angle_car,0.f,0.f,1.f);
	wheel();
	//glTranslatef(-40,-20,0);
	
	glPopMatrix();
	hump();
	road();
	glEnd();
	glFlush();
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("CAR");
	glClearColor(0.0,0.0,0.0,0.0);
	glViewport(0,0,800,800);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,800,-100,800);
	glutDisplayFunc(display);
	glutTimerFunc(15,time_update,0);
	glutMainLoop();
	return 0;
}
