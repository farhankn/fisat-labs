#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int vxb[100],vyb[100],no,i=0,k,ch,j=0;
int s,xmin=100,xmax=200,ymin=100,ymax=200,out[100],in[100],ra[4],rb[4],flag1=0,flag2=0,o[4],a[40],yya[100],xxa[100],xxb[100],p[100],q[100];
float m,c=1000,x,y,xa=0,xb=0,yb=0,ya=0,xx,xxx,yy,yyy;
void clip(void)
{
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

	glBegin(GL_POLYGON);
	glColor3f(0.4,0.7,0);
	for(i=0;i<no;i++)
	{
		glVertex2i(xxa[i],yya[i]);
	}
	glEnd();
	glFlush();
	//sleep(2);
	c=xb-xa;
	k=0;
	while(k<no)
	{
		xa=xxa[k];
		xb=xxa[k+1];
		ya=yya[k];
		yb=yya[k+1];
		xx=xa;yy=ya;
		xxx=xb;
		yyy=yb;
		if(k==no-1)
		{
			xb=xxa[0];
			yb=yya[0];
		}
		while(!(out[k]|in[k]))
		{
			for(i=0;i<4;i++)
			{
				ra[i]=0;
				rb[i]=0;
			}
			if(xa<xmin)
				ra[3]=1;
			else if(xa>xmax)
				ra[2]=1;
			if(ya<ymin)
				ra[1]=1;
			else if(ya>ymax)
				ra[0]=1;
			if(xb<xmin)
				rb[3]=1;
			else if(xb>xmax)
				rb[2]=1;
			if(yb<ymin)
				rb[1]=1;
			else if(yb>ymax)
				rb[0]=1;
			for(i=0;i<4;i++)
			{
				o[i]=ra[i]|rb[i];
				a[i]=ra[i]&rb[i];
			}
			if(o[0]|o[1]|o[2]|o[3])
				flag1=1;
			else
				in[k]=1;
			if(a[0]|a[1]|a[2]|a[3])
			{
				flag2=1;
				out[k]=1;
			}
			if(in[k])
				printf("point inside\n");
			else if(out[k])
				printf("point outside\n");
			else
			{	m=((float)(yb-ya)/(xb-xa));
			x=xa;y=ya;
			if(ra[3]==1)
			{
				x=xmin;
				if(yy!=yyy)
					y=ya+m*(x-xa);
				else
					y=ya;
			}
			if(ra[2]==1)
			{
				x=xmax;
				if(yy!=yyy)
					y=ya+m*(x-xa);
				else
					y=ya;
			}
			if(ra[1]==1)
			{
				y=ymin;
				if(xx!=xxx)
					x=xa+(y-ya)/m;
				else
					x=xa;
			}
			if(ra[0]==1)
			{
				y=ymax;
				if(xx!=xxx)
					x=xa+(y-ya)/m;
				else
					x=xa;
			}	
			xa=x;ya=y;
			x=xb;y=yb;
			if(rb[3]==1)
			{
				x=xmin;
				if(yy!=yyy)
					y=yb+m*(x-xb);
				else
					y=yb;
			}
			if(rb[2]==1)
			{
				x=xmax;
				if(yy!=yyy)
					y=yb+m*(x-xb);
				else
					y=yb;
			}
			if(rb[1]==1)
			{
				y=ymin;
				if(xx!=xxx)
					x=xb+(y-yb)/m;
				else
					x=xb;
			}
			if(rb[0]==1)
			{
				y=ymax;
				if(xx!=xxx)
					x=xb+(y-yb)/m;
				else
					x=xb;
			}
			xb=x;yb=y;
			}
		}
		if(in[k])
		{
		p[j]=xa;
		q[j]=ya;
		j++;
		p[j]=xb;
		q[j]=yb;
		j++;
		glBegin(GL_LINES);
		glColor3f(0,0.2,0.6);
		glVertex2f(xa,ya);
		glVertex2f(xb,yb);
		glEnd();
		glFlush();
		}
		k++;
		
	}
	glBegin(GL_POLYGON);
	glColor3f(0,0.3,0.6);
	for(i=0;i<j;i++)
	{
		glVertex2i(p[i],q[i]);
	}
	glEnd();
	glFlush();
	
}
void display()
{
	printf("Enter the no. of vertices ");
	scanf("%d",&no);
	printf("Enter the coordinates ");
	for(i=0;i<no;i++)
		scanf("%d%d",&xxa[i],&yya[i]);
	clip();
	
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA |GLUT_DEPTH);
	glutInitWindowSize(300,300);
	glutInitWindowPosition(100,100);
	glutCreateWindow("POLYGON CLIPPING");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,300,0,300);  
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}		
/* OUTPUT


00413@user:/mnt/00413/cg/polygonclip$ ./polygon
Enter the no. of vertices 3
Enter the coordinates 100
170
170
250
250
100
point inside
point inside
point inside
*/

