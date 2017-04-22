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
	glColor3f(1,0.6,0);
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
	printf("MENU\n");
	printf("1.Translation\n2.Scaling\n3.Rotation\n4.Exit\n");
	printf("Enter your choice :");
	scanf("%d",&ch);
	switch(choice)
	{
		case 1:
			printf("Enter the line coordinates (xa,ya,xb,yb) : ");
			scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
			glBegin(GL_LINES);
			glColor3f(0,0,0);
			glVertex2i(xa,ya);
			glVertex2i(xb,yb);
			glEnd();
			glFlush();  
			switch(ch){
				case 1:
					printf("\nEnter the translation distances (tx,ty) : ");
					scanf("%d%d",&tx,&ty);
					glBegin(GL_LINES);
					glColor3f(1,0.3,0.4);
					glVertex2i(xa+tx,ya+ty);
					glVertex2i(xb+tx,yb+ty);
					glEnd();
					glFlush();
					break;
				case 2:
					printf("\nEnter the scaling factors (sx,sy) : ");
					scanf("%d%d",&sx,&sy);
					printf("Enter the fixed point about which scaling is to be done (xf,yf) : ");
					scanf("%d%d",&xf,&yf);
					glBegin(GL_LINES);
					glColor3f(1,0.3,0.4);
					glVertex2i(xf+(xa-xf)*sx,yf+(ya-yf)*sy);
					glVertex2i(xf+(xb-xf)*sx,yf+(yb-yf)*sy);
					glEnd();
					glFlush();
					break;	
				case 3:
					printf("Enter the rotation angle\n");
					scanf("%f",&angle);
					printf("Enter the fixed point about which rotation is to be done (xf,yf) : ");
					scanf("%d%d",&xf,&yf);
					ang=angle*(3.14/180);
					xxa=xf+(xa-xf)*cos(ang)-(ya-yf)*sin(ang);
					yya=yf+(xa-xf)*sin(ang)+(ya-yf)*cos(ang);
					xxb=xf+(xb-xf)*cos(ang)-(yb-yf)*sin(ang);
					yyb=yf+(xb-xf)*sin(ang)+(yb-yf)*cos(ang);
					glBegin(GL_LINES);
					glColor3f(1,0.3,0.4);
					glVertex2f(xxa,yya);
					glVertex2f(xxb,yyb);
					glEnd();
					glFlush();
					break;	
				case 4:	exit(0);
					break;
			}
			break;
		case 2:
			printf("\nEnter the no. of polygon vertices ");
			scanf("%d",&n);
			printf("Enter the polygon vertices : ");
			for(i=0;i<n;i++)
				scanf("%d%d",&x[i],&y[i]);
			glBegin(GL_POLYGON);
			glColor3f(0.1,0,0);
			for(i=0;i<n;i++)
			{
				glVertex2i(x[i],y[i]);
			}
			glEnd();
			glFlush();  
			switch(ch){
				case 1:
					printf("\nEnter the translation distances (tx,ty) : ");
					scanf("%d%d",&tx,&ty);
					glBegin(GL_POLYGON);
					glColor3f(1,0.3,0.4);
					for(i=0;i<n;i++)
					{
					glVertex2i(x[i]+tx,y[i]+ty);
					}
					glEnd();
					glFlush();
					break;
				case 2:printf("\nEnter the scaling factors (sx,sy) : ");
					scanf("%d%d",&sx,&sy);
					printf("Enter the fixed point about which scaling is to be done (xf,yf) : ");
					scanf("%d%d",&xf,&yf);
					glBegin(GL_POLYGON);
					glColor3f(1,0.3,0.4);
					for(i=0;i<n;i++)
						glVertex2i(xf+(x[i]-xf)*sx,yf+(y[i]-yf)*sy);
					glEnd();
					glFlush();
					break;
				case 3:
					printf("Enter the rotation angle\n");
					scanf("%f",&angle);
					printf("Enter the fixed point about which rotation is to be done (xf,yf) : ");
					scanf("%d%d",&xf,&yf);
					ang=angle*(3.14/180);
					glBegin(GL_POLYGON);
					for(i=0;i<n;i++)
					{
						glVertex2i(xf+(x[i]-xf)*cos(ang)-(y[i]-yf)*sin(ang),yf+(x[i]-xf)*sin(ang)+(y[i]-yf)*cos(ang));
					}
					glEnd();
					glFlush();
					break;
				case 4: exit(0);
		
			}
	}
}
	int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA |GLUT_DEPTH);
	glutInitWindowSize(300,300);
	glutInitWindowPosition(100,100);
	glutCreateWindow("2D TRANSFORMATION");
	glViewport(50,50,350,250);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);   
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}