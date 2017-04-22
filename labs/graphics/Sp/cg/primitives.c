#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
float x0,y0,x1,y1,dx,dy,steps,xincr,yincr;
void display(float x0,float y0,float x1,float y1)
{
	int k;
	
	glClearColor(3,.4,.2,1);
	glClear(GL_COLOR_BUFFER_BIT);
	//glBegin(GL_POINTS);
	//glVertex2i(10,20);
	dx=x1-x0;
	dy=y1-y0;
	x=x0;
	y=y0;
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	xincr=dx/steps;
	yincr=dy/steps;
	glVertex2f(ceil(x),ceil(y));
	for(k=0;k<steps;k++)
	{
		x+=xincr;
		y+=yincr;
		glVertex2f(ceil(x),ceil(y));
	}
	

	
	glEnd();
	
	glFlush();
}
int main(int argc,char *argv[])
{
	float a,b,c,d;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowSize(400,300);
	glutInitWindowPosition(500,100);
	glutCreateWindow("My First openGl Window");
	printf("x0:\n");
	scanf("%f",&a);
	printf("y0:\n");
	scanf("%f",&b);
	printf("x1:\n");
	scanf("%f",&c);
	printf("y1:\n");
	scanf("%f",&d);
	glutDisplayFunc(display(a,b,c,d));
	glutMainLoop();
	return 0;
	
}
