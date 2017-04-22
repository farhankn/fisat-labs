#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<stdio.h>
#include<math.h>
int x[100],y[100],ch,n,i,choice,xa,ya,xb,yb;

void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0);
	glBegin(GL_LINES);
	glColor3f(1,0.6,0);
	glVertex2i(-250,0);
	glVertex2i(250,0);
	glColor3f(1,0.6,0);
	glVertex2i(0,-250);
	glVertex2i(0,250);
	glEnd();
	glFlush();
	printf("Main menu\n");
	printf("1.Line reflections\n2.Polygon reflections\n");
	printf("Enter the choice ");
	scanf("%d",&choice);
	
     
	if(choice==1)
	{
		printf("Enter the line coordinates(xa,ya,xb,yb) : ");
		scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
		glBegin(GL_LINES);
		glColor3f(0.6,0,0);
		glVertex2f(xa,ya);
		glVertex2f(xb,yb);
		glEnd();
		glFlush();
		printf("MENU\n");
	printf("1.Reflection about x-axis\n2.Reflection about y-axis\n3.Reflection about origin\n4.Reflection about diagonal\n5.Reflection about off diagonal\n6.Exit\n");
	printf("Enter your choice ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:	
			glBegin(GL_LINES);
			glColor3f(0,0.7,0);
			glVertex2i(xa,-ya);
			glVertex2i(xb,-yb);
			glEnd();
			glFlush(); 
			break;
		case 2:
			glBegin(GL_LINES);
			glColor3f(0,0.7,0);
			glVertex2i(-xa,ya);
			glVertex2i(-xb,yb);
			glEnd();
			glFlush(); 
			break;
		case 3:
			glBegin(GL_LINES);
			glColor3f(0,0.7,0);
			glVertex2i(-xa,-ya);
			glVertex2i(-xb,-yb);
			glEnd();
			glFlush(); 
			break;
		case 4:
			glBegin(GL_LINES);
			glColor3f(0.6,0,0);
			glVertex2f(-250,-250);
			glVertex2f(250,250);
			glEnd();
			glFlush();
			glBegin(GL_LINES);
			glColor3f(0,0.7,0);
			glVertex2i(ya,xa);
			glVertex2i(yb,xb);
			glEnd();
			glFlush(); 
			break;
		case 5:
			glBegin(GL_LINES);
			glColor3f(0.6,0,0);
			glVertex2f(-250,250);
			glVertex2f(250,-250);
			glEnd();
			glFlush();
			glBegin(GL_LINES);
			glColor3f(0,0.7,0);
			glVertex2i(-ya,-xa);
			glVertex2i(-yb,-xb);
			glEnd();
			glFlush(); 
			break;
		case 6: exit(0);
	
	}			
	}
	else
	{
	


	printf("Enter the no. of vertices of the polygon ");
	scanf("%d",&n);
	printf("Enter the polygon coordinates : ");
	for(i=0;i<n;i++)
		scanf("%d%d",&x[i],&y[i]);
	glBegin(GL_POLYGON);
	glColor3f(0.4,0.7,0);
	for(i=0;i<n;i++)
	{
		glVertex2i(x[i],y[i]);
	}
	glEnd();
	glFlush(); 
	printf("MENU\n");
	printf("1.Reflection about x-axis\n2.Reflection about y-axis\n3.Reflection about origin\n4.Reflection about diagonal\n5.Reflection about off diagonal\n6.Exit\n");
	printf("Enter your choice ");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:	
			glBegin(GL_POLYGON);
			glColor3f(0,0.7,0);
			for(i=0;i<n;i++)
			{
				glVertex2i(x[i],-y[i]);
			}
			glEnd();
			glFlush(); 
			break;
		case 2:
			glBegin(GL_POLYGON);
			glColor3f(0.4,0.7,0);
			for(i=0;i<n;i++)
			{
				glVertex2i(-x[i],y[i]);
			}
			glEnd();
			glFlush(); 
			break;
		case 3:
			glBegin(GL_POLYGON);
			glColor3f(0.4,0.7,0);
			for(i=0;i<n;i++)
			{
				glVertex2i(-x[i],-y[i]);
			}
			glEnd();
			glFlush(); 
			break;
		case 4:
			glBegin(GL_LINES);
			glColor3f(0.6,0,0);
			glVertex2f(-250,-250);
			glVertex2f(250,250);
			glEnd();
			glFlush();
			glBegin(GL_POLYGON);
			glColor3f(0.7,0.9,0);
			for(i=0;i<n;i++)
			{
				glVertex2i(y[i],x[i]);
			}
			glEnd();
			glFlush(); 
			break;
		case 5:
			glBegin(GL_LINES);
			glColor3f(0.6,0,0);
			glVertex2f(-250,250);
			glVertex2f(250,-250);
			glEnd();
			glFlush();
			glBegin(GL_POLYGON);
			glColor3f(0.7,0.9,0);
			for(i=0;i<n;i++)
			{
				glVertex2i(-y[i],-x[i]);
			}
			glEnd();
			glFlush(); 
			break;
	}			
	 }
}





int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA |GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("2D REFLECTION");
	glViewport(50,50,350,250);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-250,250,-250,250);   //setting clipping area
	glutDisplayFunc(display);
	//glutMainLoop();
	return 0;
}
