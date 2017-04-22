#include<GL/glut.h>
#include"glsupport.h"
int trans_man=0,ty_ball=0,tx_ball=0,f4;
int f=0,angh=0,f1=0,angl1,angl2,f2,f3;
void grnd(){
	setcolor(GREEN);
	glLineStipple(1,0XAAAA);
	glEnable(GL_LINE_STIPPLE);

	glBegin(GL_LINES);
	line(0,20,800,20);
	line(0,19,800,19);
	line(0,21,800,21);
	line(0,22,800,22);
	glEnd();

	glDisable(GL_LINE_STIPPLE);
	

}
void ball(){
	setcolor(YELLOW);
	fillellipse(50,80,8,10);
}
void man(){
	setcolor(RED);
	circle(30,120,10);
	line(30,110,30,45);
}

void rhand(){
	setcolor(RED);
	pieslice(30,95,0,5,20);
}
void lhand(){
	setcolor(RED);
	pieslice(30,95,330,5,20);
}
void rleg(){
	setcolor(RED);
	pieslice(30,50,290,5,30);
}
void lleg(){
	setcolor(RED);
	pieslice(30,50,250,5,30);
}

void post(){
	setcolor(BROWN);
	glRecti(350,20,360,600);
	setcolor(RED);
	ellipse(330,250,0,360,20,10);
	setcolor(LIGHTGRAY);
	line(310,250,317,200);
	line(350,250,342,200);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	if(trans_man>=200){
		
	}
	glPushMatrix();
	glTranslatef(tx_ball,ty_ball,0);
	ball();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(trans_man+30,95,0);
	glRotatef(angh,0,0,1);
	glTranslatef(-30,-95,0);
	rhand();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(trans_man+30,95,0);
	glRotatef(-angh,0,0,1);
	glTranslatef(-30,-95,0);
	lhand();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(trans_man+30,50,0);
	glRotatef(angl1,0,0,1);
	glTranslatef(-30,-50,0);
	rleg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(trans_man+30,50,0);
	glRotatef(angl2,0,0,1);
	glTranslatef(-30,-50,0);
	lleg();	
	glPopMatrix();

	glPushMatrix();
	glTranslatef(trans_man,0,0);
	man();
	glPopMatrix();
	post();
	grnd();
	glFlush();
}
void time_update(){
	
	if(tx_ball>=200){
		if(f4==0){
			tx_ball+=1;
			ty_ball+=5;
			if(ty_ball>=330){
				f4=1;
			}
		}
		if(f4==1){
			ty_ball-=5;
			if(ty_ball<=-50)
				ty_ball=-50;
		}
		
	}
	if(trans_man>=200){
		trans_man=200;
	}
	else{
		trans_man=trans_man+5;
		tx_ball=trans_man;
	
		if(f==0){
			ty_ball-=10;
			if(ty_ball==-60)
				f=1;
		}
		if(f==1){
			ty_ball+=10;
			if(ty_ball==0)
				f=0;
		}	
		if(f1==0){
			angh-=10;
			if(angh==-40)
				f1=1;
		}
		if(f1==1){
			angh+=10;
			if(angh==40)
				f1=0;
		}

		if(f2==0){
			angl1-=10;
			if(angl1==-30)
				f2=1;
		}
		if(f2==1){
			angl1+=10;
			if(angl1==30)
				f2=0;
		}

		if(f3==0){
			angl2+=10;
			if(angl2==30)
				f3=1;
		}
		if(f3==1){
			angl2-=10;
			if(angl2==-30)
				f3=0;
		}
	}
	glutPostRedisplay();
	glutTimerFunc(50,time_update,0);
}



int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Basket Ball");
	glClearColor(0.0,0.0,0.0,0.0);
	glViewport(0,50,0,50);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,400,0 ,500);
	glutDisplayFunc(display);
	
	glutTimerFunc(25,time_update,0);
	glutMainLoop();
	return 0;
}
