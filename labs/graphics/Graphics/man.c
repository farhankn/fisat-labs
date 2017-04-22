#include<GL/glut.h>
#include "glsupport.h"
int planex=500,planey=0,flag=0,mx=0,my=0,start=0,rot_leg=0,rot_ang=0,headflag=0;
int fade=0;

void plane()
{

	setcolor(BLUE);
	glRecti(300,400,450,350);
	pieslice(300,375,90,180,25);
	arc(350,400,90,35,35);
	
	setcolor(CYAN);
	int top[6]= {350,400,350,435,450,400};
	triangle(top);
	int tale1[6]={450,400,480,435,450,380};
	triangle(tale1);
	int tale2[6]={450,400,480,380,450,350};
	triangle(tale2);
}
void head()
{
	
	pieslice(380,400,0,-360,10);
}
void head1()
{
	glPushMatrix();		
	setcolor(BLACK);
	pieslice(380,400,0,-360,10);
	glPopMatrix();
}
void man()
{
	setcolor(RED);
	pieslice(250,320,0,-360,10);
	line(250,320,250,255);
	line(230,340,250,290);
	line(270,340,250,290);
	
}
void leg()
{
	line(247,255,220,225);
	line(247,255,265,225);
}
void parachute()
{
	pieslice(250,340,0,180,30);
	line(230,340,250,290);
	line(270,340,250,290);
}
void man1()
{
	setcolor(RED);
	pieslice(250,320,0,-360,10);
	line(250,320,250,255);
	line(250,290,220,260);
	
	
}
void fadep()
{
	pieslice(200,250,290,180,30);
	line(200,260,220,260);
	line(200,240,220,260);
}
/*void time_update()
{

	if(trans_plane>=-500)
		trans_plane--;
	if(trans_plane<=70)
		if(trans_par_up>0)
			trans_par_up--;
		else
			trans_par_forward++;
	
} */
void display(void)
{	
	

	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(planex,planey,0);
	plane();
	setcolor(RED);
	head();
	glPopMatrix();

	if(flag==1)
	{
		glPushMatrix();
		glTranslatef(mx,my,0);
		man();
		
		glPopMatrix();
	
	}
	if(flag==1)
	{
		glPushMatrix();
		glTranslatef(mx+6,my,0);
		leg();
		glPopMatrix();
	}
	
	if(start==1)
	{
		glPushMatrix();
		glTranslatef(mx,my,0);
		setcolor(RED);
		parachute();
		setcolor(BLACK);
		head();
		setcolor(RED);
		glPopMatrix();
	}
	if(fade==1)
	{
		glPushMatrix();
		glTranslatef(mx,my,0);
		fadep();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(mx+6,my,0);
		glRotatef(rot_leg,0,0,1);
		leg();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(mx,my,0);
		man1();
		glPopMatrix();
	}
	
		
	
		
		
	glEnd();
	glFlush();
}
		
void time_update()
{
	planex--;
	if(planex<=-130 || planey>=300)
	{
		start=1;
		flag=1;

		//headflag=1;
		//setcolor(BLACK);
		//head();
		my--;
	}

	if(my<=-300)
	{
		//headflag=1;
		flag=0;
		fade=1;
		start=0;
		my++;
		mx++;
	}
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
	glutCreateWindow("Man Parachute");
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
