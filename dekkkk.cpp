#include <gl/Glut.h>
#include <math.h>


struct Point {
	GLint x;
	GLint y;
};

void dda(Point p1, Point p2) {
	GLfloat dx = p2.x - p1.x;
	GLfloat dy = p2.y - p1.y;

	GLfloat x1 = p1.x;
	GLfloat y1 = p1.y;

	GLfloat stp = 0;

	if(abs(dx) > abs(dy)) {
		stp = abs(dx);
	} else {
		stp = abs(dy);
	}

	GLfloat xIn = dx/stp;
	GLfloat yIn = dy/stp;

	for(float i = 1; i <= stp; i++) {
		glVertex2i(x1, y1);
		x1 += xIn;
		y1 += yIn;
	}
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(1.0f);
	gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}


void DrawArm(float xPos, float yPos, float zPos)
{
	float angle = 0.0f;
	float armAngle[2] = {0.0f, 0.0f};
bool fullScreen = false;
	xPos=2.5f;
	yPos=2.5f;
	zPos=2.5f;
   glPushMatrix();

            	gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
                glColor3f(0.0f, 0.0f, 0.0f);
                glTranslatef(xPos, yPos, zPos);


        glPopMatrix();
}
void pendlm(float xPos, float yPos, float zPos)
{
		float angle = 0.0f;
	float armAngle[2] = {0.0f, 0.0f};
bool fullScreen = false;
	  
        static bool arm1 = true;
        static bool arm2 = false;
        
         glMatrixMode(GL_MODELVIEW);

        glPushMatrix();
          if (arm1)
                {
                        armAngle[0] = armAngle[0] + 1.0f;
                }
                else
                {
                        armAngle[0] = armAngle[0] - 1.0f;
                }

                
                if (armAngle[0] >= 15.0f)
                {
                        arm1 = false;
                }
                if (armAngle[0] <= 15.0f)
                {
                        arm1 = true;
                }

				gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
                glTranslatef(0.0f, -0.5f, 0.0f);
                glRotatef(armAngle[0], 1.0f, 0.0f, 0.0f);
                DrawArm(2.5f, 0.0f, -0.5f);

        glPopMatrix();

        glPushMatrix();

                if (arm2)
                {
                        armAngle[1] = armAngle[1] + 1.0f;
                }
                else
                {
                        armAngle[1] = armAngle[1] - 1.0f;
                }

              	gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
                glTranslatef(0.0f, -0.5f, 0.0f);
                glRotatef(armAngle[1], 1.0f, 0.0f, 0.0f);
                DrawArm(-1.5f, 0.0f, -0.5f);

        glPopMatrix();


}
       



void circle(Point pC, GLfloat rad) {
	GLfloat stp = 1/rad;
	GLfloat x, y;

	for(GLfloat theta = 0; theta <= 360; theta += stp) {
		x = pC.x + (rad * cos(theta));
		y = pC.y + (rad * sin(theta));
		glVertex2i(x, y);
	}
}

Point pC = {300, 300};
GLint rad = 100;

GLint hRad = 50;
GLint mRad = 60;
GLint sRad = 70;

double hDeg = 0;
double mDeg = 0;
double sDeg = 0;

void display(void) {
	
	Point pHr, pMin, pSec;

	pHr.y = pC.y + (hRad * sin(hDeg));
	pHr.x = pC.x + (hRad * cos(hDeg));

	pMin.y = pC.y + (mRad * sin(mDeg));
	pMin.x = pC.x + (mRad * cos(mDeg));

	pSec.y = pC.y + (sRad * sin(sDeg));
	pSec.x = pC.x + (sRad * cos(sDeg));

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glColor3f(3.5, 0.0, 4.5);
	circle(pC, rad);
	glColor3f(1.0, 0.0, 0.0);
	dda(pC, pHr);

	glColor3f(0.0, 1.0, 0.0);
	dda(pC, pMin);

	glColor3f(0.2, 0.6, 1.6);
	dda(pC, pSec);
	pendlm(100,100,0);
	glEnd();
	glFlush();

	mDeg -= 0.0003;
	sDeg -= 0.005;
	hDeg -= 0.00007;

}

void Timer(int value) {

	glutTimerFunc(33, Timer, 0);
	glutPostRedisplay();
}


int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(960, 640);
	glutCreateWindow("Clock with pendulum");
	glutDisplayFunc(display);
	init();
	Timer(0);
	DrawArm(100,100,0);
	glutMainLoop();
	
	
	

	return 0;
}












void penLine( float angle){

float M_PI= 22/7;
float an;
float c ;
float s ;
 glBegin(GL_LINES);
glVertex2f( 0.0, -42.0);
if(0<angle && angle<M_PI/2){ // first quad
 c = cos(angle/3+(M_PI/3));
 s = sin(angle/3+(M_PI/3)) ;
 glVertex2f( 0+47*c,-42-47*s);
}
if(-M_PI/2<angle && angle<0)//fourth quad
{an=(0-angle)/3;
c = cos(an+(M_PI/3));
s = sin(an+(M_PI/3)) ;
 glVertex2f( 0+47*c,-42-47*s);
}
if(-M_PI<angle && angle<-M_PI/2){//third quad
an=(0-(M_PI+angle))/3+(M_PI/2)-(M_PI/6);
 c = cos(an+(M_PI/3));
 s = sin(an+(M_PI/3));
 glVertex2f( 0+47*c,-42-47*s);
}// second quad
if(-M_PI*3/2<angle && angle<-M_PI)
{
an=(M_PI+angle)/3+(M_PI/2)-(M_PI/6);
 c = cos(an+(M_PI/3));
 s = sin(an+(M_PI/3)) ;
 glVertex2f( 0+47*c,-42-47*s);
}
glEnd();

  
}




penline();

