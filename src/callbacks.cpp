#include "callbacks.h"

extern short SnakeDirection;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    DrawAndUpdateSnake();
    glutSwapBuffers();
}

void reshape(int width, int height) {  // ANCHOR - reshape SIZE
    glViewport(Constants::SCREEN_POS_X, Constants::SCREEN_POS_Y,
               Constants::VIEWPORT_SCALE, Constants::VIEWPORT_SCALE);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // I'm currently making this game in 2D.
    // In the future, I plan to switch to a 3D perspective.
    glOrtho(0, Constants::ROWS, 0, Constants::COLUMNS, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
}

void timer(int) {
    glutPostRedisplay();
    glutTimerFunc(1000 / Constants::FPS, timer, 0);
}

void keypress(unsigned char key, int, int) {
    // note that the serpent should not turn 180 degrees
    switch (key) {
        case 'w':
            if (SnakeDirection != SnakeConstants::DOWN) {
                SnakeDirection = SnakeConstants::UP;
            }
            break;
        case 's':
            if (SnakeDirection != SnakeConstants::UP) {
                SnakeDirection = SnakeConstants::DOWN;
            }
            break;
        case 'd':
            if (SnakeDirection != SnakeConstants::LEFT) {
                SnakeDirection = SnakeConstants::RIGHT;
            }
            break;
        case 'a':
            if (SnakeDirection != SnakeConstants::RIGHT) {
                SnakeDirection = SnakeConstants::LEFT;
            }
            break;
        default:
            break;
    }
}