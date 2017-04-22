#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
int x,y,xc,yc,r,p;
void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0);
	x=0;
	y=r;
	p=3-(2*r);

	while(x<=y)
	{
	glBegin(GL_POINTS);
	
	glColor3f(0,0,0);
	//printf("Points : %5.2f and %5.2f\n",x,y);
	glVertex2i(xc+x,yc+y);
	glVertex2i(xc-x,yc+y);
	glVertex2i(xc+x,yc-y);
	glVertex2i(xc-x,yc-y);
	glVertex2i(xc+y,yc+x);
	glVertex2i(xc-y,yc+x);
	glVertex2i(xc+y,yc-x); 
	glVertex2i(xc-y,yc-x);
	glEnd();
	glFlush();
	if(p<0)
	{
		x=x+1;
		p=p+(4*x)+6;
	}
	else
	{
		x=x+1;
		y=y-1;
		p=p+4*(x-y)+10;
	}
}
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA |GLUT_DEPTH);
	glutInitWindowSize(300,300);
	glutInitWindowPosition(100,100);
	glutCreateWindow("BRESENHAMS CIRCLE ALGORITHM");
	glViewport(50,50,350,250);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();00413@user:/mnt/00413/cg/brcircle$ ./brcir 
Enter the radius 20
Enter the centre coordinates 50
50

	gluOrtho2D(0,100,0,100);   //setting clipping area
	printf("Enter the radius ");
	scanf("%d",&r);
	printf("Enter the centre coordinates ");
	scanf("%d%d",&xc,&yc);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
/*
OUTPUT

00413@user:/mnt/00413/cg/brcircle$ ./brcir 
Enter the radius 20
Enter the centre coordinates 50
50
*/

