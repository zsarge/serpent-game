#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <GL/gl.h>
#include <GL/glut.h>

#include "constants.h"
#include "game.h"

void display();
void reshape(int width, int height);
void timer(int);
void keypress(unsigned char key, int, int);

#endif