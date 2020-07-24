#include "game.h"

// Variables are used in DrawAndUpdateSnake()
int SnakeX = SnakeConstants::START_X;
int SnakeY = SnakeConstants::START_Y;
short snakeDirection = SnakeConstants::RIGHT;
bool gameOver = false;

void SendRulesToOutputStream() {
    std::cout << "Hello. This is a serpent game by Zack Sargent made\n";
    std::cout << "to learn the basics of graphics in C++.\n\n";
    std::cout << "Instructions:\n";
    std::cout << "\tUse WASD to control the serpent.\n";
    std::cout << "\tDo not run into yourself or the walls.\n";
    std::cout.flush();
}

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

// REVIEW - should rename to fit naming conventions? Or is everything else
// wrong?
void drawGrid() {
    for (float x = 0; x < Constants::ROWS; x++) {
        for (float y = 0; y < Constants::COLUMNS; y++) {
            glColor3f(GridColor::RED, GridColor::GREEN, GridColor::BLUE);
            drawSquare(x, y);
        }
    }
}

void DrawAndUpdateSnake() {
    UpdateSnake();

    glColor3f(1, 0, 0);  // Set the colour to red
    glRectd(SnakeX, SnakeY, SnakeX + 1, SnakeY + 1);
}

void UpdateSnake() {
    // Check which direction the snake is moving,
    // and move it in that direction.
    switch (snakeDirection) {
        case SnakeConstants::UP:
            SnakeY++;
            break;
        case SnakeConstants::DOWN:
            SnakeY--;
            break;
        case SnakeConstants::RIGHT:
            SnakeX++;
            break;
        case SnakeConstants::LEFT:
            SnakeX--;
            break;
        default:
            break;
    }

    // Make sure the serpent doesn't leave the screen:
    if (SnakeX == 0 || SnakeX == Constants::COLUMNS || SnakeY == 0 ||
        SnakeY == Constants::ROWS) {
        gameOver = true;
    }
}