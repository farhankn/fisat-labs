#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<stdio.h>
#include<math.h>
int xa,xb,ya,yb,tx,ty,sx,sy,xf,yf,choice,ch,xxa,xxb,yya,yyb,n,x[100],y[100],i,j;
float angle,ang;
void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0);
	glBegin(GL_LINES);
	glColor3f(1,1,0);
	glVertex2i(-100,0);
	glVertex2i(100,0);
	glColor3f(1,1,0);
	glVertex2i(0,-100);
	glVertex2i(0,100);
	glEnd();
	glFlush();
	printf("MENU\n");
	printf("1.Line Transformation\n2.Polygon Transformation\n3.Exit\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	printf("\nMenu");
	printf("\nLine Transformation \nScaling \nRotiation");

