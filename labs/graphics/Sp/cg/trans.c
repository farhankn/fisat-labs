#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>


int n,xa,xb,ya,yb,sx,sy,tx,ty,xf,yf,ch,choice,xp[50],yp[50],xa1,ya1,xb1,yb1,x,y,i;
float a;
void display()
{

glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);



glBegin(GL_LINES);
glColor3f(0,0,0);
glVertex2f(-100,0);
glVertex2f(100,0);
glVertex2f(0,100);
glVertex2f(0,-100);
glEnd();
glFlush();

if(choice==1)
{
	if(ch==1)
	{
		glBegin(GL_LINES);
		glColor3f(0,0,0);
		glVertex2f(xa,ya);
		glVertex2f(xb,yb);
		glEnd();
		glFlush();
		glBegin(GL_LINES);
		glColor3f(1,0,0);
		glVertex2f(xa+tx,ya+ty);
		glVertex2f(xb+tx,yb+ty);
		glEnd();
		glFlush();

	}

	if(ch==2)

	{	
		glBegin(GL_LINES);
		glColor3f(0,0,0);
		glVertex2f(xa,ya);
		glVertex2f(xb,yb);
		glEnd();
		glFlush();
		glBegin(GL_LINES);
		glColor3f(1,0,0);
		glVertex2f(xf+(xa-xf)*sx,yf+(ya-yf)*sy);
		glVertex2f(xf+(xb-xf)*sx,yf+(yb-yf)*sy);
		glEnd();
		glFlush();
	}
	
	if(ch==3)

	{	
		glBegin(GL_LINES);
		glColor3f(0,0,0);
		glVertex2f(xa,yb);
		glVertex2f(xb,yb);
		glEnd();
		glFlush();
		xa1=x+(((xa-x)*(cos(a))+((ya-y)*sin(a))));
		ya1=y+(((xa-x)*(sin(a))+((ya-y)*cos(a))));
		xb1=x+(((xb-x)*(cos(a))+((yb-y)*sin(a))));
		yb1=y+(((xb-x)*(sin(a))+((yb-y)*cos(a))));
		glBegin(GL_LINES);
		glColor3f(0,0,0);
		glVertex2f(xa1,ya1);
		glVertex2f(xb1,yb1);
		glEnd();
		glFlush();
	}
	}
		
if(choice==2)
	{
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	for(i=0;i<n;i++)
	{
		glVertex2f(xp[i],yp[i]);
	}
	glEnd();
	glFlush();
	if(ch==1)
	{
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	for(i=0;i<n;i++)
		{
		glVertex2f(xp[i]+tx,yp[i]+ty);
		}
	glEnd();
	glFlush();
	}

	if(ch==2)
	{
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	for(i=0;i<n;i++)
		{
		glVertex2f(xf+(xp[i]-xf)*sx,yf+(yp[i]-yf)*sy);
		}
	glEnd();
	glFlush();
	}

	if(ch==3)
	{
	
	
		glBegin(GL_POLYGON);
		glColor3f(1,0,0);
		for(i=0;i<n;i++)
		{
		xa1=x+(((xp[i]-x)*(cos(a))+((yp[i]-y)*sin(a))));
		ya1=y+(((xp[i]-x)*(sin(a))+((yp[i]-y)*cos(a))));
		
		glVertex3f(xa1,ya1,0);
		}
		glEnd();
		glFlush();	
	}
    }
}


int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowSize(512,512);
	glutCreateWindow("2D trans ");
	glViewport(50,500,350,250);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
	printf("\n 1. Line Transformations");
	printf("\n 2. Polygon Transformations");
	printf("\n 3. Exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		printf("Menu\n");
		printf("\n 1. Translation");
		printf("\n 2. Scaling");
		printf("\n 3. Rotation");
		printf("\n 4. Exit\n");
		printf("Enter your choice\n");
	scanf("%d",&ch);
	if(ch!= 4)
	{
		printf("Enter the first co-ordinate\n");
		scanf("%d%d",&xa,&ya);
		printf("Enter the second co-ordinate\n");
		scanf("%d%d",&xb,&yb);
	}
	
	switch(ch)
	{
		case 1:
			printf("Enter the translation vectors\n");
			scanf("%d%d",&tx,&ty);
			break;
		
		case 2:
			printf("Enter the scaling vectors\n");
			scanf("%d%d",&sx,&sy);
			printf("Enter the fixed point\n");
			scanf("%d%d",&xf,&yf);			
			break;
		
		case 3:
			
			printf("Enter the Rotation angle reference point\n");
			scanf("%f%d%d",&a,&x,&y);
			a=a*(3.14/180);				
			break;
		
		case 4:
			exit(0);
			
		default:
			printf("Wrong choice\n");
	}
	
	break;

	case 2:
		printf("Menu\n");
		printf("\n 1. Translation");
		printf("\n 2. Scaling");
		printf("\n 3. Rotation");
		printf("\n 4. Exit");
		printf("Enter your choice\n");
	scanf("%d",&ch);
	if(ch!= 4)
	{
		printf("Enter the number of co-ordinates\n");
		scanf("%d",&n);
		printf("Enter the co-ordinates\n");
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&xp[i],&yp[i]);
		}
	}

	switch(ch)
	{
		case 1:
			printf("Enter the translation vectors\n");
			scanf("%d%d",&tx,&ty);
			break;
		
		case 2:
			printf("Enter the scaling vectors\n");
			scanf("%d%d",&sx,&sy);
			printf("Enter the fixed point\n");
			scanf("%d%d",&xf,&yf);			
			break;
		
		case 3:
			
			printf("Enter the reference point\n");
			scanf("%f%d%d",&a,&x,&y);
			a=a*(3.14/180);				
			break;
		
		case 4:
			exit(0);
			
		default:
			printf("Wrong choice");
	}
		
	break;
	case 3: exit(0);

	default:
		printf("Wrong choice");		
	}
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}
	
