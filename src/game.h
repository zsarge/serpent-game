#ifndef GAME_H
#define GAME_H

#include <GL/gl.h>
#include <GL/glut.h>

#include <iostream>
#include <vector>

#include "constants.h"

struct segment {
    int X;  // segment X position
    int Y;  // segment Y position
};

class Snake {
   private:
    std::vector<segment> body;

   public:
    segment GetSegment(int index);
    void SetSegment(int index, int X, int Y);
    int GetLength();
    Snake(); // constructor function
    ~Snake(); // deconstructor function
};

void SendRulesToOutputStream();
void drawSquare(int x, int y);
void drawGrid();
void WrapSnake();
void MoveSnake();
void MoveHead();
void UpdateSnake();
void DrawAndUpdateSnake();

#endif