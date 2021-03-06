#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
int xmin=100,xmax=200,ymin=100,out=0,ymax=200,xa,xb,ya,yb,bit1[4],bit2[4],i,flag1=0,flag2=0,o[4],a[4],x,y,in=0;
float m;
void display()
{
	int i=0;
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0);
	glBegin(GL_LINES);
	glColor3f(1,0.6,0);
	glVertex2i(100,0);
	glVertex2i(100,300);
	glColor3f(1,0.6,0);
	glVertex2i(200,0);
	glVertex2i(200,300);
	glColor3f(1,0.6,0);
	glVertex2i(0,100);
	glVertex2i(300,100);
	glColor3f(1,0.6,0);
	glVertex2i(0,200);
	glVertex2i(300,200);
	glEnd();
	glFlush();


	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex2f(xmin,ymin);
	glVertex2f(xmax,ymin);
	glVertex2f(xmax,ymax);
	glVertex2f(xmin,ymax);
	glEnd();
	glFlush();
	glBegin(GL_LINES);
	glColor3f(1,0,1);
	glVertex2i(xa,ya);
	glVertex2i(xb,yb);
	glEnd();
	glFlush();
	sleep(1);
	if(!(out&in))
	{
		for(i=0;i<4;i++)
		{
			bit1[i]=0;
			bit2[i]=0;
		}
		if(xa<xmin)
			bit1[3]=1;
		else if(xa>xmax)
			bit1[2]=1;
		if(ya<ymin)
			bit1[1]=1;
		else if(ya>ymax)
			bit1[0]=1;
		if(xb<xmin)
			bit2[3]=1;
		else if(xb>xmax)
			bit2[2]=1;
		if(yb<ymin)
			bit2[1]=1;
		else if(yb>ymax)
			bit2[0]=1;
		for(i=0;i<4;i++)
		{
			o[i]=bit1[i]|bit2[i];
			a[i]=bit1[i]&bit2[i];
		}
		if(o[0]|o[1]|o[2]|o[3])
			flag1=1;
		else
			in=1;
		if(a[0]|a[1]|a[2]|a[3])
		{
			out=1;
			flag2=1;
		}
		if(in)
			printf("Line inside\n");
		else if(out)
			printf("Outside\n");
		else
		{
			if(xa==xb)
			{
				m=0;
				ya=ymin;
				yb=ymax;
				glBegin(GL_LINE_LOOP);
				glColor3f(0,0,0);
				glVertex2f(xmin,ymin);
				glVertex2f(xmax,ymin);
				glVertex2f(xmax,ymax);
				glVertex2f(xmin,ymax);
				glEnd();
				glFlush();
				glBegin(GL_LINES);
				glColor3f(1,0.9,1);
				glVertex2f(xa,ya);
				glVertex2f(xb,yb);
				glEnd();
				glFlush();
			}
			else
			{
				m=((yb-ya)/(xb-xa));
				x=xa;
				y=ya;
				if(bit1[3]==1)
				{
					x=xmin;
					y=ya+m*(x-xa);
				}
				if(bit1[2]==1)
				{
					x=xmax;
					y=ya+m*(x-xa);
				}
				if(bit1[1]==1)
				{
					y=ymin;
					x=xa+(y-ya)/m;
				}
				if(bit1[0]==1)
				{
					y=ymax;
					x=xa+(y-ya)/m;
				}
				xa=x;
				ya=y;
				x=xb;
				y=yb;
				if(bit2[3]==1)
				{
					x=xmin;
					y=yb+m*(x-xb);
				}
				if(bit2[2]==1)
				{
					x=xmax;
					y=yb+m*(x-xb);
				}
				if(bit2[1]==1)
				{
					y=ymin;
					x=xb+(y-yb)/m;
				}
				if(bit2[0]==1)
				{
					y=ymax;
					x=xb+(y-yb)/m;
				}
				xb=x;
				yb=y;
				glColor3f(0,0,0);
				glBegin(GL_LINE_LOOP);
				glColor3f(0,0,0);
				glVertex2f(xmin,ymin);
				glVertex2f(xmax,ymin);
				glVertex2f(xmax,ymax);
				glVertex2f(xmin,ymax);
				glEnd();
				glFlush();
				glBegin(GL_LINES);
				glColor3f(1.2,0,1);
				glVertex2f(xa,ya);
				glVertex2f(xb,yb);
				glEnd();
				glFlush();
			}
		}
	}
	if(in)
	{
		glBegin(GL_LINES);
		glColor3f(0.2,0.6,1);
		glVertex2f(xa,ya);
		glVertex2f(xb,yb);
		glEnd();
		glFlush();
	}
	
}
int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA |GLUT_DEPTH);
	glutInitWindowSize(300,300);
	glutInitWindowPosition(100,100);
	glutCreateWindow("LINE CLIPPING");
	//glViewport(20,20,200,200);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,300,0,300);   //setting clipping area
	printf("Enter the cordinate end points (xa,ya): ");
	scanf("%d%d",&xa,&ya);
	printf("Enter the cordinate end points (xb,yb): ");
	scanf("%d%d",&xb,&yb);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

