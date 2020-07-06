#include <GL/glut.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

float xpos = 0, ypos = 0, zpos = 55, xrot = 0, yrot = 0, zrot = 0, angle = 0.0;

float cRadius = 10.0f;

float lastx, lasty;

float xrot=0.0f;
float yrot=0.0f;
float xdiff=0.0f;
float ydiff=0.0f;
bool mouseDown=false;
int is_depth;

void axis() {
    glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1000.0f, 0.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1000.0f, 0.0f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1000.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -1000.0f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 1000.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -1000.0f);
	glEnd();
}

void grass(int locX, int locY) {
	glPushMatrix();
	glTranslated(locX, locY, 0);
	glBegin(GL_LINE_STRIP);
	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-26.945f, -27.053f, 0.01f);
	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-27.805f, -27.053f, 2.0f);
	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-26.945f, -27.053f, 0.01f);

	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-26.945f, -27.053f, 0.01f);
	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-27.574f, -27.053f, 2.0f);
	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-26.945f, -27.053f, 0.01f);

	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-26.945f, -27.053f, 0.01f);
	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-27.144f, -27.053f, 2.0f);
	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-26.945f, -27.053f, 0.01f);

	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-26.945f, -27.053f, 0.01f);
	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-26.251f, -27.053f, 2.0f);
	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-26.945f, -27.053f, 0.01f);

	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-26.945f, -27.053f, 0.01f);
	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-25.92f, -27.053f, 2.0f);
	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-26.945f, -27.053f, 0.01f);
	glEnd();


	glBegin(GL_LINE_STRIP);
	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-26.945f, -27.053f, 0.01f);
	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-27.053f, -28.078f, 2.0f);
	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-26.945f, -27.053f, 0.01f);

	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-26.945f, -27.053f, 0.01f);
	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-27.053f, -27.748f, 2.0f);
	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-26.945f, -27.053f, 0.01f);

	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-26.945f, -27.053f, 0.01f);
	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-27.053f, -26.855, 2.0f);
	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-26.945f, -27.053f, 0.01f);

	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-26.945f, -27.053f, 0.01f);
	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-27.053f, -26.425f, 2.0f);
	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-26.945f, -27.053f, 0.01f);

	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-26.945f, -27.053f, 0.01f);
	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-25.92f, -26.193f, 2.0f);
	glColor3f((210.0f / 255.0f), (224.0f / 255.0f), (105.0f / 255.0f));
	glVertex3f(-26.945f, -27.053f, 0.01f);
	glEnd();
	glPopMatrix();
}

void randomGrass() {
	for (int i = 0; i < 57; i++) {
		for (int j = -1; j < 3; j++) {
			grass(j, i);
		}
	}

	glPushMatrix();
	glTranslatef(53.89f, 0.0f, 0.0f);
		for (int i = 0; i < 57; i++) {
			for (int j = -1; j < 3; j++) {
				grass(j, i);
			}
		}
	glPopMatrix();

	glPushMatrix();
	glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
	for (int i = 0; i < 57; i++) {
		for (int j = -1; j < 3; j++) {
			grass(j, i);
		}
	}
	glPopMatrix();
}

void terrain() {
	glBegin(GL_POLYGON);
	glColor3f((63.0f / 255.0f), (51.0f / 255.0f), (39.0f / 255.0f));
	glVertex3f(-29.369f, 29.369f, -500.0f);
	glColor3f((63.0f / 255.0f), (51.0f / 255.0f), (39.0f / 255.0f));
	glVertex3f(29.369f, 29.369f, -500.0f);
	glColor3f((63.0f / 255.0f), (51.0f / 255.0f), (39.0f / 255.0f));
	glVertex3f(29.369f, -29.369f, -500.0f);
	glColor3f((63.0f / 255.0f), (51.0f / 255.0f), (39.0f / 255.0f));
	glVertex3f(-29.369f, -29.369f, -500.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((104.0f / 255.0f), (184.0f / 255.0f), (39.0f / 255.0f));
	glVertex3f(-29.369f, 29.369f, -0.01f);
	glColor3f((65.0f / 255.0f), (133.0f / 255.0f), (9.0f / 255.0f));
	glVertex3f(29.369f, 29.369f, -0.01f);
	glColor3f((104.0f / 255.0f), (184.0f / 255.0f), (39.0f / 255.0f));
	glVertex3f(29.369f, -29.369f, -0.01f);
	glColor3f((65.0f / 255.0f), (133.0f / 255.0f), (9.0f / 255.0f));
	glVertex3f(-29.369f, -29.369f, -0.01f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((63.0f / 255.0f), (51.0f / 255.0f), (39.0f / 255.0f));
	glVertex3f(-29.369f, 29.369f, -500.0f);
	glColor3f((63.0f / 255.0f), (51.0f / 255.0f), (39.0f / 255.0f));
	glVertex3f(29.369f, 29.369f, -500.0f);
	glColor3f((63.0f / 255.0f), (51.0f / 255.0f), (39.0f / 255.0f));
	glVertex3f(29.369f, 29.369f, -0.01f);
	glColor3f((63.0f / 255.0f), (51.0f / 255.0f), (39.0f / 255.0f));
	glVertex3f(-29.369f, 29.369f, -0.01f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((63.0f / 255.0f), (51.0f / 255.0f), (39.0f / 255.0f));
	glVertex3f(29.369f, 29.369f, -500.0f);
	glColor3f((63.0f / 255.0f), (51.0f / 255.0f), (39.0f / 255.0f));
	glVertex3f(29.369f, -29.369f, -500.0f);
	glColor3f((63.0f / 255.0f), (51.0f / 255.0f), (39.0f / 255.0f));
	glVertex3f(29.369f, -29.369f, -0.01f);
	glColor3f((63.0f / 255.0f), (51.0f / 255.0f), (39.0f / 255.0f));
	glVertex3f(29.369f, 29.369f, -0.01f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((63.0f / 255.0f), (51.0f / 255.0f), (39.0f / 255.0f));
	glVertex3f(29.369f, -29.369f, -500.0f);
	glColor3f((63.0f / 255.0f), (51.0f / 255.0f), (39.0f / 255.0f));
	glVertex3f(-29.369f, -29.369f, -500.0f);
	glColor3f((63.0f / 255.0f), (51.0f / 255.0f), (39.0f / 255.0f));
	glVertex3f(-29.369f, -29.369f, -0.01f);
	glColor3f((63.0f / 255.0f), (51.0f / 255.0f), (39.0f / 255.0f));
	glVertex3f(29.369f, -29.369f, -0.01f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((63.0f / 255.0f), (51.0f / 255.0f), (39.0f / 255.0f));
	glVertex3f(-29.369f, -29.369f, -500.0f);
	glColor3f((63.0f / 255.0f), (51.0f / 255.0f), (39.0f / 255.0f));
	glVertex3f(-29.369f, 29.369f, -500.0f);
	glColor3f((63.0f / 255.0f), (51.0f / 255.0f), (39.0f / 255.0f));
	glVertex3f(-29.369f, 29.369f, -0.01f);
	glColor3f((63.0f / 255.0f), (51.0f / 255.0f), (39.0f / 255.0f));
	glVertex3f(-29.369f, -29.369f, -0.01f);
	glEnd();
}

void createPilars(float x, float y, float z, float radius, int lineamount, float height, float red, float green, float blue) {
	int i;
	float twicepi = 2.0f * 3.1428571428571428571428571428571f;

	glBegin(GL_POLYGON);
	for (i = 0; i < lineamount; i++) {
		glColor3f(red, green, blue);
		glVertex3f(x + (radius * cos(i * twicepi / lineamount)), y + (radius * sin(i * twicepi / lineamount)), z);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (i = 0; i < lineamount; i++) {
		glColor3f(red, green, blue);
		glVertex3f(x + (radius * cos(i * twicepi / lineamount)), y + (radius * sin(i * twicepi / lineamount)), z);
		glColor3f(red, green, blue);
		glVertex3f(x + (radius * cos((i + 1) * twicepi / lineamount)), y + (radius * sin((i + 1) * twicepi / lineamount)), z);
		glColor3f(red, green, blue);
		glVertex3f(x + (radius * cos((i + 1) * twicepi / lineamount)), y + (radius * sin((i + 1) * twicepi / lineamount)), (z + height));
		glColor3f(red, green, blue);
		glVertex3f(x + (radius * cos(i * twicepi / lineamount)), y + (radius * sin(i * twicepi / lineamount)), (z + height));
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (i = 0; i < lineamount; i++) {
		glColor3f(red, green, blue);
		glVertex3f(x + (radius * cos(i * twicepi / lineamount)), y + (radius * sin(i * twicepi / lineamount)), (z + height));
	}
	glEnd();
}

void bottomSide() {
	glPushMatrix();
	glRotatef(180.0f, 0.0f, 0.0f, 1.0f);

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-19.825f, 10.997f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-7.84f, 10.997f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-7.84f, -6.1f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-19.825f, -6.1f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-7.84f, 13.518f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.282f, 13.518f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.282f, -5.272f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-7.84f, -5.272f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-5.187f, -5.272f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.282f, -5.272f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.282f, -14.226f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-5.187f, -14.226f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(12.692f, -14.226f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.282f, -14.226f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.282f, -15.797f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(12.692f, -15.797f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(6.338f, -14.226f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(12.692f, -14.226f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(12.692f, -18.486f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(6.338f, -18.486f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.743f, -14.226f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(6.338f, -14.226f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(6.338f, -15.292f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.743f, -15.292f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 19.04f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(12.09f, 19.04f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(12.09f, 13.518f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 13.518f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-5.9f, 15.235f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-2.018f, 15.235f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 13.518f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-7.84f, 13.518f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(14.138f, 15.235f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(18.234f, 15.235f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.282f, 13.518f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(12.09f, 13.518f, 0.0f);
	glEnd();

	glPopMatrix();
}

void bottomSideFirstFloor() {
	glPushMatrix();
	glRotatef(180.0f, 0.0f, 0.0f, 1.0f);

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-19.825f, 10.997f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-7.84f, 10.997f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-7.84f, -6.1f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-19.825f, -6.1f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-7.84f, 13.518f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.282f, 13.518f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.282f, -5.272f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-7.84f, -5.272f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-5.187f, -5.272f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.282f, -5.272f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.282f, -14.226f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-5.187f, -14.226f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(12.692f, -14.226f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.282f, -14.226f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.282f, -15.797f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(12.692f, -15.797f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(6.338f, -14.226f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(12.692f, -14.226f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(12.692f, -18.486f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(6.338f, -18.486f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.743f, -14.226f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(6.338f, -14.226f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(6.338f, -15.292f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.743f, -15.292f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-5.9f, 15.235f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-2.018f, 15.235f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 13.518f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-7.84f, 13.518f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(14.138f, 15.235f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(18.234f, 15.235f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.282f, 13.518f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(12.09f, 13.518f, 0.0f);
	glEnd();

	glPopMatrix();

	glBegin(GL_POLYGON);
	glColor3f(0.9f, 0.83f, 0.64f);
	glVertex3f(-6.469f, 9.831f, 0.05f);
	glColor3f(0.9f, 0.83f, 0.64f);
	glVertex3f(3.668f, 2.466f, 0.05f);
	glColor3f(0.9f, 0.83f, 0.64f);
	glVertex3f(-0.204f, -9.45f, 0.05f);
	glColor3f(0.9f, 0.83f, 0.64f);
	glVertex3f(-12.734f, -9.45f, 0.05f);
	glColor3f(0.9f, 0.83f, 0.64f);
	glVertex3f(-16.606f, 2.466f, 0.05f);
	glEnd();
}

void frontSide() {
	//from rightest point and rigthest xyz area

	//1
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, -11.08f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(19.921f, -11.08f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(19.921f, -11.08f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, -11.08f, 10.0f);
	glEnd();
	//2
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, -11.08f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, -13.6f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, -11.08f, 10.0f);
	glEnd();
	//3
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(5.996f, -15.317f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(5.996f, -15.317f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, -13.6f, 10.0f);
	glEnd();
	//4
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(5.996f, -15.317f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(2.114f, -15.317f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(2.114f, -15.317f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(5.996f, -15.317f, 10.0f);
	glEnd();
	//5
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(2.114f, -15.317f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.096f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.096f, -13.6f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(2.114f, -15.317f, 10.0f);
	glEnd();
	//6
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.096f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.096f, -19.123f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.096f, -19.123f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.096f, -13.6f, 10.0f);
	glEnd();
	//7
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.096f, -19.123f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-11.994f, -19.123f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-11.994f, -19.123f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.096f, -19.123f, 10.0f);
	glEnd();
	//8
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-11.994f, -19.123f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-11.994f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-11.994f, -13.6f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-11.994f, -19.123f, 10.0f);
	glEnd();
	//9
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-11.994f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-14.042f, -15.317f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-14.042f, -15.317f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-11.994f, -13.6f, 10.0f);
	glEnd();
	//10
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-14.042f, -15.317f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-18.138f, -15.317f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-18.138f, -15.317f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-14.042f, -15.317f, 10.0f);
	glEnd();
	//11
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-18.138f, -15.317f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-20.186f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-20.186f, -13.6f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-18.138f, -15.317f, 10.0f);
	glEnd();
}

void rightSide() {
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-20.186f, 15.714f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-20.186f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-20.186f, -13.6f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-20.186f, 15.714f, 10.0f);
	glEnd();
}

void backSide() {
	//1
	//gap 1
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-20.186f, 15.714f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-18.848f, 15.713f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-18.848f, 15.713f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-20.186f, 15.714f, 10.0f);
	glEnd();

	//window 1
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-18.848f, 15.713f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-17.408f, 15.713f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-17.408f, 15.713f, 1.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-18.848f, 15.713f, 1.0f);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-18.848f, 15.713f, 1.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-17.408f, 15.713f, 1.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-17.408f, 15.713f, 9.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-18.848f, 15.713f, 9.0f);
	glEnd();
	glDisable(GL_BLEND);

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-18.848f, 15.713f, 9.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-17.408f, 15.713f, 9.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-17.408f, 15.713f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-18.848f, 15.713f, 10.0f);
	glEnd();

	//gap 2
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-17.408f, 15.713f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-15.375f, 15.713f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-15.375f, 15.713f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-17.408f, 15.713f, 10.0f);
	glEnd();

	//windows 2
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-15.375f, 15.713f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-13.934f, 15.713f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-13.934f, 15.713f, 1.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-15.375f, 15.713f, 1.0f);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-15.375f, 15.713f, 1.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-13.934f, 15.713f, 1.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-13.934f, 15.713f, 9.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-15.375f, 15.713f, 9.0f);
	glEnd();
	glDisable(GL_BLEND);

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-15.375f, 15.713f, 9.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-13.934f, 15.713f, 9.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-13.934f, 15.713f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-15.375f, 15.713f, 10.0f);
	glEnd();

	//gap 3
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-13.934f, 15.713f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-12.596f, 15.713f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-12.596f, 15.713f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-13.934f, 15.713f, 10.0f);
	glEnd();

	//2
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-12.596f, 15.714f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-12.596f, 18.403f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-12.596f, 18.403f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-12.596f, 15.714f, 10.0f);
	glEnd();
	//3
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-12.596f, 18.403f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-6.242f, 18.403f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-6.242f, 18.403f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-12.596f, 18.403f, 10.0f);
	glEnd();
	//4
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-6.242f, 18.403f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-6.242f, 15.209f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-6.242f, 15.209f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-6.242f, 18.403f, 10.0f);
	glEnd();
	//5
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-6.242f, 15.209f, 0.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-1.647f, 15.209f, 0.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-1.647f, 15.209f, 10.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-6.242f, 15.209f, 10.0f);
	glEnd();
	glDisable(GL_BLEND);
	//6
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-1.647f, 15.209f, 0.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-1.647f, 14.143f, 0.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-1.647f, 14.143f, 10.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-1.647f, 15.209f, 10.0f);
	glEnd();
	glDisable(GL_BLEND);
	//7
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-1.647f, 14.143f, 0.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(5.283f, 14.143f, 0.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(5.283f, 14.143f, 10.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-1.647f, 14.143f, 10.0f);
	glEnd();
	glDisable(GL_BLEND);
	//8
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(5.283f, 14.143f, 0.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(5.283f, 5.19f, 0.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(5.283f, 5.19f, 10.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(5.283f, 14.143f, 10.0f);
	glEnd();
	glDisable(GL_BLEND);
	//9
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(5.283f, 5.19f, 0.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(7.936f, 5.19f, 0.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(7.936f, 5.19f, 10.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(5.283f, 5.19f, 10.0f);
	glEnd();
	glDisable(GL_BLEND);
	//10
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, 5.19f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, 6.017f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, 6.017f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, 5.19f, 10.0f);
	glEnd();
	//11
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, 6.017f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(19.921f, 6.017f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(19.921f, 6.017f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, 6.017f, 10.0f);
	glEnd();

	glPushMatrix();
	glTranslatef(19.865f, 19.821f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.76f, 0.47f, 0.0f);
	glVertex3f(-3.055f, -13.6f, 0.0f);
	glColor3f(0.76f, 0.47f, 0.0f);
	glVertex3f(-8.818f, -13.6f, 0.0f);
	glColor3f(0.76f, 0.47f, 0.0f);
	glVertex3f(-8.818f, -13.6f, 7.0f);
	glColor3f(0.76f, 0.47f, 0.0f);
	glVertex3f(-3.055f, -13.6f, 7.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-3.055f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-8.818f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-8.818f, -13.6f, 7.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-3.055f, -13.6f, 7.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-5.936f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-5.936f, -13.6f, 7.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(19.865f, 20.23f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-6.859f, -13.811f, 3.259f);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-6.42f, -13.811f, 3.259f);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-6.42f, -13.811f, 3.741f);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-6.859f, -13.811f, 3.741f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-5.457f, -13.811f, 3.259f);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-5.019f, -13.811f, 3.259f);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-5.019f, -13.811f, 3.741f);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-5.457f, -13.811f, 3.741f);
	glEnd();
	glPopMatrix();

	//1
//gap 1
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-20.186f, 15.714f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-18.848f, 15.713f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-18.848f, 15.713f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-20.186f, 15.714f, 10.0f);
	glEnd();

	//window 1
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-18.848f, 15.713f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-17.408f, 15.713f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-17.408f, 15.713f, 1.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-18.848f, 15.713f, 1.0f);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-18.848f, 15.713f, 1.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-17.408f, 15.713f, 1.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-17.408f, 15.713f, 9.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-18.848f, 15.713f, 9.0f);
	glEnd();
	glDisable(GL_BLEND);

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-18.848f, 15.713f, 9.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-17.408f, 15.713f, 9.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-17.408f, 15.713f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-18.848f, 15.713f, 10.0f);
	glEnd();

	//gap 2
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-17.408f, 15.713f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-15.375f, 15.713f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-15.375f, 15.713f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-17.408f, 15.713f, 10.0f);
	glEnd();

	//windows 2
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-15.375f, 15.713f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-13.934f, 15.713f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-13.934f, 15.713f, 1.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-15.375f, 15.713f, 1.0f);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-15.375f, 15.713f, 1.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-13.934f, 15.713f, 1.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-13.934f, 15.713f, 9.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-15.375f, 15.713f, 9.0f);
	glEnd();
	glDisable(GL_BLEND);

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-15.375f, 15.713f, 9.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-13.934f, 15.713f, 9.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-13.934f, 15.713f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-15.375f, 15.713f, 10.0f);
	glEnd();

	//gap 3
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-13.934f, 15.713f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-12.596f, 15.713f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-12.596f, 15.713f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-13.934f, 15.713f, 10.0f);
	glEnd();

	//2
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-12.596f, 15.714f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-12.596f, 18.403f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-12.596f, 18.403f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-12.596f, 15.714f, 10.0f);
	glEnd();
	//3
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-12.596f, 18.403f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-6.242f, 18.403f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-6.242f, 18.403f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-12.596f, 18.403f, 10.0f);
	glEnd();
	//4
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-6.242f, 18.403f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-6.242f, 15.209f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-6.242f, 15.209f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-6.242f, 18.403f, 10.0f);
	glEnd();
	//5
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-6.242f, 15.209f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.647f, 15.209f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.647f, 15.209f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-6.242f, 15.209f, 10.0f);
	glEnd();
	glDisable(GL_BLEND);
	//6
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.647f, 15.209f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.647f, 14.143f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.647f, 14.143f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.647f, 15.209f, 10.0f);
	glEnd();
	glDisable(GL_BLEND);
	//7
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.647f, 14.143f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.283f, 14.143f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.283f, 14.143f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.647f, 14.143f, 10.0f);
	glEnd();
	glDisable(GL_BLEND);
	//8
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.283f, 14.143f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.283f, 5.19f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.283f, 5.19f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.283f, 14.143f, 10.0f);
	glEnd();
	glDisable(GL_BLEND);
	//9
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.283f, 5.19f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, 5.19f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, 5.19f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.283f, 5.19f, 10.0f);
	glEnd();
	glDisable(GL_BLEND);
	//10
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, 5.19f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, 6.017f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, 6.017f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, 5.19f, 10.0f);
	glEnd();
	//11
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, 6.017f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(19.921f, 6.017f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(19.921f, 6.017f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, 6.017f, 10.0f);
	glEnd();

	glPushMatrix();
	glTranslatef(19.865f, 19.821f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-3.055f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-8.818f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-8.818f, -13.6f, 7.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-3.055f, -13.6f, 7.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-3.055f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-8.818f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-8.818f, -13.6f, 7.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-3.055f, -13.6f, 7.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-5.936f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-5.936f, -13.6f, 7.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(19.865f, 20.23f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-6.859f, -13.811f, 3.259f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-6.42f, -13.811f, 3.259f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-6.42f, -13.811f, 3.741f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-6.859f, -13.811f, 3.741f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-5.457f, -13.811f, 3.259f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-5.019f, -13.811f, 3.259f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-5.019f, -13.811f, 3.741f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-5.457f, -13.811f, 3.741f);
	glEnd();
	glPopMatrix();
}

void backSideFirstFloor() {
	//1
	//gap 1
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-20.186f, 15.714f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-18.848f, 15.713f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-18.848f, 15.713f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-20.186f, 15.714f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-20.186f, 15.714f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-18.848f, 15.713f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-18.848f, 15.713f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-20.186f, 15.714f, 10.0f);
	glEnd();

	//window 1
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-18.848f, 15.713f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-17.408f, 15.713f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-17.408f, 15.713f, 1.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-18.848f, 15.713f, 1.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-18.848f, 15.713f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-17.408f, 15.713f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-17.408f, 15.713f, 1.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-18.848f, 15.713f, 1.0f);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-18.848f, 15.713f, 1.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-17.408f, 15.713f, 1.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-17.408f, 15.713f, 9.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-18.848f, 15.713f, 9.0f);
	glEnd();
	glDisable(GL_BLEND);

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-18.848f, 15.713f, 1.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-17.408f, 15.713f, 1.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-17.408f, 15.713f, 9.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-18.848f, 15.713f, 9.0f);
	glEnd();

	//gap 2
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-17.408f, 15.713f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-15.375f, 15.713f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-15.375f, 15.713f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-17.408f, 15.713f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-17.408f, 15.713f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-15.375f, 15.713f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-15.375f, 15.713f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-17.408f, 15.713f, 10.0f);
	glEnd();

	//windows 2
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-15.375f, 15.713f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-13.934f, 15.713f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-13.934f, 15.713f, 1.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-15.375f, 15.713f, 1.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-15.375f, 15.713f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-13.934f, 15.713f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-13.934f, 15.713f, 1.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-15.375f, 15.713f, 1.0f);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-15.375f, 15.713f, 1.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-13.934f, 15.713f, 1.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-13.934f, 15.713f, 9.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-15.375f, 15.713f, 9.0f);
	glEnd();
	glDisable(GL_BLEND);

	glBegin(GL_POLYGON);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-15.375f, 15.713f, 1.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-13.934f, 15.713f, 1.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-13.934f, 15.713f, 9.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-15.375f, 15.713f, 9.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-15.375f, 15.713f, 9.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-13.934f, 15.713f, 9.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-13.934f, 15.713f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-15.375f, 15.713f, 10.0f);
	glEnd();

	//gap 3
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-13.934f, 15.713f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-12.596f, 15.713f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-12.596f, 15.713f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-13.934f, 15.713f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-13.934f, 15.713f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-12.596f, 15.713f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-12.596f, 15.713f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-13.934f, 15.713f, 10.0f);
	glEnd();

	//2
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-12.596f, 15.713f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-12.596f, 18.403f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-12.596f, 18.403f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-12.596f, 15.713f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-12.596f, 15.713f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-12.596f, 18.403f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-12.596f, 18.403f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-12.596f, 15.713f, 10.0f);
	glEnd();

	//3
	//gap 1
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-12.596f, 18.403f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-10.86f, 18.403f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-10.86f, 18.403f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-12.596f, 18.403f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-12.596f, 18.403f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-10.86f, 18.403f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-10.86f, 18.403f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-12.596f, 18.403f, 10.0f);
	glEnd();

	//door
	glBegin(GL_POLYGON);
	glColor3f(0.76f, 0.47f, 0.0f);
	glVertex3f(-10.86f, 18.403f, 0.0f);
	glColor3f(0.76f, 0.47f, 0.0f);
	glVertex3f(-7.978f, 18.403f, 0.0f);
	glColor3f(0.76f, 0.47f, 0.0f);
	glVertex3f(-7.978f, 18.403f, 7.0f);
	glColor3f(0.76f, 0.47f, 0.0f);
	glVertex3f(-10.86f, 18.403f, 7.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-10.86f, 18.403f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-7.978f, 18.403f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-7.978f, 18.403f, 7.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-10.86f, 18.403f, 7.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-10.86f, 18.403f, 7.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-7.978f, 18.403f, 7.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-7.978f, 18.403f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-10.86f, 18.403f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-10.86f, 18.403f, 7.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-7.978f, 18.403f, 7.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-7.978f, 18.403f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-10.86f, 18.403f, 10.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-8.907f, 18.497f, 3.259f);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-8.468f, 18.497f, 3.259f);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-8.468f, 18.497f, 3.741f);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-8.907f, 18.497f, 3.741f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-8.907f, 18.497f, 3.259f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-8.468f, 18.497f, 3.259f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-8.468f, 18.497f, 3.741f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-8.907f, 18.497f, 3.741f);
	glEnd();

	//gap 2
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-7.978f, 18.403f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-6.242f, 18.403f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-6.242f, 18.403f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-7.978f, 18.403f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-7.978f, 18.403f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-6.242f, 18.403f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-6.242f, 18.403f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-7.978f, 18.403f, 10.0f);
	glEnd();

	//4
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-6.242f, 18.403f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-6.242f, 15.209f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-6.242f, 15.209f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-6.242f, 18.403f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-6.242f, 18.403f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-6.242f, 15.209f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-6.242f, 15.209f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-6.242f, 18.403f, 10.0f);
	glEnd();
	//5
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-6.242f, 15.209f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.647f, 15.209f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.647f, 15.209f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-6.242f, 15.209f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-6.242f, 15.209f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.647f, 15.209f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.647f, 15.209f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-6.242f, 15.209f, 10.0f);
	glEnd();
	//6
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.647f, 15.209f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.647f, 14.143f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.647f, 14.143f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.647f, 15.209f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.647f, 15.209f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.647f, 14.143f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.647f, 14.143f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.647f, 15.209f, 10.0f);
	glEnd();
	//7
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.647f, 14.143f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(5.283f, 14.143f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(5.283f, 14.143f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.647f, 14.143f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.647f, 14.143f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.283f, 14.143f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.283f, 14.143f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.647f, 14.143f, 10.0f);
	glEnd();
	//8
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(5.283f, 14.143f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(5.283f, 5.19f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(5.283f, 5.19f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(5.283f, 14.143f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.283f, 14.143f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.283f, 5.19f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.283f, 5.19f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.283f, 14.143f, 10.0f);
	glEnd();
	//9
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(5.283f, 5.19f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, 5.19f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, 5.19f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(5.283f, 5.19f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.283f, 5.19f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, 5.19f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, 5.19f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.283f, 5.19f, 10.0f);
	glEnd();
	//10
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, 5.19f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, 6.017f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, 6.017f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, 5.19f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, 5.19f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, 6.017f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, 6.017f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, 5.19f, 10.0f);
	glEnd();
	//11
	//gap 1
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, 6.017f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(9.282f, 6.017f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(9.282f, 6.017f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, 6.017f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, 6.017f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, 6.017f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, 6.017f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, 6.017f, 10.0f);
	glEnd();

	//window
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(9.282f, 6.017f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(18.576f, 6.017f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(18.576f, 6.017f, 1.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(9.282f, 6.017f, 1.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, 6.017f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, 6.017f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, 6.017f, 1.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, 6.017f, 1.0f);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(9.282f, 6.017f, 1.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(18.576f, 6.017f, 1.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(18.576f, 6.017f, 9.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(9.282f, 6.017f, 9.0f);
	glEnd();
	glDisable(GL_BLEND);

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, 6.017f, 1.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, 6.017f, 1.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, 6.017f, 9.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, 6.017f, 9.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(9.282f, 6.017f, 9.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(18.576f, 6.017f, 9.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(18.576f, 6.017f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(9.282f, 6.017f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, 6.017f, 9.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, 6.017f, 9.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, 6.017f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, 6.017f, 10.0f);
	glEnd();

	//gap 2
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(18.576f, 6.017f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(19.921f, 6.017f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(19.921f, 6.017f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(18.576f, 6.017f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, 6.017f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(19.921f, 6.017f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(19.921f, 6.017f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, 6.017f, 10.0f);
	glEnd();
}

void leftSide() {
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(19.921f, 6.017f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(19.921f, -11.08f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(19.921f, -11.08f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(19.921f, 6.017f, 10.0f);
	glEnd();
}

void topSide() {
	glPushMatrix();
	glRotatef(180.0f, 0.0f, 0.0f, 1.0f);

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-19.825f, 10.997f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-7.84f, 10.997f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-7.84f, -6.1f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-19.825f, -6.1f, 10.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-7.84f, 13.518f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.282f, 13.518f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.282f, -5.272f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-7.84f, -5.272f, 10.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-5.187f, -5.272f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.282f, -5.272f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.282f, -14.226f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-5.187f, -14.226f, 10.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(12.692f, -14.226f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.282f, -14.226f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.282f, -15.797f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(12.692f, -15.797f, 10.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(6.338f, -14.226f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(12.692f, -14.226f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(12.692f, -18.486f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(6.338f, -18.486f, 10.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.743f, -14.226f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(6.338f, -14.226f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(6.338f, -15.292f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.743f, -15.292f, 10.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 19.04f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(12.09f, 19.04f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(12.09f, 13.518f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 13.518f, 10.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-5.9f, 15.235f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-2.018f, 15.235f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 13.518f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-7.84f, 13.518f, 10.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(14.138f, 15.235f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(18.234f, 15.235f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.282f, 13.518f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(12.09f, 13.518f, 10.0f);
	glEnd();

	glPopMatrix();
}

void frontSideFirstFloor() {
	//from rightest point and rigthest xyz area
	//1
	glBegin(GL_POLYGON);
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(7.936f, -11.08f, 0.0f);
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(19.921f, -11.08f, 0.0f);
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(19.921f, -11.08f, 10.0f);
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(7.936f, -11.08f, 10.0f);
	glEnd();

	float frontLine = 0.0f;
	for (int i = 0; i < 34; i++)
	{
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(7.936f, -11.1f, frontLine);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(19.921f, -11.1f, frontLine);
		glEnd();
		frontLine += 0.3f;
	}

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, -11.08f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(19.921f, -11.08f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(19.921f, -11.08f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, -11.08f, 10.0f);
	glEnd();
	//2
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, -11.08f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, -13.6f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, -11.08f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, -11.08f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, -13.6f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, -11.08f, 10.0f);
	glEnd();
	//3
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(5.996f, -15.317f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(5.996f, -15.317f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, -13.6f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.996f, -15.317f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.996f, -15.317f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, -13.6f, 10.0f);
	glEnd();
	//4
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(5.996f, -15.317f, 0.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(2.114f, -15.317f, 0.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(2.114f, -15.317f, 10.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(5.996f, -15.317f, 10.0f);
	glEnd();
	glDisable(GL_BLEND);

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.996f, -15.317f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(2.114f, -15.317f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(2.114f, -15.317f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.996f, -15.317f, 10.0f);
	glEnd();
	//5
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(2.114f, -15.317f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.096f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.096f, -13.6f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(2.114f, -15.317f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(2.114f, -15.317f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.096f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.096f, -13.6f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(2.114f, -15.317f, 10.0f);
	glEnd();
	//6
	//gap1
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.096f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-3.055f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-3.055f, -13.6f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.096f, -13.6f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.096f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-3.055f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-3.055f, -13.6f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.096f, -13.6f, 10.0f);
	glEnd();

	//door
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-3.055f, -13.6f, 7.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-8.818f, -13.6f, 7.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-8.818f, -13.6f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-3.055f, -13.6f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-3.055f, -13.6f, 7.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-8.818f, -13.6f, 7.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-8.818f, -13.6f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-3.055f, -13.6f, 10.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.76f, 0.47f, 0.0f);
	glVertex3f(-3.055f, -13.6f, 0.0f);
	glColor3f(0.76f, 0.47f, 0.0f);
	glVertex3f(-8.818f, -13.6f, 0.0f);
	glColor3f(0.76f, 0.47f, 0.0f);
	glVertex3f(-8.818f, -13.6f, 7.0f);
	glColor3f(0.76f, 0.47f, 0.0f);
	glVertex3f(-3.055f, -13.6f, 7.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-3.055f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-8.818f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-8.818f, -13.6f, 7.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-3.055f, -13.6f, 7.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-5.936f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-5.936f, -13.6f, 7.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-6.859f, -13.811f, 3.259f);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-6.42f, -13.811f, 3.259f);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-6.42f, -13.811f, 3.741f);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-6.859f, -13.811f, 3.741f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-5.457f, -13.811f, 3.259f);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-5.019f, -13.811f, 3.259f);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-5.019f, -13.811f, 3.741f);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-5.457f, -13.811f, 3.741f);
	glEnd();
	//gap 2
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-8.818f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-11.994f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-11.994f, -13.6f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-8.818f, -13.6f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-8.818f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-11.994f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-11.994f, -13.6f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-8.818f, -13.6f, 10.0f);
	glEnd();
	//7
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-11.994f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-14.042f, -15.317f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-14.042f, -15.317f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-11.994f, -13.6f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-11.994f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-14.042f, -15.317f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-14.042f, -15.317f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-11.994f, -13.6f, 10.0f);
	glEnd();
	//8
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-14.042f, -15.317f, 0.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-18.138f, -15.317f, 0.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-18.138f, -15.317f, 10.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-14.042f, -15.317f, 10.0f);
	glEnd();
	glDisable(GL_BLEND);

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-14.042f, -15.317f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-18.138f, -15.317f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-18.138f, -15.317f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-14.042f, -15.317f, 10.0f);
	glEnd();
	//9
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-18.138f, -15.317f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-20.186f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-20.186f, -13.6f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-18.138f, -15.317f, 10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-18.138f, -15.317f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-20.186f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-20.186f, -13.6f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-18.138f, -15.317f, 10.0f);
	glEnd();
}

void frontSideSecondFloor() {
	//from rightest point and rigthest xyz area
	//1
	//gap 1
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, -11.08f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(9.282f, -11.08f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(9.282f, -11.08f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, -11.08f, 10.0f);
	glEnd();

	//window
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(9.282f, -11.08f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(18.576f, -11.08f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(18.576f, -11.08f, 1.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(9.282f, -11.08f, 1.0f);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(9.282f, -11.08f, 1.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(18.576f, -11.08f, 1.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(18.576f, -11.08f, 2.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(9.282f, -11.08f, 2.0f);
	glEnd();
	glDisable(GL_BLEND);

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(9.282f, -11.08f, 2.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(18.576f, -11.08f, 2.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(18.576f, -11.08f, 3.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(9.282f, -11.08f, 3.0f);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(9.282f, -11.08f, 3.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(18.576f, -11.08f, 3.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(18.576f, -11.08f, 4.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(9.282f, -11.08f, 4.0f);
	glEnd();
	glDisable(GL_BLEND);

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(9.282f, -11.08f, 4.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(18.576f, -11.08f, 4.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(18.576f, -11.08f, 5.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(9.282f, -11.08f, 5.0f);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(9.282f, -11.08f, 5.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(18.576f, -11.08f, 5.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(18.576f, -11.08f, 6.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(9.282f, -11.08f, 6.0f);
	glEnd();
	glDisable(GL_BLEND);

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(9.282f, -11.08f, 6.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(18.576f, -11.08f, 6.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(18.576f, -11.08f, 7.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(9.282f, -11.08f, 7.0f);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(9.282f, -11.08f, 7.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(18.576f, -11.08f, 7.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(18.576f, -11.08f, 8.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(9.282f, -11.08f, 8.0f);
	glEnd();
	glDisable(GL_BLEND);

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(9.282f, -11.08f, 8.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(18.576f, -11.08f, 8.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(18.576f, -11.08f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(9.282f, -11.08f, 10.0f);
	glEnd();

	////gap 2
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(18.576f, -11.08f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(19.921f, -11.08f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(19.921f, -11.08f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(18.576f, -11.08f, 10.0f);
	glEnd();
	//2
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, -11.08f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, -13.6f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, -11.08f, 10.0f);
	glEnd();
	//3
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(5.996f, -15.317f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(5.996f, -15.317f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(7.936f, -13.6f, 10.0f);
	glEnd();
	//4
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(5.996f, -15.317f, 0.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(2.114f, -15.317f, 0.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(2.114f, -15.317f, 10.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(5.996f, -15.317f, 10.0f);
	glEnd();
	glDisable(GL_BLEND);
	//5
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(2.114f, -15.317f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.096f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.096f, -13.6f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(2.114f, -15.317f, 10.0f);
	glEnd();
	//6
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.096f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.096f, -19.123f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.096f, -19.123f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.096f, -13.6f, 10.0f);
	glEnd();

	float frontLine = 0.0f;
	for (int i = 0; i < 34; i++)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.098f, -13.6f, frontLine);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.098f, -19.123f, frontLine);
		glEnd();
		frontLine += 0.3f;
	}
	//7
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.096f, -19.123f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-11.994f, -19.123f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-11.994f, -19.123f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.096f, -19.123f, 10.0f);
	glEnd();

	float frontLine2 = 0.0f;
	for (int i = 0; i < 34; i++)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.096f, -19.125f, frontLine2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-11.994f, -19.125f, frontLine2);
		glEnd();
		frontLine2 += 0.3f;
	}
	//8
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-11.994f, -19.123f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-11.994f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-11.994f, -13.6f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-11.994f, -19.123f, 10.0f);
	glEnd();

	float frontLine3 = 0.0f;
	for (int i = 0; i < 34; i++)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-11.996f, -19.123f, frontLine3);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-11.996f, -13.6f, frontLine3);
		glEnd();
		frontLine3 += 0.3f;
	}
	//9
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-11.994f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-14.042f, -15.317f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-14.042f, -15.317f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-11.994f, -13.6f, 10.0f);
	glEnd();
	//10
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-14.042f, -15.317f, 0.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-18.138f, -15.317f, 0.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-18.138f, -15.317f, 10.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-14.042f, -15.317f, 10.0f);
	glEnd();
	glDisable(GL_BLEND);
	//11
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-18.138f, -15.317f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-20.186f, -13.6f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-20.186f, -13.6f, 10.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-18.138f, -15.317f, 10.0f);
	glEnd();

	//from rightest point and rigthest xyz area
	//1
	//gap 1
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, -11.08f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, -11.08f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, -11.08f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, -11.08f, 10.0f);
	glEnd();

	//window
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, -11.08f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, -11.08f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, -11.08f, 1.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, -11.08f, 1.0f);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, -11.08f, 1.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, -11.08f, 1.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, -11.08f, 2.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, -11.08f, 2.0f);
	glEnd();
	glDisable(GL_BLEND);

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, -11.08f, 2.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, -11.08f, 2.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, -11.08f, 3.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, -11.08f, 3.0f);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, -11.08f, 3.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, -11.08f, 3.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, -11.08f, 4.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, -11.08f, 4.0f);
	glEnd();
	glDisable(GL_BLEND);

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, -11.08f, 4.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, -11.08f, 4.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, -11.08f, 5.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, -11.08f, 5.0f);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, -11.08f, 5.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, -11.08f, 5.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, -11.08f, 6.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, -11.08f, 6.0f);
	glEnd();
	glDisable(GL_BLEND);

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, -11.08f, 6.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, -11.08f, 6.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, -11.08f, 7.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, -11.08f, 7.0f);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, -11.08f, 7.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, -11.08f, 7.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, -11.08f, 8.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, -11.08f, 8.0f);
	glEnd();
	glDisable(GL_BLEND);

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, -11.08f, 8.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, -11.08f, 8.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, -11.08f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.282f, -11.08f, 10.0f);
	glEnd();

	////gap 2
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, -11.08f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(19.921f, -11.08f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(19.921f, -11.08f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(18.576f, -11.08f, 10.0f);
	glEnd();
	//2
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, -11.08f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, -13.6f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, -11.08f, 10.0f);
	glEnd();
	//3
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.996f, -15.317f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.996f, -15.317f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.936f, -13.6f, 10.0f);
	glEnd();
	//4
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.996f, -15.317f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(2.114f, -15.317f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(2.114f, -15.317f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(5.996f, -15.317f, 10.0f);
	glEnd();
	glDisable(GL_BLEND);
	//5
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(2.114f, -15.317f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.096f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.096f, -13.6f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(2.114f, -15.317f, 10.0f);
	glEnd();
	//6
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.096f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.096f, -19.123f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.096f, -19.123f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.096f, -13.6f, 10.0f);
	glEnd();

	float frontLineL = 0.0f;
	for (int i = 0; i < 34; i++)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.098f, -13.6f, frontLineL);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.098f, -19.123f, frontLineL);
		glEnd();
		frontLineL += 0.3f;
	}
	//7
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.096f, -19.123f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-11.994f, -19.123f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-11.994f, -19.123f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.096f, -19.123f, 10.0f);
	glEnd();

	float frontLineL2 = 0.0f;
	for (int i = 0; i < 34; i++)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.096f, -19.125f, frontLineL2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-11.994f, -19.125f, frontLineL2);
		glEnd();
		frontLineL2 += 0.3f;
	}
	//8
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-11.994f, -19.123f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-11.994f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-11.994f, -13.6f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-11.994f, -19.123f, 10.0f);
	glEnd();

	float frontLineL3 = 0.0f;
	for (int i = 0; i < 34; i++)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-11.996f, -19.123f, frontLineL3);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-11.996f, -13.6f, frontLineL3);
		glEnd();
		frontLineL3 += 0.3f;
	}
	//9
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-11.994f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-14.042f, -15.317f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-14.042f, -15.317f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-11.994f, -13.6f, 10.0f);
	glEnd();
	//10
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-14.042f, -15.317f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-18.138f, -15.317f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-18.138f, -15.317f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-14.042f, -15.317f, 10.0f);
	glEnd();
	glDisable(GL_BLEND);
	//11
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-18.138f, -15.317f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-20.186f, -13.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-20.186f, -13.6f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-18.138f, -15.317f, 10.0f);
	glEnd();
}

void leftFence() {
	//main fence
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-25.0f, 25.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-23.5f, 25.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-23.5f, -25.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-25.0f, -25.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-23.5f, 25.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-23.5f, -25.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-23.5f, -25.0f, 3.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-23.5f, 25.0f, 3.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-25.0f, 25.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-23.5f, 25.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-23.5f, 25.0f, 3.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-25.0f, 25.0f, 3.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-23.5f, -25.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-25.0f, -25.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-25.0f, -25.0f, 3.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-23.5f, -25.0f, 3.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-25.0f, -25.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-25.0f, 25.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-25.0f, 25.0f, 3.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-25.0f, -25.0f, 3.0f);
	glEnd();

	//secondary fence (top)
	glBegin(GL_POLYGON);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-25.25f, 25.25f, 2.5f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-23.25f, 25.25f, 2.5f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-23.25f, -25.25f, 2.5f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-25.25f, -25.25f, 2.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-25.25f, 25.25f, 2.5f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-23.25f, 25.25f, 2.5f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-23.25f, 25.25f, 3.0f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-25.25f, 25.25f, 3.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-23.25f, 25.25f, 2.5f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-23.25f, -25.25f, 2.5f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-23.25f, -25.25f, 3.0f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-23.25f, 25.25f, 3.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-23.25f, -25.25f, 2.5f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-25.25f, -25.25f, 2.5f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-25.25f, -25.25f, 3.0f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-23.25f, -25.25f, 3.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-25.25f, -25.25f, 2.5f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-25.25f, 25.25f, 2.5f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-25.25f, 25.25f, 3.0f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-25.25f, -25.25f, 3.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-25.25f, 25.25f, 3.0f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-23.25f, 25.25f, 3.0f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-23.25f, -25.25f, 3.0f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-25.25f, -25.25f, 3.0f);
	glEnd();
}

void topFence() {
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
	glTranslatef(48.5f, 0.0f, 0.0f);
	leftFence();
	glPopMatrix();
}

void bottomFence() {
	glPushMatrix();
	glScalef(0.25f, 1.0f, 1.0f);
	glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.0f, 75.0f, 0.0f);
	leftFence();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.55f, 1.0f, 1.0f);
	glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.0f, -20.0f, 0.0f);
	leftFence();
	glPopMatrix();
}

void rightFence() {
	glPushMatrix();
	glTranslatef(48.5f, 0.0f, 0.0f);
	leftFence();
	glPopMatrix();
}

void secondFloor() {
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 10.0f);
	bottomSide();
	rightSide();
	backSide();
	leftSide();
	topSide();
	frontSideSecondFloor();
	glPopMatrix();
}

void firstFloor() {
	bottomSideFirstFloor();
	rightSide();
	leftSide();
	topSide();
	backSideFirstFloor();
	frontSideFirstFloor();
}

void middle() {
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, 18.403f, 9.5f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, 18.403f, 9.5f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, -19.123f, 9.5f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, -19.123f, 9.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, 18.403f, 10.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, 18.403f, 10.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, -19.123f, 10.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, -19.123f, 10.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, 18.403f, 9.5f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, 18.403f, 9.5f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, 18.403f, 10.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, 18.403f, 10.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, 18.403f, 9.5f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, -19.123f, 9.5f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, -19.123f, 10.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, 18.403f, 10.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, -19.123f, 9.5f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, -19.123f, 9.5f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, -19.123f, 10.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, -19.123f, 10.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, -19.123f, 9.5f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, 18.403f, 9.5f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, 18.403f, 10.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, -19.123f, 10.0f);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-6.242f, 17.3f, 10.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(19.921f, 17.3f, 10.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(19.921f, 17.3f, 12.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(-6.242f, 17.3f, 12.0f);
	glEnd();
	glDisable(GL_BLEND);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(19.921f, 17.3f, 10.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(19.921f, 6.017f, 10.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(19.921f, 6.017f, 12.0f);
	glColor4f(0.498f, 0.858f, 1.0f, 0.6f);
	glVertex3f(19.921f, 17.3f, 12.0f);
	glEnd();
	glDisable(GL_BLEND);
}

void roof() {
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, 18.403f, 20.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, 18.403f, 20.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, -19.123f, 20.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, -19.123f, 20.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, 18.403f, 20.5f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, 18.403f, 20.5f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, -19.123f, 20.5f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, -19.123f, 20.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, 18.403f, 20.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, 18.403f, 20.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, 18.403f, 20.5f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, 18.403f, 20.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, 18.403f, 20.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, -19.123f, 20.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, -19.123f, 20.5f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, 18.403f, 20.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, -19.123f, 20.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, -19.123f, 20.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, -19.123f, 20.5f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.089f, -19.123f, 20.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, -19.123f, 20.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, 18.403f, 20.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, 18.403f, 20.5f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-21.354f, -19.123f, 20.5f);
	glEnd();
}

void pilarsFirstFloor() {
	createPilars(-10.92f, -18.098, 0.0f, 0.645f, 100, 10.0f, 0.9f, 0.9f, 0.9f);
	createPilars(-0.978f, -18.098, 0.0f, 0.645f, 100, 10.0f, 0.9f, 0.9f, 0.9f);

	createPilars(-19.23f, -18.098, 0.0f, 0.645f, 100, 10.0f, 0.9f, 0.9f, 0.9f);
	createPilars(18.965f, -18.098, 0.0f, 0.645f, 100, 10.0f, 0.9f, 0.9f, 0.9f);

	createPilars(-19.23f, 17.378, 0.0f, 0.645f, 100, 10.0f, 0.9f, 0.9f, 0.9f);
	createPilars(18.965f, 17.378, 0.0f, 0.645f, 100, 10.0f, 0.9f, 0.9f, 0.9f);
}

void pilarsSecondFloor() {
	createPilars(-19.23f, -18.098, 10.0f, 0.645f, 100, 10.0f, 0.9f, 0.9f, 0.9f);
	createPilars(18.965f, -18.098, 10.0f, 0.645f, 100, 10.0f, 0.9f, 0.9f, 0.9f);

	createPilars(-19.23f, 17.378, 10.0f, 0.645f, 100, 10.0f, 0.9f, 0.9f, 0.9f);
	createPilars(18.965f, 17.378, 10.0f, 0.645f, 100, 10.0f, 0.9f, 0.9f, 0.9f);
}

void tableStand() {
	//stand
	glBegin(GL_POLYGON);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, 3.437f, 0.01f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(17.546f, 3.437f, 0.01f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(17.546f, 2.71f, 0.01f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, 2.71f, 0.01f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, 3.437f, 3.5f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(17.546f, 3.437f, 3.5f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(17.546f, 2.71f, 3.5f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, 2.71f, 3.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, 3.437f, 0.01f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(17.546f, 3.437f, 0.01f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(17.546f, 3.437f, 3.5f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, 3.437f, 3.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(17.546f, 3.437f, 0.01f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(17.546f, 2.71f, 0.01f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(17.546f, 2.71f, 3.5f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(17.546f, 3.437f, 3.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(17.546f, 2.71f, 0.01f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, 2.71f, 0.01f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, 2.71f, 3.5f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(17.546f, 2.71f, 3.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, 2.71f, 0.01f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, 3.437f, 0.01f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, 3.437f, 3.5f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, 2.71f, 3.5f);
	glEnd();
}

void tableTop() {
	glBegin(GL_POLYGON);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, 3.437f, 3.5f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(19.582f, 3.437f, 3.5f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(19.582f, -6.926f, 3.5f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, -6.926f, 3.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, 3.437f, 3.0f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(19.582f, 3.437f, 3.0f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(19.582f, -6.926f, 3.0f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, -6.926f, 3.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, 3.437f, 3.0f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(19.582f, 3.437f, 3.0f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(19.582f, 3.437f, 3.5f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, 3.437f, 3.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(19.582f, 3.437f, 3.0f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(19.582f, -6.926f, 3.0f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(19.582f, -6.926f, 3.5f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(19.582f, 3.437f, 3.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(19.582f, -6.926f, 3.0f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, -6.926f, 3.0f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, -6.926f, 3.5f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(19.582f, -6.926f, 3.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, -6.926f, 3.0f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, 3.437f, 3.0f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, 3.437f, 3.5f);
	glColor3f((102.0f / 255.0f), (63.0f / 255.0f), (0.0f / 255.0f));
	glVertex3f(16.819f, -6.926f, 3.5f);
	glEnd();
}

void table() {
	float tblTopZ = 0.0f;
	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glTranslatef(0.0f, 0.0f, tblTopZ);
		tableTop();
		glPopMatrix();
		tblTopZ -= 1.0f;
	}

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	tableStand();
	glPopMatrix();

	glPushMatrix();
	glTranslatef((19.582f - 17.546f), 0.0f, 0.0f);
	tableStand();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, (-6.198f - 3.437f), 0.0f);
	tableStand();
	glPopMatrix();

	glPushMatrix();
	glTranslatef((18.855f - 16.819), (-6.198f - 3.437f), 0.0f);
	tableStand();
	glPopMatrix();
}

void tv() {
	//stand
	glBegin(GL_POLYGON);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.007f, -0.917f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -0.917f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -2.571f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.007f, -2.571f, 3.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.007f, -0.917f, 3.7f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -0.917f, 3.7f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -2.571f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.007f, -2.571f, 3.7f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.007f, -0.917f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -0.917f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -0.917f, 3.7f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.007f, -0.917f, 3.7f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -0.917f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -2.571f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -2.571f, 3.7f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -0.917f, 3.7f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -2.571f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.007f, -2.571f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.007f, -2.571f, 3.7f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -2.571f, 3.7f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.007f, -2.571f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.007f, -0.917f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.007f, -0.917f, 3.7f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.007f, -2.571f, 3.7f);
	glEnd();

	//screen
	glBegin(GL_POLYGON);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.393f, 0.639f, 4.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, 0.639f, 4.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -4.127f, 4.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.393f, -4.127f, 4.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.393f, 0.639f, 6.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, 0.639f, 6.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -4.127f, 6.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.393f, -4.127f, 6.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.393f, 0.639f, 4.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, 0.639f, 4.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, 0.639f, 6.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.393f, 0.639f, 6.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, 0.639f, 4.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -4.127f, 4.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -4.127f, 6.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, 0.639f, 6.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -4.127f, 4.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.393f, -4.127f, 4.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.393f, -4.127f, 6.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -4.127f, 6.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.393f, -4.127f, 4.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.393f, 0.639f, 4.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.393f, 0.639f, 6.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.393f, -4.127f, 6.0f);
	glEnd();

	//neck
	glBegin(GL_POLYGON);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -1.54f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(19.187f, -1.54f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(19.187f, -1.948f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -1.948f, 3.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -1.54f, 5.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(19.187f, -1.54f, 5.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(19.187f, -1.948f, 5.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -1.948f, 5.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -1.54f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(19.187f, -1.54f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(19.187f, -1.54f, 5.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -1.54f, 5.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(19.187f, -1.54f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(19.187f, -1.948f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(19.187f, -1.948f, 5.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(19.187f, -1.54f, 5.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(19.187f, -1.948f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -1.948f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -1.948f, 5.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(19.187f, -1.948f, 5.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -1.948f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -1.54f, 3.5f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -1.54f, 5.0f);
	glColor3f((18.0f / 255.0f), (18.0f / 255.0f), (18.0f / 255.0f));
	glVertex3f(18.779f, -1.948f, 5.0f);
	glEnd();
}

void sofa() {
	//seat
	glBegin(GL_POLYGON);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.038f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.038f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, -4.526f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, -4.526f, 0.01f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.038f, 2.0f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.038f, 2.0f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, -4.526f, 2.0f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, -4.526f, 2.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.038f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.038f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.038f, 2.0f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.038f, 2.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.038f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, -4.526f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, -4.526f, 2.0f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.038f, 2.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, -4.526f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, -4.526f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, -4.526f, 2.0f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, -4.526f, 2.0f);
	glEnd();

	//armrest1
	glBegin(GL_POLYGON);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.938f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.938f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.038f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.038f, 0.01f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.938f, 2.5f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.938f, 2.5f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.038f, 2.5f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.038f, 2.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.938f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.938f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.938f, 2.5f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.938f, 2.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.938f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.038f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.038f, 2.5f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.938f, 2.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.038f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.038f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.038f, 2.5f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.038f, 2.5f);
	glEnd();

	//armrest2
	glPushMatrix();
	glTranslatef(0.0f, (-4.526 - 1.938), 0.0f);
	glBegin(GL_POLYGON);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.938f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.938f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.038f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.038f, 0.01f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.938f, 2.5f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.938f, 2.5f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.038f, 2.5f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.038f, 2.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.938f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.938f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.938f, 2.5f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.938f, 2.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.938f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.038f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.038f, 2.5f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.938f, 2.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.038f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.038f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.038f, 2.5f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(12.031f, 1.038f, 2.5f);
	glEnd();
	glPopMatrix();

	//backrest
	glBegin(GL_POLYGON);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.418f, 1.938f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(10.3f, 1.938f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(10.3f, -5.426f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.418f, -5.426f, 0.01f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(8.977f, 1.938f, 4.0f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.938f, 4.0f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, -5.426f, 4.0f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(8.977f, -5.426f, 4.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(10.3f, 1.938f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(10.3f, -5.426f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, -5.426f, 4.0f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.938f, 4.0f);
	glEnd();

	glPushMatrix();
	glTranslatef((8.977f - 9.859f), 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(10.3f, 1.938f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(10.3f, -5.426f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, -5.426f, 4.0f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, 1.938f, 4.0f);
	glEnd();
	glPopMatrix();

	glBegin(GL_POLYGON);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(10.3f, -5.426f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.418f, -5.426f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(8.977f, -5.426f, 4.0f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, -5.426f, 4.0f);
	glEnd();

	glPushMatrix();
	glTranslatef(0.0f, (1.938f + 5.426), 0.0f);
	glBegin(GL_POLYGON);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(10.3f, -5.426f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.418f, -5.426f, 0.01f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(8.977f, -5.426f, 4.0f);
	glColor3f((199.0f / 255.0f), (160.0f / 255.0f), (98.0f / 255.0f));
	glVertex3f(9.859f, -5.426f, 4.0f);
	glEnd();
	glPopMatrix();
}

void house() {
	terrain();
	tv();
	sofa();
	table();
	leftFence();
	topFence();
	rightFence();
	bottomFence();
	roof();
	firstFloor();
	secondFloor();
	middle();
	pilarsSecondFloor();
	pilarsFirstFloor();
	randomGrass();
}

void enable(void) {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
}

void display(void) {
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
    glClear(GL_COLOR_BUFFER_BIT);

	glClearColor(0.0, 0.7, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	enable();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -cRadius);
	glRotatef(xrot, 1.0, 0.0, 0.0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidCube(0.1);

	glRotatef(yrot, 0.0, 1.0, 0.0);
	glTranslated(-xpos, -ypos, -zpos);
	glColor3f(1.0f, 1.0f, 1.0f);
	axis();
	glPushMatrix();
	glRotatef(270.0f, 90.0f, 0.0f, 1.0f);
	house();
	glPopMatrix();

	glutSwapBuffers();
	angle++;
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	gluPerspective(60, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);

}

void keyboard(unsigned char key,int x, int y)
{
    switch(key)
    {

    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3.0, 0.0, 3.0);
        break;
    case '7':
        glTranslatef(0.0, 3.0, 0.0);
        break;
    case '9':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '4':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    display();

}
void idle(){
    if(!mouseDown){
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
    mouseDown = false;
}

void mouseMotion(int x, int y){
    if(mouseDown){
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Joseph Triwin Subarja – 672018094");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);

	glutPassiveMotionFunc(mouseMotion());

	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
