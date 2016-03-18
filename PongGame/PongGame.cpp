// PongGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <sstream>
#include <math.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include "GL/freeglut.h"
#pragma comment(lib, "OpenGL32.lib")
//window size and update rate
int width = 500;
int height = 200;
int interval = 1000 / 60;

//score
int score_left = 0;
int score_right = 0;
std::string int2str(int  x)
{
	//converts int to string
	std::stringstream ss;
	ss << x;
	return ss.str();
}
//draws text on screen
void drawText(float x, float y, std::string text)
{
	glRasterPos2f(x, y);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char*)text.c_str());
}
//draws the board
void draw()
{
	//clear (clears the board so it can redraw it.)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//Draw the scene
	//draw score
	drawText(width / 2 - 10, height - 15, int2str(score_left) + ":" + int2str(score_right));
	//swap buffers
	glutSwapBuffers();
}

//updates the board
void update(int value)
{
	//call update() again in 'interval' milliseconds
	glutTimerFunc(interval, update, 0);

	//redisplay frame
	glutPostRedisplay();

}

void enable2D(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, width, 0.0f, height, 0.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
//argc means argument count and argv means argument vector. 
//They take program arguments from the command line
int main(int argc, char **argv)
{
	//initialize opengl using the opengl utility kit(glut)
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("Benjamin's Pong");

	//register callback functions
	glutDisplayFunc(draw);
	glutTimerFunc(interval, update, 0);

	//setup scene to 2d mode and set draw color to white
	enable2D(width, height);
	glColor3f(1.0f, 1.0f, 1.0f);

	//start the whole thing
	glutMainLoop();
    return 0;
}

