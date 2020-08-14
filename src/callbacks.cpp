#include "callbacks.h"

extern short snakeDirection;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    DrawAndUpdateGame();
    glutSwapBuffers();
}

void reshape(int width, int height) {  // ANCHOR - reshape SIZE
    glViewport(Constants::SCREEN_POS_X, Constants::SCREEN_POS_Y,
               Constants::VIEWPORT_SCALE, Constants::VIEWPORT_SCALE);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // REVIEW - perspective
    // I'm currently making this game in 2D.
    // In the future, I plan to switch to a 3D perspective.
    glOrtho(0, Constants::ROWS, 0, Constants::COLUMNS, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
}

void timer(int) {
    glutPostRedisplay();
    glutTimerFunc(500 / Constants::FPS, timer, 0);
}

void keypress(unsigned char key, int, int) {
    // note that the serpent should not turn 180 degrees
    switch (key) {
        case 'w':
            if (snakeDirection != SnakeConstants::DOWN) {
                snakeDirection = SnakeConstants::UP;
            }
            break;
        case 's':
            if (snakeDirection != SnakeConstants::UP) {
                snakeDirection = SnakeConstants::DOWN;
            }
            break;
        case 'd':
            if (snakeDirection != SnakeConstants::LEFT) {
                snakeDirection = SnakeConstants::RIGHT;
            }
            break;
        case 'a':
            if (snakeDirection != SnakeConstants::RIGHT) {
                snakeDirection = SnakeConstants::LEFT;
            }
            break;
        default:
            break;
    }
}