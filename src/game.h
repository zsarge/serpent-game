#ifndef GAME_H
#define GAME_H

#include <GL/gl.h>
#include <GL/glut.h>

#include <iostream>
#include <vector>

#include "constants.h"

struct segment {
    int segmentX;
    int segmentY;
};

class Snake {
   private:
    std::vector<segment> body;

   public:
    Snake();
};

void SendRulesToOutputStream();
void drawSquare(int x, int y);
void drawGrid();
void WrapSnake();
void MoveSnake();
void UpdateSnake();
void DrawAndUpdateSnake();

#endif