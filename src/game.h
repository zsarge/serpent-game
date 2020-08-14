#ifndef GAME_H
#define GAME_H

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <iostream>
#include <vector>

#include "constants.h"

struct segment {
    int X;  // segment X position
    int Y;  // segment Y position
};

class Snake {
   private:
    // REVIEW - consider making static?
    std::vector<segment> body;

   public:
    segment GetSegment(int index);
    void SetSegment(int index, int X, int Y);
    int GetLength();
    void Grow();
    void Restart();
    Snake();   // constructor function
    ~Snake();  // deconstructor function
};

class Food {
   private:
    segment piece;

   public:
    void MoveFood();
    segment GetFood();
    Food();
};

int RandomNumber(int start, int stop);
void SendRulesToOutputStream();
void drawSquare(int x, int y);
void drawGrid();
void WrapSnake();
void MoveSnake();
void MoveHead();
void CheckSnake();
void UpdateSnake();
void ApplyFoodRules();
void DrawAndUpdateGame();

#endif