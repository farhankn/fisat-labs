#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
float xa,ya,xb,yb,dx,dy,steps,xincr,yincr,x,y;

void display()
{
	
	
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(1.0);
	//glBegin(GL_LINES);
	//glVertex2i(10,20);
	

	int k;
	dx=xb-xa;
	dy=yb-ya;
	x=xa;
	y=ya;
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	xincr=dx/steps;
	yincr=dy/steps;
	glBegin(GL_POINTS);
	glColor3f(1,0,0);
	glVertex2i(round(x),round(y));
	glEnd();
	
	
	for(k=0;k<steps;k++)
	{
		printf("%f %f\n",round(x),round(y));
		x+=xincr;
		y+=yincr;
		glBegin(GL_POINTS);
		glColor3f(1,0,0);
		glVertex2i(round(x),round(y));
		glEnd();
	
		
	}
	

	glFlush();
}

int main(int argc,char *argv[])
{
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowSize(400,300);
	glutInitWindowPosition(500,100);
	glutCreateWindow("DDL");
	glViewport(50,50,350,250);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
	printf("xa:\n");
	scanf("%f",&xa);
	printf("ya:\n");
	scanf("%f",&ya);
	printf("xb:\n");
	scanf("%f",&xb);
	printf("yb:\n");
	scanf("%f",&yb);
	glutDisplayFunc(display);
	
	glutMainLoop();
	return 0;
	
}

