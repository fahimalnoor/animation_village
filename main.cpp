#include <windows.h>  // for MS Windows
#include <GL/gl.h>
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>
#include<cstdio>
#define PI           3.14159265358979323846

GLfloat i = 0.0f;
GLfloat j = 0.0f;

GLfloat position = 0.0f;
GLfloat speed = 0.1f;

GLfloat position2 = 0.0f;
GLfloat speed2 = 0.1f;

void dis();
void display();


void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   gluOrtho2D(-4,4,-4,4);
}



void Idle()
{
    glutPostRedisplay(); // marks the current window as needing to be redisplayed
}

GLfloat Rainposition = 0.0f;
GLfloat RainSpeed = 0.3f;

void Rain(int value) {

    if(Rainposition <0.0)
        Rainposition = 1.0f;

    Rainposition -= RainSpeed;

	glutPostRedisplay();


	glutTimerFunc(100, Rain, 0);
}


void update(int value) {

    if(position <-6.5)
        position = 6.5f;

    position = position - speed;

	glutPostRedisplay();

	glutTimerFunc(100, update, 0.0);
}

void update2(int value) {

    if(position2 > 12)
        position2 = -12;

    position2 += speed2;

	glutPostRedisplay();

	glutTimerFunc(100, update2, 0);
}


void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //black
    glClear(GL_COLOR_BUFFER_BIT);

     glBegin(GL_QUADS);
    glColor3ub(102, 204, 0);//base
    glVertex2f(-4.0f,2.0f);
    glVertex2f(-4.0f,-1.2f);
    glVertex2f(4.0f,-1.0f);
    glVertex2f(4.0f,2.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 153, 255);//sky
    glVertex2f(-4.0f,2.0f);
    glVertex2f(-4.0f,4.0f);
    glVertex2f(4.0f,4.0f);
    glVertex2f(4.0f,2.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 102, 204);//river
    glVertex2f(-4.0f,-4.0f);
    glVertex2f(4.0f,-4.0f);
    glVertex2f(4.0f,-1.0f);
    glVertex2f(-4.0f,-1.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 26, 0);//road
    glVertex2f(4.0f,-1.0f);
    glVertex2f(-4.0f,-1.2f);
    glVertex2f(-4.0f,-0.8f);
    glVertex2f(4.0f,-0.6f);
    glEnd();

    //sun
	GLfloat x=3.0f; GLfloat y=3.0f; GLfloat radius =.3f;
	int triangleAmount = 20; //# of triangles used to draw circle

    GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(227, 39, 39);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


    //still clouds

    //cloud1
    x=-0.8f; y=3.6f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 1.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-0.6f; y=3.6f;radius =.17f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 1.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


	x=-0.4f; y=3.6f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 1.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//cloud3
	x=-2.8f; y=3.2f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 3.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=-2.6f; y=3.2f;radius =.17f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 3.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=-2.4f; y=3.2f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 3.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//cloud4
	x=-1.9f; y=3.5f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 4.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=-1.6f; y=3.5f;radius =.25f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 4.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=-1.3f; y=3.5f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 4.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//cloud5
	x=-4.9f; y=2.7f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 5.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-4.6f; y=2.7f;radius =.25f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 5.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-4.3f; y=2.7f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 5.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//cloud6
	x=-6.8f; y=3.2f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 6.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=-6.6f; y=3.2f;radius =.17f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 6.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-6.4f; y=3.2f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 6.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//cloud7
	x=-5.9f; y=3.5f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 7.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-5.6f; y=3.5f;radius =.25f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 7.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-5.3f; y=3.5f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 7.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


	//cloud9
	x=1.6f; y=3.2f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 9.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=1.4f; y=3.2f;radius =.17f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 9.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=1.2f; y=3.2f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 9.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//cloud10
	x=0.9f; y=2.7f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 10.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=0.6f; y=2.7f;radius =.25f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 10.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=0.3f; y=2.7f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 10.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    //running clouds

    //cloud2
    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
	x=-1.8f; y=2.7f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 2.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-1.6f; y=2.7f;radius =.17f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 2.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-1.4f; y=2.7f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 2.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//cloud8
	x=2.9f; y=3.2f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 8.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=2.6f; y=3.2f;radius =.25f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 8.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=2.3f; y=3.2f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 8.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glPopMatrix();


	//birds
	glPushMatrix();
	glTranslatef(position,0.0f, 0.0f);
	//bird-1
	glLineWidth(3.0);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); // Black color
	glVertex2f(-2.5f, 2.7f);    // x, y
	glVertex2f(-2.45f, 2.6f);    // x, y
    glVertex2f(-2.45f, 2.6f);    // x, y
	glVertex2f(-2.4f, 2.7f);    // x, y
	glEnd();
	//bird2
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); // Black color
	glVertex2f(-2.7f, 2.7f);    // x, y
	glVertex2f(-2.65f, 2.6f);    // x, y
    glVertex2f(-2.65f, 2.6f);    // x, y
	glVertex2f(-2.6f, 2.7f);    // x, y
	glEnd();
    //bird3
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); // Black color
	glVertex2f(-2.3f, 2.7f);    // x, y
	glVertex2f(-2.25f, 2.6f);    // x, y
    glVertex2f(-2.25f, 2.6f);    // x, y
	glVertex2f(-2.2f, 2.7f);    // x, y
	glEnd();
    //bird4
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); // Black color
	glVertex2f(-2.4f, 2.9f);    // x, y
	glVertex2f(-2.35f, 2.8f);    // x, y
    glVertex2f(-2.35f, 2.8f);    // x, y
	glVertex2f(-2.3f, 2.9f);    // x, y
	glEnd();
	//bird-5
	glLineWidth(3.0);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); // Black color
	glVertex2f(-2.6f, 2.9f);    // x, y
	glVertex2f(-2.55f, 2.8f);    // x, y
    glVertex2f(-2.55f, 2.8f);    // x, y
	glVertex2f(-2.5f, 2.9f);    // x, y
	glEnd();
    //bird6
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); // Black color
	glVertex2f(-2.8f, 2.9f);    // x, y
	glVertex2f(-2.75f, 2.8f);    // x, y
    glVertex2f(-2.75f, 2.8f);    // x, y
	glVertex2f(-2.7f, 2.9f);    // x, y
	glEnd();
    //bird7
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); // Black color
	glVertex2f(-2.7f, 3.1f);    // x, y
	glVertex2f(-2.65f, 3.0f);    // x, y
    glVertex2f(-2.65f, 3.0f);    // x, y
	glVertex2f(-2.6f, 3.1f);    // x, y
	glEnd();
    //bird8
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); // Black color
	glVertex2f(-2.5f, 3.1f);    // x, y
	glVertex2f(-2.45f, 3.0f);    // x, y
    glVertex2f(-2.45f, 3.0f);    // x, y
	glVertex2f(-2.4f, 3.1f);    // x, y
	glEnd();

    glPopMatrix();


    //back hills
    glBegin(GL_TRIANGLES);

    glColor3ub(45, 134, 45);//hill-1
    glVertex2f(-4.0f,2.0f);
    glVertex2f(-3.0f,2.0f);
    glVertex2f(-3.5f,2.5f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(45, 134, 45);//hill-2
    glVertex2f(-2.0f,2.0f);
    glVertex2f(-3.0f,2.0f);
    glVertex2f(-2.5f,2.2f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(45, 134, 45);//hill-3
    glVertex2f(-2.0f,2.0f);
    glVertex2f(0.0f,2.0f);
    glVertex2f(-1.0f,2.6f);
    glEnd();


    glBegin(GL_TRIANGLES);

    glColor3ub(45, 134, 45);//hill-4
    glVertex2f(1.0f,2.0f);
    glVertex2f(0.0f,2.0f);
    glVertex2f(0.5f,2.3f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(45, 134, 45);//hill-5
    glVertex2f(1.0f,2.0f);
    glVertex2f(1.5f,2.0f);
    glVertex2f(1.25f,2.2f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(45, 134, 45);//hill-6
    glVertex2f(3.0f,2.0f);
    glVertex2f(1.5f,2.0f);
    glVertex2f(2.0f,2.5f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(45, 134, 45);//hill-7
    glVertex2f(3.0f,2.0f);
    glVertex2f(4.0f,2.0f);
    glVertex2f(3.5f,2.5f);
    glEnd();



    //houses

    glBegin(GL_QUADS);
    glColor3ub(255, 128, 0);//house
    glVertex2f(-3.4f,-0.1f);
    glVertex2f(-1.6f,-0.1f);
    glVertex2f(-1.6f,1.0f);
    glVertex2f(-3.4f,1.0f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(153, 31, 0);//left window
    glVertex2f(-3.4f,0.9f);
    glVertex2f(-3.4f,0.6f);
    glVertex2f(-3.1f,0.6f);
    glVertex2f(-3.1f,0.9f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(153, 31, 0);//right window
    glVertex2f(-1.6f,0.9f);
    glVertex2f(-1.6f,0.6f);
    glVertex2f(-1.9f,0.6f);
    glVertex2f(-1.9f,0.9f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 31, 0);//Door
    glVertex2f(-2.6f,-0.1f);//bottom left
    glVertex2f(-2.3f,-0.1f);//bottom right
    glVertex2f(-2.3f,0.2f);//top right
    glVertex2f(-2.6f,0.2f);//top left
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 0, 0);//2nd house
    glVertex2f(-1.6f,0.2f);//bottom left
    glVertex2f(-0.4f,0.2f);//bottom right
    glVertex2f(-0.4f,1.3f);//top right
    glVertex2f(-1.6f,1.3f);//top left
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 77, 51);// 1st house top
    glVertex2f(-3.7f,1.0f);
    glVertex2f(-1.3f,1.0f);
    glVertex2f(-2.0f,1.5f);
    glVertex2f(-3.0f,1.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 255);//2nd home left window
    glVertex2f(-1.6f,1.0f);//bottom left
    glVertex2f(-1.6f,0.6f);//bottom right
    glVertex2f(-1.3f,0.6f);//top right
    glVertex2f(-1.3f,1.0f);//top left
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 255);//2nd home right window
    glVertex2f(-0.4,1.0f);//bottom left
    glVertex2f(-0.4f,0.6f);//bottom right
    glVertex2f(-0.7f,0.6f);//top right
    glVertex2f(-0.7f,1.0f);//top left
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 255);//2nd home door
    glVertex2f(-1.2f,0.2f);//bottom left
    glVertex2f(-0.8f,0.2f);//bottom right
    glVertex2f(-0.8f,0.5);//top right
    glVertex2f(-1.2f,0.5f);//top left
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(204, 51, 153);//2nd home top
    glVertex2f(-0.4f,1.3f);
    glVertex2f(-1.6f,1.3f);
    glVertex2f(-1.0f,1.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);//Tree 1 base
    glVertex2f(0.3f,1.0f);//bottom left
    glVertex2f(0.6f,1.0f);//bottom right
    glVertex2f(0.6f,0.0f);//top right
    glVertex2f(0.3f,0.0f);//top left
    glEnd();

     glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);//tree 1  leaf
    glVertex2f(0.0f,0.8f);
    glVertex2f(0.9f,0.8f);
    glVertex2f(0.45f,1.8f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);//tree 1 top leaf
    glVertex2f(0.1f,1.3f);
    glVertex2f(0.8f,1.3f);
    glVertex2f(0.45f,2.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 102, 0);//3rd house base
    glVertex2f(2.0f,1.5f);
    glVertex2f(2.0f,0.8f);
    glVertex2f(2.8f,0.8f);
    glVertex2f(2.8f,1.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 0, 0);//3rd house top
    glVertex2f(1.7f,1.5f);
    glVertex2f(2.0f,1.8f);
    glVertex2f(2.8f,1.8f);
    glVertex2f(3.1f,1.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);//3rd house left window
    glVertex2f(2.0f,1.3f);
    glVertex2f(2.0f,1.1f);
    glVertex2f(2.2f,1.1f);
    glVertex2f(2.2f,1.3f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0,0,0);//3rd house right window
    glVertex2f(2.8f,1.3f);
    glVertex2f(2.8f,1.1f);
    glVertex2f(2.6f,1.1f);
    glVertex2f(2.6f,1.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);//3rd house door
    glVertex2f(2.3f,0.8f);
    glVertex2f(2.3f,1.0f);
    glVertex2f(2.5f,1.0f);
    glVertex2f(2.5f,0.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 102, 0);//3rd house door
    glVertex2f(1.1f,0.2f);
    glVertex2f(1.2f,1.5f);
    glVertex2f(1.3f,1.5f);
    glVertex2f(1.4f,0.2f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);//tree 2 leaf
    glVertex2f(0.8f,1.2f);
    glVertex2f(1.7f,1.2f);
    glVertex2f(1.3f,2.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 102, 0);//2nd home door
    glVertex2f(3.3f,0.3f);//bottom left
    glVertex2f(3.4f,1.2f);//bottom right
    glVertex2f(3.5f,1.2f);//top right
    glVertex2f(3.6f,0.3f);//top left
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);//tree 1 top leaf
    glVertex2f(3.0f,0.7f);
    glVertex2f(3.9f,0.7f);
    glVertex2f(3.45f,1.5f);
    glEnd();


    //windmill building
    glBegin(GL_QUADS);

    glColor3ub(72,61,139);
    glVertex2f(-0.2f, -1.0f);
    glVertex2f(0.2f, -1.0f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glEnd();

    glPushMatrix();
    glRotatef(j,0,0.0,0.1);//i=how many degree you want to rotate around an axis

    //windmill 4 fans
    glBegin(GL_TRIANGLES);

    glColor3ub(139,69,19);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.4f, -0.1f);
    glVertex2f(0.4f, 0.1f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(139,69,19);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.1f, 0.4f);
    glVertex2f(-0.1f, 0.4f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(139,69,19);
    glVertex2f(0.0f, 0.0f);
    glVertex2f( -0.4f, 0.1f);
    glVertex2f( -0.4f, -0.1f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(139,69,19);
    glVertex2f(0.0f, 0.0f);
    glVertex2f( -0.1f, -0.4f);
    glVertex2f( 0.1f, -0.4f);
    glEnd();

    glPopMatrix();

    j = j - 0.1f; //clock wise rotate

    int j;
    x=0.0f; y=0.0f; radius =.07f;
	triangleAmount = 20; //# of triangles used to draw circle


	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

    //fan circle
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(245,255,250);
		glVertex2f(x, y); // First Ray
		for(j = 0; j <= triangleAmount;j++) {
			glVertex2f(
		            x + (radius * cos(j *  twicePi / triangleAmount)),
			    y + (radius * sin(j * twicePi / triangleAmount))
			);
		}

    glEnd();


    //boats
    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);//Boat
    glVertex2f(-3.0f,-1.5f);//bottom left
    glVertex2f(-1.0f,-1.5f);//bottom right
    glVertex2f(-1.4f,-1.8f);//top right
    glVertex2f(-2.6f,-1.8f);//top left
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 102, 0);//Boat top
    glVertex2f(-2.6f,-1.5f);//bottom left
    glVertex2f(-2.3f,-1.2f);//bottom right
    glVertex2f(-1.7f,-1.2f);//top right
    glVertex2f(-1.4f,-1.5f);//top left
    glEnd();
    glPopMatrix();

    //boat2
    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);
    glScalef(1.0f,1.0f,0.0f);

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);//Boat 2
    glVertex2f(0.5f,-2.8f);//bottom left
    glVertex2f(0.0f,-2.5f);//bottom right
    glVertex2f(2.5f,-2.5f);//top right
    glVertex2f(2.0f,-2.8f);//top left
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 102, 0);//Boat top 2
    glVertex2f(0.5f,-2.5f);//bottom left
    glVertex2f(0.8f,-2.2f);//bottom right
    glVertex2f(2.0f,-2.2f);//top right
    glVertex2f(2.0f,-2.5f);//top left
    glEnd();

    glLoadIdentity();
    glPopMatrix();



    glFlush();
}

void display2() {

    glBegin(GL_QUADS);
    glColor3ub(102, 204, 0);//base
    glVertex2f(-4.0f,2.0f);
    glVertex2f(-4.0f,-1.2f);
    glVertex2f(4.0f,-1.0f);
    glVertex2f(4.0f,2.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 153, 255);//sky
    glVertex2f(-4.0f,2.0f);
    glVertex2f(-4.0f,4.0f);
    glVertex2f(4.0f,4.0f);
    glVertex2f(4.0f,2.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 102, 204);//river
    glVertex2f(-4.0f,-4.0f);
    glVertex2f(4.0f,-4.0f);
    glVertex2f(4.0f,-1.0f);
    glVertex2f(-4.0f,-1.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 26, 0);//road
    glVertex2f(4.0f,-1.0f);
    glVertex2f(-4.0f,-1.2f);
    glVertex2f(-4.0f,-0.8f);
    glVertex2f(4.0f,-0.6f);
    glEnd();

    //sun
	GLfloat x=3.0f; GLfloat y=3.0f; GLfloat radius =.3f;
	int triangleAmount = 20; //# of triangles used to draw circle

    GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,211,0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


    //clouds
    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
    //cloud1
    x=-0.8f; y=3.6f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 1.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=-0.6f; y=3.6f;radius =.17f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 1.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}

	glEnd();
	x=-0.4f; y=3.6f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 1.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//cloud2
	x=-1.8f; y=2.7f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 2.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-1.6f; y=2.7f;radius =.17f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 2.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-1.4f; y=2.7f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 2.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//cloud3
	x=-2.8f; y=3.2f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 3.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-2.6f; y=3.2f;radius =.17f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 3.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-2.4f; y=3.2f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 3.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//cloud4
	x=-1.9f; y=3.5f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 4.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-1.6f; y=3.5f;radius =.25f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 4.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-1.3f; y=3.5f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 4.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//cloud5
	x=-4.9f; y=2.7f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 5.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-4.6f; y=2.7f;radius =.25f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 5.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-4.3f; y=2.7f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 5.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//cloud6
	x=-6.8f; y=3.2f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 6.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=-6.6f; y=3.2f;radius =.17f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 6.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-6.4f; y=3.2f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 6.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//cloud7
	x=-5.9f; y=3.5f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 7.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-5.6f; y=3.5f;radius =.25f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 7.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-5.3f; y=3.5f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 7.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    //cloud8
	x=2.9f; y=3.2f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 8.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=2.6f; y=3.2f;radius =.25f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 8.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=2.3f; y=3.2f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 8.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//cloud9
	x=1.6f; y=3.2f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 9.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=1.4f; y=3.2f;radius =.17f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 9.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=1.2f; y=3.2f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 9.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//cloud10
	x=0.9f; y=2.7f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 10.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=0.6f; y=2.7f;radius =.25f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 10.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=0.3f; y=2.7f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 10.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glPopMatrix();


	//birds
	//bird-1
	glPushMatrix();
	glTranslatef(position,0.0f, 0.0f);
	glLineWidth(3.0);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); // Black color
	glVertex2f(-2.5f, 2.7f);    // x, y
	glVertex2f(-2.45f, 2.6f);    // x, y
    glVertex2f(-2.45f, 2.6f);    // x, y
	glVertex2f(-2.4f, 2.7f);    // x, y
	glEnd();
	//bird2
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); // Black color
	glVertex2f(-2.7f, 2.7f);    // x, y
	glVertex2f(-2.65f, 2.6f);    // x, y
    glVertex2f(-2.65f, 2.6f);    // x, y
	glVertex2f(-2.6f, 2.7f);    // x, y
	glEnd();
    //bird3
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); // Black color
	glVertex2f(-2.3f, 2.7f);    // x, y
	glVertex2f(-2.25f, 2.6f);    // x, y
    glVertex2f(-2.25f, 2.6f);    // x, y
	glVertex2f(-2.2f, 2.7f);    // x, y
	glEnd();

	glPopMatrix();


	//back hills
    glBegin(GL_TRIANGLES);

    glColor3ub(45, 134, 45);//hill-1
    glVertex2f(-4.0f,2.0f);
    glVertex2f(-3.0f,2.0f);
    glVertex2f(-3.5f,2.5f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(45, 134, 45);//hill-2
    glVertex2f(-2.0f,2.0f);
    glVertex2f(-3.0f,2.0f);
    glVertex2f(-2.5f,2.2f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(45, 134, 45);//hill-3
    glVertex2f(-2.0f,2.0f);
    glVertex2f(0.0f,2.0f);
    glVertex2f(-1.0f,2.6f);
    glEnd();


    glBegin(GL_TRIANGLES);

    glColor3ub(45, 134, 45);//hill-4
    glVertex2f(1.0f,2.0f);
    glVertex2f(0.0f,2.0f);
    glVertex2f(0.5f,2.3f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(45, 134, 45);//hill-5
    glVertex2f(1.0f,2.0f);
    glVertex2f(1.5f,2.0f);
    glVertex2f(1.25f,2.2f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(45, 134, 45);//hill-6
    glVertex2f(3.0f,2.0f);
    glVertex2f(1.5f,2.0f);
    glVertex2f(2.0f,2.5f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(45, 134, 45);//hill-7
    glVertex2f(3.0f,2.0f);
    glVertex2f(4.0f,2.0f);
    glVertex2f(3.5f,2.5f);
    glEnd();



    //houses

    glBegin(GL_QUADS);
    glColor3ub(255, 128, 0);//house
    glVertex2f(-3.4f,-0.1f);
    glVertex2f(-1.6f,-0.1f);
    glVertex2f(-1.6f,1.0f);
    glVertex2f(-3.4f,1.0f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(153, 31, 0);//left window
    glVertex2f(-3.4f,0.9f);
    glVertex2f(-3.4f,0.6f);
    glVertex2f(-3.1f,0.6f);
    glVertex2f(-3.1f,0.9f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(153, 31, 0);//right window
    glVertex2f(-1.6f,0.9f);
    glVertex2f(-1.6f,0.6f);
    glVertex2f(-1.9f,0.6f);
    glVertex2f(-1.9f,0.9f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 31, 0);//Door
    glVertex2f(-2.6f,-0.1f);//bottom left
    glVertex2f(-2.3f,-0.1f);//bottom right
    glVertex2f(-2.3f,0.2f);//top right
    glVertex2f(-2.6f,0.2f);//top left
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 0, 0);//2nd house
    glVertex2f(-1.6f,0.2f);//bottom left
    glVertex2f(-0.4f,0.2f);//bottom right
    glVertex2f(-0.4f,1.3f);//top right
    glVertex2f(-1.6f,1.3f);//top left
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 77, 51);// 1st house top
    glVertex2f(-3.7f,1.0f);
    glVertex2f(-1.3f,1.0f);
    glVertex2f(-2.0f,1.5f);
    glVertex2f(-3.0f,1.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 255);//2nd home left window
    glVertex2f(-1.6f,1.0f);//bottom left
    glVertex2f(-1.6f,0.6f);//bottom right
    glVertex2f(-1.3f,0.6f);//top right
    glVertex2f(-1.3f,1.0f);//top left
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 255);//2nd home right window
    glVertex2f(-0.4,1.0f);//bottom left
    glVertex2f(-0.4f,0.6f);//bottom right
    glVertex2f(-0.7f,0.6f);//top right
    glVertex2f(-0.7f,1.0f);//top left
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 255);//2nd home door
    glVertex2f(-1.2f,0.2f);//bottom left
    glVertex2f(-0.8f,0.2f);//bottom right
    glVertex2f(-0.8f,0.5);//top right
    glVertex2f(-1.2f,0.5f);//top left
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(204, 51, 153);//2nd home top
    glVertex2f(-0.4f,1.3f);
    glVertex2f(-1.6f,1.3f);
    glVertex2f(-1.0f,1.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);//Tree 1 base
    glVertex2f(0.3f,1.0f);//bottom left
    glVertex2f(0.6f,1.0f);//bottom right
    glVertex2f(0.6f,0.0f);//top right
    glVertex2f(0.3f,0.0f);//top left
    glEnd();

     glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);//tree 1  leaf
    glVertex2f(0.0f,0.8f);
    glVertex2f(0.9f,0.8f);
    glVertex2f(0.45f,1.8f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);//tree 1 top leaf
    glVertex2f(0.1f,1.3f);
    glVertex2f(0.8f,1.3f);
    glVertex2f(0.45f,2.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 102, 0);//3rd house base
    glVertex2f(2.0f,1.5f);
    glVertex2f(2.0f,0.8f);
    glVertex2f(2.8f,0.8f);
    glVertex2f(2.8f,1.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 0, 0);//3rd house top
    glVertex2f(1.7f,1.5f);
    glVertex2f(2.0f,1.8f);
    glVertex2f(2.8f,1.8f);
    glVertex2f(3.1f,1.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);//3rd house left window
    glVertex2f(2.0f,1.3f);
    glVertex2f(2.0f,1.1f);
    glVertex2f(2.2f,1.1f);
    glVertex2f(2.2f,1.3f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0,0,0);//3rd house right window
    glVertex2f(2.8f,1.3f);
    glVertex2f(2.8f,1.1f);
    glVertex2f(2.6f,1.1f);
    glVertex2f(2.6f,1.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);//3rd house door
    glVertex2f(2.3f,0.8f);
    glVertex2f(2.3f,1.0f);
    glVertex2f(2.5f,1.0f);
    glVertex2f(2.5f,0.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 102, 0);//3rd house door
    glVertex2f(1.1f,0.2f);
    glVertex2f(1.2f,1.5f);
    glVertex2f(1.3f,1.5f);
    glVertex2f(1.4f,0.2f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);//tree 2 leaf
    glVertex2f(0.8f,1.2f);
    glVertex2f(1.7f,1.2f);
    glVertex2f(1.3f,2.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 102, 0);//2nd home door
    glVertex2f(3.3f,0.3f);//bottom left
    glVertex2f(3.4f,1.2f);//bottom right
    glVertex2f(3.5f,1.2f);//top right
    glVertex2f(3.6f,0.3f);//top left
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);//tree 1 top leaf
    glVertex2f(3.0f,0.7f);
    glVertex2f(3.9f,0.7f);
    glVertex2f(3.45f,1.5f);
    glEnd();


    //windmill building
    glBegin(GL_QUADS);

    glColor3ub(72,61,139);
    glVertex2f(-0.2f, -1.0f);
    glVertex2f(0.2f, -1.0f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glEnd();

    glPushMatrix();
    glRotatef(j,0,0.0,0.1);//i=how many degree you want to rotate around an axis

    //windmill 4 fans
    glBegin(GL_TRIANGLES);

    glColor3ub(139,69,19);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.4f, -0.1f);
    glVertex2f(0.4f, 0.1f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(139,69,19);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.1f, 0.4f);
    glVertex2f(-0.1f, 0.4f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(139,69,19);
    glVertex2f(0.0f, 0.0f);
    glVertex2f( -0.4f, 0.1f);
    glVertex2f( -0.4f, -0.1f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(139,69,19);
    glVertex2f(0.0f, 0.0f);
    glVertex2f( -0.1f, -0.4f);
    glVertex2f( 0.1f, -0.4f);
    glEnd();

    glPopMatrix();

    j = j - 0.1f; //clock wise rotate

    int j;
    x=0.0f; y=0.0f; radius =.07f;
	triangleAmount = 20; //# of triangles used to draw circle


	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

    //fan circle
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(245,255,250);
		glVertex2f(x, y); // First Ray
		for(j = 0; j <= triangleAmount;j++) {
			glVertex2f(
		            x + (radius * cos(j *  twicePi / triangleAmount)),
			    y + (radius * sin(j * twicePi / triangleAmount))
			);
		}
    glEnd();


    //boats
    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);//Boat
    glVertex2f(-3.0f,-1.5f);//bottom left
    glVertex2f(-1.0f,-1.5f);//bottom right
    glVertex2f(-1.4f,-1.8f);//top right
    glVertex2f(-2.6f,-1.8f);//top left
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 102, 0);//Boat top
    glVertex2f(-2.6f,-1.5f);//bottom left
    glVertex2f(-2.3f,-1.2f);//bottom right
    glVertex2f(-1.7f,-1.2f);//top right
    glVertex2f(-1.4f,-1.5f);//top left
    glEnd();
    glPopMatrix();

    //boat2
    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);
    glScalef(1.0f,1.0f,0.0f);

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);//Boat 2
    glVertex2f(0.5f,-2.8f);//bottom left
    glVertex2f(0.0f,-2.5f);//bottom right
    glVertex2f(2.5f,-2.5f);//top right
    glVertex2f(2.0f,-2.8f);//top left
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 102, 0);//Boat top 2
    glVertex2f(0.5f,-2.5f);//bottom left
    glVertex2f(0.8f,-2.2f);//bottom right
    glVertex2f(2.0f,-2.2f);//top right
    glVertex2f(2.0f,-2.5f);//top left
    glEnd();

    glLoadIdentity();
    glPopMatrix();




    //Rain
    glPushMatrix();
    glTranslatef(0.0f,Rainposition, 0.0f);

    glBegin(GL_LINES);
    glLineWidth(0.2);
    glColor3f(1.0f, 1.0f, 1.0f);


    //-3.9x
   glVertex2f(-3.9f,-3.4f);
   glVertex2f(-3.9f,-3.8f);
   glVertex2f(-3.9f,-3.0f);
   glVertex2f(-3.9f,-3.2f);
   glVertex2f(-3.9f,-2.2f);
   glVertex2f(-3.9f,-2.8f);
   glVertex2f(-3.9f,-1.3f);
   glVertex2f(-3.9f,-1.8f);
   glVertex2f(-3.9f,0.3f);
   glVertex2f(-3.9f,-1.1f);

   glVertex2f(-3.9f,3.8f);
   glVertex2f(-3.9f,3.4f);
   glVertex2f(-3.9f,3.2f);
   glVertex2f(-3.9f,3.0f);
   glVertex2f(-3.9f,2.8f);
   glVertex2f(-3.9f,2.2f);
   glVertex2f(-3.9f,1.8f);
   glVertex2f(-3.9f,1.3f);
   glVertex2f(-3.9f,1.6f);
   glVertex2f(-3.9f,0.6f);


    //-3.7x
   glVertex2f(-3.7f,-3.4f);
   glVertex2f(-3.7f,-3.8f);
   glVertex2f(-3.7f,-3.0f);
   glVertex2f(-3.7f,-3.2f);
   glVertex2f(-3.7f,-2.2f);
   glVertex2f(-3.7f,-2.8f);
   glVertex2f(-3.7f,-1.3f);
   glVertex2f(-3.7f,-1.8f);
   glVertex2f(-3.7f,0.3f);
   glVertex2f(-3.7f,-1.1f);

   glVertex2f(-3.7f,3.8f);
   glVertex2f(-3.7f,3.4f);
   glVertex2f(-3.7f,3.2f);
   glVertex2f(-3.7f,3.0f);
   glVertex2f(-3.7f,2.8f);
   glVertex2f(-3.7f,2.2f);
   glVertex2f(-3.7f,1.8f);
   glVertex2f(-3.7f,1.3f);
   glVertex2f(-3.7f,1.6f);
   glVertex2f(-3.7f,0.6f);

   //-3.5x
   glVertex2f(-3.5f,-3.4f);
   glVertex2f(-3.5f,-3.8f);
   glVertex2f(-3.5f,-3.0f);
   glVertex2f(-3.5f,-3.2f);
   glVertex2f(-3.5f,-2.2f);
   glVertex2f(-3.5f,-2.8f);
   glVertex2f(-3.5f,-1.3f);
   glVertex2f(-3.5f,-1.8f);
   glVertex2f(-3.5f,0.3f);
   glVertex2f(-3.5f,-1.1f);

   glVertex2f(-3.5f,3.8f);
   glVertex2f(-3.5f,3.4f);
   glVertex2f(-3.5f,3.2f);
   glVertex2f(-3.5f,3.0f);
   glVertex2f(-3.5f,2.8f);
   glVertex2f(-3.5f,2.2f);
   glVertex2f(-3.5f,1.8f);
   glVertex2f(-3.5f,1.3f);
   glVertex2f(-3.5f,1.6f);
   glVertex2f(-3.5f,0.6f);

   //-3.3
   glVertex2f(-3.3f,-3.4f);
   glVertex2f(-3.3f,-3.8f);
   glVertex2f(-3.3f,-3.0f);
   glVertex2f(-3.3f,-3.2f);
   glVertex2f(-3.3f,-2.2f);
   glVertex2f(-3.3f,-2.8f);
   glVertex2f(-3.3f,-1.3f);
   glVertex2f(-3.3f,-1.8f);
   glVertex2f(-3.3f,0.3f);
   glVertex2f(-3.3f,-1.1f);

   glVertex2f(-3.3f,3.8f);
   glVertex2f(-3.3f,3.4f);
   glVertex2f(-3.3f,3.2f);
   glVertex2f(-3.3f,3.0f);
   glVertex2f(-3.3f,2.8f);
   glVertex2f(-3.3f,2.2f);
   glVertex2f(-3.3f,1.8f);
   glVertex2f(-3.3f,1.3f);
   glVertex2f(-3.3f,1.6f);
   glVertex2f(-3.3f,0.6f);

   //-3.1
   glVertex2f(-3.1f,-3.4f);
   glVertex2f(-3.1f,-3.8f);
   glVertex2f(-3.1f,-3.0f);
   glVertex2f(-3.1f,-3.2f);
   glVertex2f(-3.1f,-2.2f);
   glVertex2f(-3.1f,-2.8f);
   glVertex2f(-3.1f,-1.3f);
   glVertex2f(-3.1f,-1.8f);
   glVertex2f(-3.1f,0.3f);
   glVertex2f(-3.1f,-1.1f);

   glVertex2f(-3.1f,3.8f);
   glVertex2f(-3.1f,3.4f);
   glVertex2f(-3.1f,3.2f);
   glVertex2f(-3.1f,3.0f);
   glVertex2f(-3.1f,2.8f);
   glVertex2f(-3.1f,2.2f);
   glVertex2f(-3.1f,1.8f);
   glVertex2f(-3.1f,1.3f);
   glVertex2f(-3.1f,1.6f);
   glVertex2f(-3.1f,0.6f);

   //-2.9
   glVertex2f(-2.9f,-3.4f);
   glVertex2f(-2.9f,-3.8f);
   glVertex2f(-2.9f,-3.0f);
   glVertex2f(-2.9f,-3.2f);
   glVertex2f(-2.9f,-2.2f);
   glVertex2f(-2.9f,-2.8f);
   glVertex2f(-2.9f,-1.3f);
   glVertex2f(-2.9f,-1.8f);
   glVertex2f(-2.9f,0.3f);
   glVertex2f(-2.9f,-1.1f);

   glVertex2f(-2.9f,3.8f);
   glVertex2f(-2.9f,3.4f);
   glVertex2f(-2.9f,3.2f);
   glVertex2f(-2.9f,3.0f);
   glVertex2f(-2.9f,2.8f);
   glVertex2f(-2.9f,2.2f);
   glVertex2f(-2.9f,1.8f);
   glVertex2f(-2.9f,1.3f);
   glVertex2f(-2.9f,1.6f);
   glVertex2f(-2.9f,0.6f);

   //-2.7
   glVertex2f(-2.7f,-3.4f);
   glVertex2f(-2.7f,-3.8f);
   glVertex2f(-2.7f,-3.0f);
   glVertex2f(-2.7f,-3.2f);
   glVertex2f(-2.7f,-2.2f);
   glVertex2f(-2.7f,-2.8f);
   glVertex2f(-2.7f,-1.3f);
   glVertex2f(-2.7f,-1.8f);
   glVertex2f(-2.7f,0.3f);
   glVertex2f(-2.7f,-1.1f);

   glVertex2f(-2.7f,3.8f);
   glVertex2f(-2.7f,3.4f);
   glVertex2f(-2.7f,3.2f);
   glVertex2f(-2.7f,3.0f);
   glVertex2f(-2.7f,2.8f);
   glVertex2f(-2.7f,2.2f);
   glVertex2f(-2.7f,1.8f);
   glVertex2f(-2.7f,1.3f);
   glVertex2f(-2.7f,1.6f);
   glVertex2f(-2.7f,0.6f);

   //-2.5
   glVertex2f(-2.5f,-3.4f);
   glVertex2f(-2.5f,-3.8f);
   glVertex2f(-2.5f,-3.0f);
   glVertex2f(-2.5f,-3.2f);
   glVertex2f(-2.5f,-2.2f);
   glVertex2f(-2.5f,-2.8f);
   glVertex2f(-2.5f,-1.3f);
   glVertex2f(-2.5f,-1.8f);
   glVertex2f(-2.5f,0.3f);
   glVertex2f(-2.5f,-1.1f);

   glVertex2f(-2.5f,3.8f);
   glVertex2f(-2.5f,3.4f);
   glVertex2f(-2.5f,3.2f);
   glVertex2f(-2.5f,3.0f);
   glVertex2f(-2.5f,2.8f);
   glVertex2f(-2.5f,2.2f);
   glVertex2f(-2.5f,1.8f);
   glVertex2f(-2.5f,1.3f);
   glVertex2f(-2.5f,1.6f);
   glVertex2f(-2.5f,0.6f);

   //-2.3
   glVertex2f(-2.3f,-3.4f);
   glVertex2f(-2.3f,-3.8f);
   glVertex2f(-2.3f,-3.0f);
   glVertex2f(-2.3f,-3.2f);
   glVertex2f(-2.3f,-2.2f);
   glVertex2f(-2.3f,-2.8f);
   glVertex2f(-2.3f,-1.3f);
   glVertex2f(-2.3f,-1.8f);
   glVertex2f(-2.3f,0.3f);
   glVertex2f(-2.3f,-1.1f);

   glVertex2f(-2.3f,3.8f);
   glVertex2f(-2.3f,3.4f);
   glVertex2f(-2.3f,3.2f);
   glVertex2f(-2.3f,3.0f);
   glVertex2f(-2.3f,2.8f);
   glVertex2f(-2.3f,2.2f);
   glVertex2f(-2.3f,1.8f);
   glVertex2f(-2.3f,1.3f);
   glVertex2f(-2.3f,1.6f);
   glVertex2f(-2.3f,0.6f);

   //2.1
   glVertex2f(-2.1f,-3.4f);
   glVertex2f(-2.1f,-3.8f);
   glVertex2f(-2.1f,-3.0f);
   glVertex2f(-2.1f,-3.2f);
   glVertex2f(-2.1f,-2.2f);
   glVertex2f(-2.1f,-2.8f);
   glVertex2f(-2.1f,-1.3f);
   glVertex2f(-2.1f,-1.8f);
   glVertex2f(-2.1f,0.3f);
   glVertex2f(-2.1f,-1.1f);

   glVertex2f(-2.1f,3.8f);
   glVertex2f(-2.1f,3.4f);
   glVertex2f(-2.1f,3.2f);
   glVertex2f(-2.1f,3.0f);
   glVertex2f(-2.1f,2.8f);
   glVertex2f(-2.1f,2.2f);
   glVertex2f(-2.1f,1.8f);
   glVertex2f(-2.1f,1.3f);
   glVertex2f(-2.1f,1.6f);
   glVertex2f(-2.1f,0.6f);

   //-1.9
   glVertex2f(-1.9f,-3.4f);
   glVertex2f(-1.9f,-3.8f);
   glVertex2f(-1.9f,-3.0f);
   glVertex2f(-1.9f,-3.2f);
   glVertex2f(-1.9f,-2.2f);
   glVertex2f(-1.9f,-2.8f);
   glVertex2f(-1.9f,-1.3f);
   glVertex2f(-1.9f,-1.8f);
   glVertex2f(-1.9f,0.3f);
   glVertex2f(-1.9f,-1.1f);

   glVertex2f(-1.9f,3.8f);
   glVertex2f(-1.9f,3.4f);
   glVertex2f(-1.9f,3.2f);
   glVertex2f(-1.9f,3.0f);
   glVertex2f(-1.9f,2.8f);
   glVertex2f(-1.9f,2.2f);
   glVertex2f(-1.9f,1.8f);
   glVertex2f(-1.9f,1.3f);
   glVertex2f(-1.9f,1.6f);
   glVertex2f(-1.9f,0.6f);

   //-1.7
   glVertex2f(-1.7f,-3.4f);
   glVertex2f(-1.7f,-3.8f);
   glVertex2f(-1.7f,-3.0f);
   glVertex2f(-1.7f,-3.2f);
   glVertex2f(-1.7f,-2.2f);
   glVertex2f(-1.7f,-2.8f);
   glVertex2f(-1.7f,-1.3f);
   glVertex2f(-1.7f,-1.8f);
   glVertex2f(-1.7f,0.3f);
   glVertex2f(-1.7f,-1.1f);

   glVertex2f(-1.7f,3.8f);
   glVertex2f(-1.7f,3.4f);
   glVertex2f(-1.7f,3.2f);
   glVertex2f(-1.7f,3.0f);
   glVertex2f(-1.7f,2.8f);
   glVertex2f(-1.7f,2.2f);
   glVertex2f(-1.7f,1.8f);
   glVertex2f(-1.7f,1.3f);
   glVertex2f(-1.7f,1.6f);
   glVertex2f(-1.7f,0.6f);

   //-1.5
   glVertex2f(-1.5f,-3.4f);
   glVertex2f(-1.5f,-3.8f);
   glVertex2f(-1.5f,-3.0f);
   glVertex2f(-1.5f,-3.2f);
   glVertex2f(-1.5f,-2.2f);
   glVertex2f(-1.5f,-2.8f);
   glVertex2f(-1.5f,-1.3f);
   glVertex2f(-1.5f,-1.8f);
   glVertex2f(-1.5f,0.3f);
   glVertex2f(-1.5f,-1.1f);

   glVertex2f(-1.5f,3.8f);
   glVertex2f(-1.5f,3.4f);
   glVertex2f(-1.5f,3.2f);
   glVertex2f(-1.5f,3.0f);
   glVertex2f(-1.5f,2.8f);
   glVertex2f(-1.5f,2.2f);
   glVertex2f(-1.5f,1.8f);
   glVertex2f(-1.5f,1.3f);
   glVertex2f(-1.5f,1.6f);
   glVertex2f(-1.5f,0.6f);

   //-1.3
   glVertex2f(-1.3f,-3.4f);
   glVertex2f(-1.3f,-3.8f);
   glVertex2f(-1.3f,-3.0f);
   glVertex2f(-1.3f,-3.2f);
   glVertex2f(-1.3f,-2.2f);
   glVertex2f(-1.3f,-2.8f);
   glVertex2f(-1.3f,-1.3f);
   glVertex2f(-1.3f,-1.8f);
   glVertex2f(-1.3f,0.3f);
   glVertex2f(-1.3f,-1.1f);

   glVertex2f(-1.3f,3.8f);
   glVertex2f(-1.3f,3.4f);
   glVertex2f(-1.3f,3.2f);
   glVertex2f(-1.3f,3.0f);
   glVertex2f(-1.3f,2.8f);
   glVertex2f(-1.3f,2.2f);
   glVertex2f(-1.3f,1.8f);
   glVertex2f(-1.3f,1.3f);
   glVertex2f(-1.3f,1.6f);
   glVertex2f(-1.3f,0.6f);

   //-1.1
   glVertex2f(-1.1f,-3.4f);
   glVertex2f(-1.1f,-3.8f);
   glVertex2f(-1.1f,-3.0f);
   glVertex2f(-1.1f,-3.2f);
   glVertex2f(-1.1f,-2.2f);
   glVertex2f(-1.1f,-2.8f);
   glVertex2f(-1.1f,-1.3f);
   glVertex2f(-1.1f,-1.8f);
   glVertex2f(-1.1f,0.3f);
   glVertex2f(-1.1f,-1.1f);

   glVertex2f(-1.1f,3.8f);
   glVertex2f(-1.1f,3.4f);
   glVertex2f(-1.1f,3.2f);
   glVertex2f(-1.1f,3.0f);
   glVertex2f(-1.1f,2.8f);
   glVertex2f(-1.1f,2.2f);
   glVertex2f(-1.1f,1.8f);
   glVertex2f(-1.1f,1.3f);
   glVertex2f(-1.1f,1.6f);
   glVertex2f(-1.1f,0.6f);

   //-0.9
   glVertex2f(-0.9f,-3.4f);
   glVertex2f(-0.9f,-3.8f);
   glVertex2f(-0.9f,-3.0f);
   glVertex2f(-0.9f,-3.2f);
   glVertex2f(-0.9f,-2.2f);
   glVertex2f(-0.9f,-2.8f);
   glVertex2f(-0.9f,-1.3f);
   glVertex2f(-0.9f,-1.8f);
   glVertex2f(-0.9f,0.3f);
   glVertex2f(-0.9f,-1.1f);

   glVertex2f(-0.9f,3.8f);
   glVertex2f(-0.9f,3.4f);
   glVertex2f(-0.9f,3.2f);
   glVertex2f(-0.9f,3.0f);
   glVertex2f(-0.9f,2.8f);
   glVertex2f(-0.9f,2.2f);
   glVertex2f(-0.9f,1.8f);
   glVertex2f(-0.9f,1.3f);
   glVertex2f(-0.9f,1.6f);
   glVertex2f(-0.9f,0.6f);

   //-0.7
   //-0.9
   glVertex2f(-0.7f,-3.4f);
   glVertex2f(-0.7f,-3.8f);
   glVertex2f(-0.7f,-3.0f);
   glVertex2f(-0.7f,-3.2f);
   glVertex2f(-0.7f,-2.2f);
   glVertex2f(-0.7f,-2.8f);
   glVertex2f(-0.7f,-1.3f);
   glVertex2f(-0.7f,-1.8f);
   glVertex2f(-0.7f,0.3f);
   glVertex2f(-0.7f,-1.1f);

   glVertex2f(-0.7f,3.8f);
   glVertex2f(-0.7f,3.4f);
   glVertex2f(-0.7f,3.2f);
   glVertex2f(-0.7f,3.0f);
   glVertex2f(-0.7f,2.8f);
   glVertex2f(-0.7f,2.2f);
   glVertex2f(-0.7f,1.8f);
   glVertex2f(-0.7f,1.3f);
   glVertex2f(-0.7f,1.6f);
   glVertex2f(-0.7f,0.6f);

   //-0.5
   glVertex2f(-0.5f,-3.4f);
   glVertex2f(-0.5f,-3.8f);
   glVertex2f(-0.5f,-3.0f);
   glVertex2f(-0.5f,-3.2f);
   glVertex2f(-0.5f,-2.2f);
   glVertex2f(-0.5f,-2.8f);
   glVertex2f(-0.5f,-1.3f);
   glVertex2f(-0.5f,-1.8f);
   glVertex2f(-0.5f,0.3f);
   glVertex2f(-0.5f,-1.1f);

   glVertex2f(-0.5f,3.8f);
   glVertex2f(-0.5f,3.4f);
   glVertex2f(-0.5f,3.2f);
   glVertex2f(-0.5f,3.0f);
   glVertex2f(-0.5f,2.8f);
   glVertex2f(-0.5f,2.2f);
   glVertex2f(-0.5f,1.8f);
   glVertex2f(-0.5f,1.3f);
   glVertex2f(-0.5f,1.6f);
   glVertex2f(-0.5f,0.6f);

   //-.3
   glVertex2f(-0.3f,-3.4f);
   glVertex2f(-0.3f,-3.8f);
   glVertex2f(-0.3f,-3.0f);
   glVertex2f(-0.3f,-3.2f);
   glVertex2f(-0.3f,-2.2f);
   glVertex2f(-0.3f,-2.8f);
   glVertex2f(-0.3f,-1.3f);
   glVertex2f(-0.3f,-1.8f);
   glVertex2f(-0.3f,0.3f);
   glVertex2f(-0.3f,-1.1f);

   glVertex2f(-0.3f,3.8f);
   glVertex2f(-0.3f,3.4f);
   glVertex2f(-0.3f,3.2f);
   glVertex2f(-0.3f,3.0f);
   glVertex2f(-0.3f,2.8f);
   glVertex2f(-0.3f,2.2f);
   glVertex2f(-0.3f,1.8f);
   glVertex2f(-0.3f,1.3f);
   glVertex2f(-0.3f,1.6f);
   glVertex2f(-0.3f,0.6f);

   //-0.1
   glVertex2f(-0.1f,-3.4f);
   glVertex2f(-0.1f,-3.8f);
   glVertex2f(-0.1f,-3.0f);
   glVertex2f(-0.1f,-3.2f);
   glVertex2f(-0.1f,-2.2f);
   glVertex2f(-0.1f,-2.8f);
   glVertex2f(-0.1f,-1.3f);
   glVertex2f(-0.1f,-1.8f);
   glVertex2f(-0.1f,0.3f);
   glVertex2f(-0.1f,-1.1f);

   glVertex2f(-0.1f,3.8f);
   glVertex2f(-0.1f,3.4f);
   glVertex2f(-0.1f,3.2f);
   glVertex2f(-0.1f,3.0f);
   glVertex2f(-0.1f,2.8f);
   glVertex2f(-0.1f,2.2f);
   glVertex2f(-0.1f,1.8f);
   glVertex2f(-0.1f,1.3f);
   glVertex2f(-0.1f,1.6f);
   glVertex2f(-0.1f,0.6f);

   //
   //
   //POSITIVE X SIDE OF RAIN
   //
   //
    //3.9x
   glVertex2f(3.9f,-3.4f);
   glVertex2f(3.9f,-3.8f);
   glVertex2f(3.9f,-3.0f);
   glVertex2f(3.9f,-3.2f);
   glVertex2f(3.9f,-2.2f);
   glVertex2f(3.9f,-2.8f);
   glVertex2f(3.9f,-1.3f);
   glVertex2f(3.9f,-1.8f);
   glVertex2f(3.9f,0.3f);
   glVertex2f(3.9f,-1.1f);

   glVertex2f(3.9f,3.8f);
   glVertex2f(3.9f,3.4f);
   glVertex2f(3.9f,3.2f);
   glVertex2f(3.9f,3.0f);
   glVertex2f(3.9f,2.8f);
   glVertex2f(3.9f,2.2f);
   glVertex2f(3.9f,1.8f);
   glVertex2f(3.9f,1.3f);
   glVertex2f(3.9f,1.6f);
   glVertex2f(3.9f,0.6f);


    //3.7x
   glVertex2f(3.7f,-3.4f);
   glVertex2f(3.7f,-3.8f);
   glVertex2f(3.7f,-3.0f);
   glVertex2f(3.7f,-3.2f);
   glVertex2f(3.7f,-2.2f);
   glVertex2f(3.7f,-2.8f);
   glVertex2f(3.7f,-1.3f);
   glVertex2f(3.7f,-1.8f);
   glVertex2f(3.7f,0.3f);
   glVertex2f(3.7f,-1.1f);

   glVertex2f(3.7f,3.8f);
   glVertex2f(3.7f,3.4f);
   glVertex2f(3.7f,3.2f);
   glVertex2f(3.7f,3.0f);
   glVertex2f(3.7f,2.8f);
   glVertex2f(3.7f,2.2f);
   glVertex2f(3.7f,1.8f);
   glVertex2f(3.7f,1.3f);
   glVertex2f(3.7f,1.6f);
   glVertex2f(3.7f,0.6f);

   //3.5x
   glVertex2f(3.5f,-3.4f);
   glVertex2f(3.5f,-3.8f);
   glVertex2f(3.5f,-3.0f);
   glVertex2f(3.5f,-3.2f);
   glVertex2f(3.5f,-2.2f);
   glVertex2f(3.5f,-2.8f);
   glVertex2f(3.5f,-1.3f);
   glVertex2f(3.5f,-1.8f);
   glVertex2f(3.5f,0.3f);
   glVertex2f(3.5f,-1.1f);

   glVertex2f(3.5f,3.8f);
   glVertex2f(3.5f,3.4f);
   glVertex2f(3.5f,3.2f);
   glVertex2f(3.5f,3.0f);
   glVertex2f(3.5f,2.8f);
   glVertex2f(3.5f,2.2f);
   glVertex2f(3.5f,1.8f);
   glVertex2f(3.5f,1.3f);
   glVertex2f(3.5f,1.6f);
   glVertex2f(3.5f,0.6f);

   //3.3
   glVertex2f(3.3f,-3.4f);
   glVertex2f(3.3f,-3.8f);
   glVertex2f(3.3f,-3.0f);
   glVertex2f(3.3f,-3.2f);
   glVertex2f(3.3f,-2.2f);
   glVertex2f(3.3f,-2.8f);
   glVertex2f(3.3f,-1.3f);
   glVertex2f(3.3f,-1.8f);
   glVertex2f(3.3f,0.3f);
   glVertex2f(3.3f,-1.1f);

   glVertex2f(3.3f,3.8f);
   glVertex2f(3.3f,3.4f);
   glVertex2f(3.3f,3.2f);
   glVertex2f(3.3f,3.0f);
   glVertex2f(3.3f,2.8f);
   glVertex2f(3.3f,2.2f);
   glVertex2f(3.3f,1.8f);
   glVertex2f(3.3f,1.3f);
   glVertex2f(3.3f,1.6f);
   glVertex2f(3.3f,0.6f);

   //3.1
   glVertex2f(3.1f,-3.4f);
   glVertex2f(3.1f,-3.8f);
   glVertex2f(3.1f,-3.0f);
   glVertex2f(3.1f,-3.2f);
   glVertex2f(3.1f,-2.2f);
   glVertex2f(3.1f,-2.8f);
   glVertex2f(3.1f,-1.3f);
   glVertex2f(3.1f,-1.8f);
   glVertex2f(3.1f,0.3f);
   glVertex2f(3.1f,-1.1f);

   glVertex2f(3.1f,3.8f);
   glVertex2f(3.1f,3.4f);
   glVertex2f(3.1f,3.2f);
   glVertex2f(3.1f,3.0f);
   glVertex2f(3.1f,2.8f);
   glVertex2f(3.1f,2.2f);
   glVertex2f(3.1f,1.8f);
   glVertex2f(3.1f,1.3f);
   glVertex2f(3.1f,1.6f);
   glVertex2f(3.1f,0.6f);

   //2.9
   glVertex2f(2.9f,-3.4f);
   glVertex2f(2.9f,-3.8f);
   glVertex2f(2.9f,-3.0f);
   glVertex2f(2.9f,-3.2f);
   glVertex2f(2.9f,-2.2f);
   glVertex2f(2.9f,-2.8f);
   glVertex2f(2.9f,-1.3f);
   glVertex2f(2.9f,-1.8f);
   glVertex2f(2.9f,0.3f);
   glVertex2f(2.9f,-1.1f);

   glVertex2f(2.9f,3.8f);
   glVertex2f(2.9f,3.4f);
   glVertex2f(2.9f,3.2f);
   glVertex2f(2.9f,3.0f);
   glVertex2f(2.9f,2.8f);
   glVertex2f(2.9f,2.2f);
   glVertex2f(2.9f,1.8f);
   glVertex2f(2.9f,1.3f);
   glVertex2f(2.9f,1.6f);
   glVertex2f(2.9f,0.6f);

   //2.7
   glVertex2f(2.7f,-3.4f);
   glVertex2f(2.7f,-3.8f);
   glVertex2f(2.7f,-3.0f);
   glVertex2f(2.7f,-3.2f);
   glVertex2f(2.7f,-2.2f);
   glVertex2f(2.7f,-2.8f);
   glVertex2f(2.7f,-1.3f);
   glVertex2f(2.7f,-1.8f);
   glVertex2f(2.7f,0.3f);
   glVertex2f(2.7f,-1.1f);

   glVertex2f(2.7f,3.8f);
   glVertex2f(2.7f,3.4f);
   glVertex2f(2.7f,3.2f);
   glVertex2f(2.7f,3.0f);
   glVertex2f(2.7f,2.8f);
   glVertex2f(2.7f,2.2f);
   glVertex2f(2.7f,1.8f);
   glVertex2f(2.7f,1.3f);
   glVertex2f(2.7f,1.6f);
   glVertex2f(2.7f,0.6f);

   //2.5
   glVertex2f(2.5f,-3.4f);
   glVertex2f(2.5f,-3.8f);
   glVertex2f(2.5f,-3.0f);
   glVertex2f(2.5f,-3.2f);
   glVertex2f(2.5f,-2.2f);
   glVertex2f(2.5f,-2.8f);
   glVertex2f(2.5f,-1.3f);
   glVertex2f(2.5f,-1.8f);
   glVertex2f(2.5f,0.3f);
   glVertex2f(2.5f,-1.1f);

   glVertex2f(2.5f,3.8f);
   glVertex2f(2.5f,3.4f);
   glVertex2f(2.5f,3.2f);
   glVertex2f(2.5f,3.0f);
   glVertex2f(2.5f,2.8f);
   glVertex2f(2.5f,2.2f);
   glVertex2f(2.5f,1.8f);
   glVertex2f(2.5f,1.3f);
   glVertex2f(2.5f,1.6f);
   glVertex2f(2.5f,0.6f);

   //2.3
   glVertex2f(2.3f,-3.4f);
   glVertex2f(2.3f,-3.8f);
   glVertex2f(2.3f,-3.0f);
   glVertex2f(2.3f,-3.2f);
   glVertex2f(2.3f,-2.2f);
   glVertex2f(2.3f,-2.8f);
   glVertex2f(2.3f,-1.3f);
   glVertex2f(2.3f,-1.8f);
   glVertex2f(2.3f,0.3f);
   glVertex2f(2.3f,-1.1f);

   glVertex2f(2.3f,3.8f);
   glVertex2f(2.3f,3.4f);
   glVertex2f(2.3f,3.2f);
   glVertex2f(2.3f,3.0f);
   glVertex2f(2.3f,2.8f);
   glVertex2f(2.3f,2.2f);
   glVertex2f(2.3f,1.8f);
   glVertex2f(2.3f,1.3f);
   glVertex2f(2.3f,1.6f);
   glVertex2f(2.3f,0.6f);

   //2.1
   glVertex2f(2.1f,-3.4f);
   glVertex2f(2.1f,-3.8f);
   glVertex2f(2.1f,-3.0f);
   glVertex2f(2.1f,-3.2f);
   glVertex2f(2.1f,-2.2f);
   glVertex2f(2.1f,-2.8f);
   glVertex2f(2.1f,-1.3f);
   glVertex2f(2.1f,-1.8f);
   glVertex2f(2.1f,0.3f);
   glVertex2f(2.1f,-1.1f);

   glVertex2f(2.1f,3.8f);
   glVertex2f(2.1f,3.4f);
   glVertex2f(2.1f,3.2f);
   glVertex2f(2.1f,3.0f);
   glVertex2f(2.1f,2.8f);
   glVertex2f(2.1f,2.2f);
   glVertex2f(2.1f,1.8f);
   glVertex2f(2.1f,1.3f);
   glVertex2f(2.1f,1.6f);
   glVertex2f(2.1f,0.6f);

   //1.9
   glVertex2f(1.9f,-3.4f);
   glVertex2f(1.9f,-3.8f);
   glVertex2f(1.9f,-3.0f);
   glVertex2f(1.9f,-3.2f);
   glVertex2f(1.9f,-2.2f);
   glVertex2f(1.9f,-2.8f);
   glVertex2f(1.9f,-1.3f);
   glVertex2f(1.9f,-1.8f);
   glVertex2f(1.9f,0.3f);
   glVertex2f(1.9f,-1.1f);

   glVertex2f(1.9f,3.8f);
   glVertex2f(1.9f,3.4f);
   glVertex2f(1.9f,3.2f);
   glVertex2f(1.9f,3.0f);
   glVertex2f(1.9f,2.8f);
   glVertex2f(1.9f,2.2f);
   glVertex2f(1.9f,1.8f);
   glVertex2f(1.9f,1.3f);
   glVertex2f(1.9f,1.6f);
   glVertex2f(1.9f,0.6f);

   //1.7
   glVertex2f(1.7f,-3.4f);
   glVertex2f(1.7f,-3.8f);
   glVertex2f(1.7f,-3.0f);
   glVertex2f(1.7f,-3.2f);
   glVertex2f(1.7f,-2.2f);
   glVertex2f(1.7f,-2.8f);
   glVertex2f(1.7f,-1.3f);
   glVertex2f(1.7f,-1.8f);
   glVertex2f(1.7f,0.3f);
   glVertex2f(1.7f,-1.1f);

   glVertex2f(1.7f,3.8f);
   glVertex2f(1.7f,3.4f);
   glVertex2f(1.7f,3.2f);
   glVertex2f(1.7f,3.0f);
   glVertex2f(1.7f,2.8f);
   glVertex2f(1.7f,2.2f);
   glVertex2f(1.7f,1.8f);
   glVertex2f(1.7f,1.3f);
   glVertex2f(1.7f,1.6f);
   glVertex2f(1.7f,0.6f);

   //1.5
   glVertex2f(1.5f,-3.4f);
   glVertex2f(1.5f,-3.8f);
   glVertex2f(1.5f,-3.0f);
   glVertex2f(1.5f,-3.2f);
   glVertex2f(1.5f,-2.2f);
   glVertex2f(1.5f,-2.8f);
   glVertex2f(1.5f,-1.3f);
   glVertex2f(1.5f,-1.8f);
   glVertex2f(1.5f,0.3f);
   glVertex2f(1.5f,-1.1f);

   glVertex2f(1.5f,3.8f);
   glVertex2f(1.5f,3.4f);
   glVertex2f(1.5f,3.2f);
   glVertex2f(1.5f,3.0f);
   glVertex2f(1.5f,2.8f);
   glVertex2f(1.5f,2.2f);
   glVertex2f(1.5f,1.8f);
   glVertex2f(1.5f,1.3f);
   glVertex2f(1.5f,1.6f);
   glVertex2f(1.5f,0.6f);

   //1.3
   glVertex2f(1.3f,-3.4f);
   glVertex2f(1.3f,-3.8f);
   glVertex2f(1.3f,-3.0f);
   glVertex2f(1.3f,-3.2f);
   glVertex2f(1.3f,-2.2f);
   glVertex2f(1.3f,-2.8f);
   glVertex2f(1.3f,-1.3f);
   glVertex2f(1.3f,-1.8f);
   glVertex2f(1.3f,0.3f);
   glVertex2f(1.3f,-1.1f);

   glVertex2f(1.3f,3.8f);
   glVertex2f(1.3f,3.4f);
   glVertex2f(1.3f,3.2f);
   glVertex2f(1.3f,3.0f);
   glVertex2f(1.3f,2.8f);
   glVertex2f(1.3f,2.2f);
   glVertex2f(1.3f,1.8f);
   glVertex2f(1.3f,1.3f);
   glVertex2f(1.3f,1.6f);
   glVertex2f(1.3f,0.6f);

   //1.1
   glVertex2f(1.1f,-3.4f);
   glVertex2f(1.1f,-3.8f);
   glVertex2f(1.1f,-3.0f);
   glVertex2f(1.1f,-3.2f);
   glVertex2f(1.1f,-2.2f);
   glVertex2f(1.1f,-2.8f);
   glVertex2f(1.1f,-1.3f);
   glVertex2f(1.1f,-1.8f);
   glVertex2f(1.1f,0.3f);
   glVertex2f(1.1f,-1.1f);

   glVertex2f(1.1f,3.8f);
   glVertex2f(1.1f,3.4f);
   glVertex2f(1.1f,3.2f);
   glVertex2f(1.1f,3.0f);
   glVertex2f(1.1f,2.8f);
   glVertex2f(1.1f,2.2f);
   glVertex2f(1.1f,1.8f);
   glVertex2f(1.1f,1.3f);
   glVertex2f(1.1f,1.6f);
   glVertex2f(1.1f,0.6f);

   //0.9
   glVertex2f(0.9f,-3.4f);
   glVertex2f(0.9f,-3.8f);
   glVertex2f(0.9f,-3.0f);
   glVertex2f(0.9f,-3.2f);
   glVertex2f(0.9f,-2.2f);
   glVertex2f(0.9f,-2.8f);
   glVertex2f(0.9f,-1.3f);
   glVertex2f(0.9f,-1.8f);
   glVertex2f(0.9f,0.3f);
   glVertex2f(0.9f,-1.1f);

   glVertex2f(0.9f,3.8f);
   glVertex2f(0.9f,3.4f);
   glVertex2f(0.9f,3.2f);
   glVertex2f(0.9f,3.0f);
   glVertex2f(0.9f,2.8f);
   glVertex2f(0.9f,2.2f);
   glVertex2f(0.9f,1.8f);
   glVertex2f(0.9f,1.3f);
   glVertex2f(0.9f,1.6f);
   glVertex2f(0.9f,0.6f);

   //-0.7
   glVertex2f(0.7f,-3.4f);
   glVertex2f(0.7f,-3.8f);
   glVertex2f(0.7f,-3.0f);
   glVertex2f(0.7f,-3.2f);
   glVertex2f(0.7f,-2.2f);
   glVertex2f(0.7f,-2.8f);
   glVertex2f(0.7f,-1.3f);
   glVertex2f(0.7f,-1.8f);
   glVertex2f(0.7f,0.3f);
   glVertex2f(0.7f,-1.1f);

   glVertex2f(0.7f,3.8f);
   glVertex2f(0.7f,3.4f);
   glVertex2f(0.7f,3.2f);
   glVertex2f(0.7f,3.0f);
   glVertex2f(0.7f,2.8f);
   glVertex2f(0.7f,2.2f);
   glVertex2f(0.7f,1.8f);
   glVertex2f(0.7f,1.3f);
   glVertex2f(0.7f,1.6f);
   glVertex2f(0.7f,0.6f);

   //0.5
   glVertex2f(0.5f,-3.4f);
   glVertex2f(0.5f,-3.8f);
   glVertex2f(0.5f,-3.0f);
   glVertex2f(0.5f,-3.2f);
   glVertex2f(0.5f,-2.2f);
   glVertex2f(0.5f,-2.8f);
   glVertex2f(0.5f,-1.3f);
   glVertex2f(0.5f,-1.8f);
   glVertex2f(0.5f,0.3f);
   glVertex2f(0.5f,-1.1f);

   glVertex2f(0.5f,3.8f);
   glVertex2f(0.5f,3.4f);
   glVertex2f(0.5f,3.2f);
   glVertex2f(0.5f,3.0f);
   glVertex2f(0.5f,2.8f);
   glVertex2f(0.5f,2.2f);
   glVertex2f(0.5f,1.8f);
   glVertex2f(0.5f,1.3f);
   glVertex2f(0.5f,1.6f);
   glVertex2f(0.5f,0.6f);

   //.3
   glVertex2f(0.3f,-3.4f);
   glVertex2f(0.3f,-3.8f);
   glVertex2f(0.3f,-3.0f);
   glVertex2f(0.3f,-3.2f);
   glVertex2f(0.3f,-2.2f);
   glVertex2f(0.3f,-2.8f);
   glVertex2f(0.3f,-1.3f);
   glVertex2f(0.3f,-1.8f);
   glVertex2f(0.3f,0.3f);
   glVertex2f(0.3f,-1.1f);

   glVertex2f(0.3f,3.8f);
   glVertex2f(0.3f,3.4f);
   glVertex2f(0.3f,3.2f);
   glVertex2f(0.3f,3.0f);
   glVertex2f(0.3f,2.8f);
   glVertex2f(0.3f,2.2f);
   glVertex2f(0.3f,1.8f);
   glVertex2f(0.3f,1.3f);
   glVertex2f(0.3f,1.6f);
   glVertex2f(0.3f,0.6f);

   //0.1
   glVertex2f(0.1f,-3.4f);
   glVertex2f(0.1f,-3.8f);
   glVertex2f(0.1f,-3.0f);
   glVertex2f(0.1f,-3.2f);
   glVertex2f(0.1f,-2.2f);
   glVertex2f(0.1f,-2.8f);
   glVertex2f(0.1f,-1.3f);
   glVertex2f(0.1f,-1.8f);
   glVertex2f(0.1f,0.3f);
   glVertex2f(0.1f,-1.1f);

   glVertex2f(0.1f,3.8f);
   glVertex2f(0.1f,3.4f);
   glVertex2f(0.1f,3.2f);
   glVertex2f(0.1f,3.0f);
   glVertex2f(0.1f,2.8f);
   glVertex2f(0.1f,2.2f);
   glVertex2f(0.1f,1.8f);
   glVertex2f(0.1f,1.3f);
   glVertex2f(0.1f,1.6f);
   glVertex2f(0.1f,0.6f);

   glEnd();

  glLoadIdentity();
  glPopMatrix();



   glFlush();
}



void night()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //black
    glClear(GL_COLOR_BUFFER_BIT);

     glBegin(GL_QUADS);
    glColor3ub(75, 92, 50);//base
    glVertex2f(-4.0f,2.0f);
    glVertex2f(-4.0f,-1.2f);
    glVertex2f(4.0f,-1.0f);
    glVertex2f(4.0f,2.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(106, 106, 107);//sky
    glVertex2f(-4.0f,2.0f);
    glVertex2f(-4.0f,4.0f);
    glVertex2f(4.0f,4.0f);
    glVertex2f(4.0f,2.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(62, 81, 156);//river
    glVertex2f(-4.0f,-4.0f);
    glVertex2f(4.0f,-4.0f);
    glVertex2f(4.0f,-1.0f);
    glVertex2f(-4.0f,-1.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 26, 0);//road
    glVertex2f(4.0f,-1.0f);
    glVertex2f(-4.0f,-1.2f);
    glVertex2f(-4.0f,-0.8f);
    glVertex2f(4.0f,-0.6f);
    glEnd();

    //moon
	GLfloat x=3.0f; GLfloat y=3.0f; GLfloat radius =.3f;
	int triangleAmount = 20; //# of triangles used to draw circle

    GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(247, 248, 250);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


    //still clouds

    //cloud1
    x=-0.8f; y=3.6f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 1.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-0.6f; y=3.6f;radius =.17f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 1.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


	x=-0.4f; y=3.6f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 1.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//cloud3
	x=-2.8f; y=3.2f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 3.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=-2.6f; y=3.2f;radius =.17f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 3.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=-2.4f; y=3.2f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 3.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//cloud4
	x=-1.9f; y=3.5f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 4.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=-1.6f; y=3.5f;radius =.25f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 4.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=-1.3f; y=3.5f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 4.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


	//cloud6
	x=-6.8f; y=3.2f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 6.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=-6.6f; y=3.2f;radius =.17f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 6.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-6.4f; y=3.2f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 6.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


	//cloud9
	x=1.6f; y=3.2f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 9.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=1.4f; y=3.2f;radius =.17f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 9.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=1.2f; y=3.2f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 9.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//cloud10
	x=0.9f; y=2.7f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 10.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=0.6f; y=2.7f;radius =.25f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 10.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=0.3f; y=2.7f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
		glVertex2f(x, y); // Cloud 10.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    //running clouds

    //cloud2
    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
	x=-1.8f; y=2.7f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // Cloud 2.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-1.6f; y=2.7f;radius =.17f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // Cloud 2.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-1.4f; y=2.7f;radius =.1f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // Cloud 2.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//cloud8
	x=2.9f; y=3.2f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // Cloud 8.1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=2.6f; y=3.2f;radius =.25f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // Cloud 8.2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=2.3f; y=3.2f;radius =.15f;
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51, 51, 51);
		glVertex2f(x, y); // Cloud 8.3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glPopMatrix();


    //back hills
    glBegin(GL_TRIANGLES);

    glColor3ub(57, 61, 46);//hill-1
    glVertex2f(-4.0f,2.0f);
    glVertex2f(-3.0f,2.0f);
    glVertex2f(-3.5f,2.5f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(57, 61, 46);//hill-2
    glVertex2f(-2.0f,2.0f);
    glVertex2f(-3.0f,2.0f);
    glVertex2f(-2.5f,2.2f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(57, 61, 46);//hill-3
    glVertex2f(-2.0f,2.0f);
    glVertex2f(0.0f,2.0f);
    glVertex2f(-1.0f,2.6f);
    glEnd();


    glBegin(GL_TRIANGLES);

    glColor3ub(57, 61, 46);//hill-4
    glVertex2f(1.0f,2.0f);
    glVertex2f(0.0f,2.0f);
    glVertex2f(0.5f,2.3f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(57, 61, 46);//hill-5
    glVertex2f(1.0f,2.0f);
    glVertex2f(1.5f,2.0f);
    glVertex2f(1.25f,2.2f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(57, 61, 46);//hill-6
    glVertex2f(3.0f,2.0f);
    glVertex2f(1.5f,2.0f);
    glVertex2f(2.0f,2.5f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(57, 61, 46);//hill-7
    glVertex2f(3.0f,2.0f);
    glVertex2f(4.0f,2.0f);
    glVertex2f(3.5f,2.5f);
    glEnd();



    //houses

    glBegin(GL_QUADS);
    glColor3ub(255, 128, 0);//house
    glVertex2f(-3.4f,-0.1f);
    glVertex2f(-1.6f,-0.1f);
    glVertex2f(-1.6f,1.0f);
    glVertex2f(-3.4f,1.0f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(153, 31, 0);//left window
    glVertex2f(-3.4f,0.9f);
    glVertex2f(-3.4f,0.6f);
    glVertex2f(-3.1f,0.6f);
    glVertex2f(-3.1f,0.9f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(153, 31, 0);//right window
    glVertex2f(-1.6f,0.9f);
    glVertex2f(-1.6f,0.6f);
    glVertex2f(-1.9f,0.6f);
    glVertex2f(-1.9f,0.9f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 31, 0);//Door
    glVertex2f(-2.6f,-0.1f);//bottom left
    glVertex2f(-2.3f,-0.1f);//bottom right
    glVertex2f(-2.3f,0.2f);//top right
    glVertex2f(-2.6f,0.2f);//top left
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 0, 0);//2nd house
    glVertex2f(-1.6f,0.2f);//bottom left
    glVertex2f(-0.4f,0.2f);//bottom right
    glVertex2f(-0.4f,1.3f);//top right
    glVertex2f(-1.6f,1.3f);//top left
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 77, 51);// 1st house top
    glVertex2f(-3.7f,1.0f);
    glVertex2f(-1.3f,1.0f);
    glVertex2f(-2.0f,1.5f);
    glVertex2f(-3.0f,1.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 255);//2nd home left window
    glVertex2f(-1.6f,1.0f);//bottom left
    glVertex2f(-1.6f,0.6f);//bottom right
    glVertex2f(-1.3f,0.6f);//top right
    glVertex2f(-1.3f,1.0f);//top left
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 255);//2nd home right window
    glVertex2f(-0.4,1.0f);//bottom left
    glVertex2f(-0.4f,0.6f);//bottom right
    glVertex2f(-0.7f,0.6f);//top right
    glVertex2f(-0.7f,1.0f);//top left
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 255);//2nd home door
    glVertex2f(-1.2f,0.2f);//bottom left
    glVertex2f(-0.8f,0.2f);//bottom right
    glVertex2f(-0.8f,0.5);//top right
    glVertex2f(-1.2f,0.5f);//top left
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(204, 51, 153);//2nd home top
    glVertex2f(-0.4f,1.3f);
    glVertex2f(-1.6f,1.3f);
    glVertex2f(-1.0f,1.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);//Tree 1 base
    glVertex2f(0.3f,1.0f);//bottom left
    glVertex2f(0.6f,1.0f);//bottom right
    glVertex2f(0.6f,0.0f);//top right
    glVertex2f(0.3f,0.0f);//top left
    glEnd();

     glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);//tree 1  leaf
    glVertex2f(0.0f,0.8f);
    glVertex2f(0.9f,0.8f);
    glVertex2f(0.45f,1.8f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);//tree 1 top leaf
    glVertex2f(0.1f,1.3f);
    glVertex2f(0.8f,1.3f);
    glVertex2f(0.45f,2.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 102, 0);//3rd house base
    glVertex2f(2.0f,1.5f);
    glVertex2f(2.0f,0.8f);
    glVertex2f(2.8f,0.8f);
    glVertex2f(2.8f,1.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 0, 0);//3rd house top
    glVertex2f(1.7f,1.5f);
    glVertex2f(2.0f,1.8f);
    glVertex2f(2.8f,1.8f);
    glVertex2f(3.1f,1.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);//3rd house left window
    glVertex2f(2.0f,1.3f);
    glVertex2f(2.0f,1.1f);
    glVertex2f(2.2f,1.1f);
    glVertex2f(2.2f,1.3f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0,0,0);//3rd house right window
    glVertex2f(2.8f,1.3f);
    glVertex2f(2.8f,1.1f);
    glVertex2f(2.6f,1.1f);
    glVertex2f(2.6f,1.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);//3rd house door
    glVertex2f(2.3f,0.8f);
    glVertex2f(2.3f,1.0f);
    glVertex2f(2.5f,1.0f);
    glVertex2f(2.5f,0.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 102, 0);//3rd house door
    glVertex2f(1.1f,0.2f);
    glVertex2f(1.2f,1.5f);
    glVertex2f(1.3f,1.5f);
    glVertex2f(1.4f,0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);//tree 2 leaf
    glVertex2f(0.8f,1.2f);
    glVertex2f(1.7f,1.2f);
    glVertex2f(1.3f,2.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 102, 0);//2nd home door
    glVertex2f(3.3f,0.3f);//bottom left
    glVertex2f(3.4f,1.2f);//bottom right
    glVertex2f(3.5f,1.2f);//top right
    glVertex2f(3.6f,0.3f);//top left
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);//tree 1 top leaf
    glVertex2f(3.0f,0.7f);
    glVertex2f(3.9f,0.7f);
    glVertex2f(3.45f,1.5f);
    glEnd();


    //windmill building
    glBegin(GL_QUADS);

    glColor3ub(72,61,139);
    glVertex2f(-0.2f, -1.0f);
    glVertex2f(0.2f, -1.0f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glEnd();

    glPushMatrix();
    glRotatef(j,0,0.0,0.1);//i=how many degree you want to rotate around an axis

    //windmill 4 fans
    glBegin(GL_TRIANGLES);

    glColor3ub(139,69,19);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.4f, -0.1f);
    glVertex2f(0.4f, 0.1f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(139,69,19);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.1f, 0.4f);
    glVertex2f(-0.1f, 0.4f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(139,69,19);
    glVertex2f(0.0f, 0.0f);
    glVertex2f( -0.4f, 0.1f);
    glVertex2f( -0.4f, -0.1f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(139,69,19);
    glVertex2f(0.0f, 0.0f);
    glVertex2f( -0.1f, -0.4f);
    glVertex2f( 0.1f, -0.4f);
    glEnd();

    glPopMatrix();

    j = j - 0.1f; //clock wise rotate

    int j;
    x=0.0f; y=0.0f; radius =.07f;
	triangleAmount = 20; //# of triangles used to draw circle


	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

    //fan circle
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(245,255,250);
		glVertex2f(x, y); // First Ray
		for(j = 0; j <= triangleAmount;j++) {
			glVertex2f(
		            x + (radius * cos(j *  twicePi / triangleAmount)),
			    y + (radius * sin(j * twicePi / triangleAmount))
			);
		}

    glEnd();


    //boats
    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);//Boat
    glVertex2f(-3.0f,-1.5f);//bottom left
    glVertex2f(-1.0f,-1.5f);//bottom right
    glVertex2f(-1.4f,-1.8f);//top right
    glVertex2f(-2.6f,-1.8f);//top left
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 102, 0);//Boat top
    glVertex2f(-2.6f,-1.5f);//bottom left
    glVertex2f(-2.3f,-1.2f);//bottom right
    glVertex2f(-1.7f,-1.2f);//top right
    glVertex2f(-1.4f,-1.5f);//top left
    glEnd();
    glPopMatrix();

    //boat2
    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);
    glScalef(1.0f,1.0f,0.0f);

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);//Boat 2
    glVertex2f(0.5f,-2.8f);//bottom left
    glVertex2f(0.0f,-2.5f);//bottom right
    glVertex2f(2.5f,-2.5f);//top right
    glVertex2f(2.0f,-2.8f);//top left
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 102, 0);//Boat top 2
    glVertex2f(0.5f,-2.5f);//bottom left
    glVertex2f(0.8f,-2.2f);//bottom right
    glVertex2f(2.0f,-2.2f);//top right
    glVertex2f(2.0f,-2.5f);//top left
    glEnd();

    glLoadIdentity();
    glPopMatrix();



    glFlush();
}


//RAIN SOUND
void sound()
{

    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
    PlaySound("rain.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}

//Village Sound
void sound1()
{

    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
    PlaySound("forest.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}

//Village Night
void soundNight()
{

    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
    PlaySound("night.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}

//Null Sound
void soundNo()
{

    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
    PlaySound("", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}


void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

case 'r':

    sound();
    glutDisplayFunc(display2);
    glutPostRedisplay();
    break;

case 's':

    sound1();
    glutDisplayFunc(display);
    glutPostRedisplay();

    break;

case 'n':
    soundNight();
    glutDisplayFunc(night);
    glutPostRedisplay();

    break;

case 'd':
    sound1();
    glutDisplayFunc(display);
    glutPostRedisplay();

    break;

	}

}


void handleMouse(int button, int state, int a, int b) {
	if (button == GLUT_LEFT_BUTTON)
	{
	    speed2 = 0.1f;
    }
    if (button == GLUT_RIGHT_BUTTON)
	{
	    speed2 = 0.0f;
	}
    glutPostRedisplay();
}

void SpecialInput(int key, int x, int y)
{

    switch(key)
    {
    case GLUT_KEY_UP:

    speed += 0.3f;
    break;

    case GLUT_KEY_DOWN:
    speed -= 0.1f;
    break;

    case GLUT_KEY_LEFT:
    speed = 0.1f;
    break;

    case GLUT_KEY_RIGHT:
    speed = 0.0f;
    break;
    }

    glutPostRedisplay();
}



   int main(int argc, char** argv)
    {
	  glutInit(&argc, argv);                 // Initialize GLUT
	  glutCreateWindow("Village Scenerio"); // Create a window with the given title
      glutInitWindowSize(320, 320);   // Set the window's initial width & height

      glutDisplayFunc(display);

	  init();       // Register display callback handler for window re-paint
      sound1();

      glutIdleFunc(Idle);

      glutKeyboardFunc(handleKeypress);
      glutTimerFunc(100, Rain, 0);

	  glutTimerFunc(100, update, 0);
      glutSpecialFunc(SpecialInput);

      glutTimerFunc(100, update2, 0);
      glutMouseFunc(handleMouse);

	  glutMainLoop();           // Enter the event-processing loop
	  return 0;
}
