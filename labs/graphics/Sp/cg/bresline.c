#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
int xa,ya,xb,yb,dx,dy,x,y,p;


void display()
{
	
	
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0);
	dx=xb-xa;
	dy=yb-ya;
	p = 2 * dy - dx;

	x=xa;
	y=ya;
	printf("%d  %d\n",x,y);
	glBegin(GL_POINTS);
	glColor3f(1,0,0);
	glVertex2i(x,y);
	glEnd();
	 while(x < xb)
	      {
		    x = x + 1;
		    if(p < 0)
		    {
		          p = p + 2 * dy;
		    }
		    else
		    {
		          y = y + 1;
		          p = p + 2 * (dy - dx);
		    }
		   printf("%d  %d\n",x,y);
		   glBegin(GL_POINTS);
		   glColor3f(1,0,0);
		   glVertex2i(x,y);
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
	glutCreateWindow("Bresenhams Line");
	glViewport(50,50,350,250);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,100,0,100);
	printf("xa:\n");
	scanf("%d",&xa);
	printf("ya:\n");
	scanf("%d",&ya);
	printf("xb:\n");
	scanf("%d",&xb);
	printf("yb:\n");
	scanf("%d",&yb);
	glutDisplayFunc(display);
	
	glutMainLoop();
	return 0;
	
}

