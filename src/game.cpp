#include "game.h"

// Variables are used in DrawAndUpdateSnake()
int SnakeX = SnakeConstants::START_X;
int SnakeY = SnakeConstants::START_Y;
short SnakeDirection = SnakeConstants::RIGHT;

void drawSquare(int x, int y) {  // ANCHOR - drawSquare
    glLineWidth(10.0);

    // 2f takes two floating points
    // STUB - this will need to be replaced when I switch to 3D

    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x + 1, y);
    glVertex2f(x + 1, y + 1);
    glVertex2f(x, y + 1);
    glEnd();

    glFlush();
}

// REVIEW - should rename to fit naming conventions? Or is everything else wrong?
void drawGrid() {
    for (float x = 0; x < Constants::ROWS; x++) {
        for (float y = 0; y < Constants::COLUMNS; y++) {
            glColor3f(GridColor::RED, GridColor::GREEN, GridColor::BLUE);
            drawSquare(x, y);
        }
    }
}

void DrawAndUpdateSnake() {
    if (SnakeDirection == SnakeConstants::UP) {
        SnakeY++;
    } else if (SnakeDirection == SnakeConstants::DOWN) {
        SnakeY--;
    } else if (SnakeDirection == SnakeConstants::RIGHT) {
        SnakeX++;
    } else if (SnakeDirection == SnakeConstants::LEFT) {
        SnakeX--;
    }

    glColor3f(1, 0, 0);  // Set the colour to red
    glRectd(SnakeX, SnakeY, SnakeX + 1, SnakeY + 1);
}