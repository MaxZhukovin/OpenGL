
#include <iostream>
#include <GL\glut.h>
#include <list>;
#include"TriangleInfo.h";
#include"VertexInfo.h";
#include <Windows.h>;
#include <string>;
#include "Figure.h";
#include "Geometry.h";
#include "Octahedron.h";
#include "Sphere.h";
#include <thread>;
#include <chrono>;
#define M_PI 3.14159265358979323846
#include"Lamp.h";

using namespace std;
void Init();
void Display();
void KeyboardDown(unsigned char,int x,int y);
void timerCB(int millisec);
void mouse(int button, int stat, int x, int y);
void mouseMotionCB(int x, int y);

void *font = GLUT_BITMAP_HELVETICA_12;

list<Figure*> Figures;
list<Lamp*> lamps;

bool mouseLeftDown;
bool mouseRightDown;
bool mouseMiddleDown;
float mouseX, mouseY;
float cameraAngleX;
float cameraAngleY;
float cameraDistance;



double rotate_y = 0;
double rotate_x = 0;
double rotate_z = 0;

int a = 0;
const int   TEXT_HEIGHT = 13;
const int   SCREEN_HEIGHT = 700;
const float LightCahngeCoef = 0.05;

int main(int argc, char **argv)
{
	//creating new lamp
	Lamp *lamp1 = new Lamp(0.7, new VertexInfo(10, 0, 0));
	lamp1->SetColor(1, 1, 1);

	//adding lamp to scene
	lamps.push_back(lamp1);

	//creating & adding new sphere
	Sphere *sphere = new Sphere();
	sphere->SetSphere(new VertexInfo(0, 0, 0), 0.5, 5);
	Figure *f = sphere;
	Figures.push_back(f);

	//OpenGL initialize functions
	glutInit(&argc, argv);
	glutInitWindowSize(700, 700);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("Sphere");
	glEnable(GL_DEPTH_TEST);
	Init();
	glutDisplayFunc(Display);
	glutTimerFunc(33, timerCB, 33);
	glutKeyboardFunc(KeyboardDown);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotionCB);
	glutMainLoop();
}

void KeyboardDown(unsigned char key,int x ,int y)
{
	if (key == '1') 
	{
		for (Lamp *l : lamps) {
			
			l->SetLightItensity(l->GetLightItensity() + l->GetLightItensity() * LightCahngeCoef);
		}
	}
	else if(key == '2')
	{
		for (Lamp *l : lamps) {
			l->SetLightItensity(l->GetLightItensity() - l->GetLightItensity() * LightCahngeCoef);
		}
	}

	glutPostRedisplay();
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glLoadIdentity();

	// tramsform camera
	glTranslatef(0, 0, -cameraDistance);
	glRotatef(cameraAngleX, -1, 0, 0);   // pitch
	glRotatef(cameraAngleY, 0, -1, 0);   // heading

	glRotatef(-90, 1, 0, 0);	

	float Color1 = (0.6 * 5);
	float Color2 = (0.6 * 5);
	float Color3 = (0.1 * 5);	

	glBegin(GL_LINES);
	glColor3f(0, 0, 5);
	glVertex3f(0, 0, 0);
	glVertex3f(0,0,5);

	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(5, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 5, 0);
	glEnd();

	float color[4] = { 0.5, 0.5, 0.5, 1 };

	
	for (Figure *f : Figures)
	{
		float light = 0;
		for (TriangleInfo t : f->GetTriangles())
		{

			float Rlamp = 0;
			float Glamp = 0;
			float Blamp = 0;

			float k = 0;
			for (Lamp *l : lamps) {
				
				float k1 = l->GetLightCoefitient(t, f->GetCenter());
				if (k1 >= 0) {
					k += k1;
				}

			}

			for (Lamp *l : lamps) {
				float k1 = l->GetLightCoefitient(t, f->GetCenter()) / k;
				if (k1 < 0)
				{
					k1 = 0;
				}

				if (l->GetColor().GetXPosition() >= 0) {
					Rlamp += l->GetColor().GetXPosition() * k1;
				}
				if (l->GetColor().GetYPosition() >= 0) {
					Glamp += l->GetColor().GetYPosition() * k1;
				}
				if (l->GetColor().GetZPosition() >= 0) {
					Blamp += l->GetColor().GetZPosition() * k1;
				}

			}
			
			light += k;
			float RColor = Color1 * k * Rlamp;
			float GColor = Color2 * k * Glamp;
			float BColor = Color3 * k * Blamp;

			glBegin(GL_TRIANGLES);
			glColor3f(RColor, GColor, BColor);
			glVertex3f(t.GetVertex1().GetXPosition(), t.GetVertex1().GetYPosition(), t.GetVertex1().GetZPosition());
			glVertex3f(t.GetVertex2().GetXPosition(), t.GetVertex2().GetYPosition(), t.GetVertex2().GetZPosition());
			glVertex3f(t.GetVertex3().GetXPosition(), t.GetVertex3().GetYPosition(), t.GetVertex3().GetZPosition());
			glEnd();
		}
	}



	Color1 = (0.160 * 5);
	Color2 = (0.256 * 5);
	Color3 = (0.150 * 5);

	glPopMatrix();
	// Reset transformations
	glFlush();
	glutSwapBuffers();
}

void Init()
{
	glClearColor(0.1333, 0.1333, 0.1333, 0.0);
}

void mouse(int button, int state, int x, int y)
{
	mouseX = x;
	mouseY = y;

	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			mouseLeftDown = true;
		}
		else if (state == GLUT_UP)
			mouseLeftDown = false;
	}

	else if (button == GLUT_MIDDLE_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			mouseMiddleDown = true;
		}
		else if (state == GLUT_UP)
			mouseMiddleDown = false;
	}

	else if (button == 3) 
	{
		for (Figure *var: Figures)
		{
			var->AugmentScale(0.01);
		}
	}

	else if (button == 4) 
	{
		for (Figure* var : Figures) 
		{
			var->DecreaseScale(0.01);                 
		}
	}
}

void mouseMotionCB(int x, int y)
{
	if (mouseLeftDown)
	{
		cameraAngleY += (x - mouseX);
		cameraAngleX += (y - mouseY);
		mouseX = x;
		mouseY = y;
	}
	if (mouseRightDown)
	{
		cameraDistance -= (y - mouseY) * 0.2f;
		mouseY = y;
	}
}

void timerCB(int millisec)
{
	glutTimerFunc(millisec, timerCB, millisec);
	
	glutPostRedisplay();
}
