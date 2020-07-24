#ifndef GAME_H
#define GAME_H

#include <GL/gl.h>
#include <GL/glut.h>

#include <iostream>

#include "constants.h"

void SendRulesToOutputStream();
void drawSquare(int x, int y);
void drawGrid();
void UpdateSnake();
void DrawAndUpdateSnake();

#endif