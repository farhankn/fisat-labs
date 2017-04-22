
#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
float x,y,xa,ya,xb,yb,dx,dy,steps,k,xincr,yincr;
void display()
{

	glClearColor(0.5,1.0,1.0,0.5);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5.0);
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

	glColor3f(0,0,0);
	//printf("Points : %5.2f and %5.2f\n",round(x),round(y));
	glVertex2i(round(x),round(y));
	glEnd();
	glFlush();
	for(k=0;k<steps;k++)
	{
		x+=xincr;
		y+=yincr;
		glBegin(GL_POINTS);
	//	printf("Points : %3.2f and %3.2f\n",round(x),round(y));
		glVertex2i(round(x),round(y));
		glEnd();
		glFlush();
	}
}
int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA |GLUT_DEPTH);
	glutInitWindowSize(512,512);
	glutInitWindowPosition(100,100);
	glutCreateWindow("DDA ALGORITHM");
	glViewport(50,50,350,250);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,100,0,100);   //setting clipping area
	printf("Enter points (xa,ya): ");
	scanf("%f%f",&xa,&ya);
	printf("Enter points (xb,yb): ");
	scanf("%f%f",&xb,&yb);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
