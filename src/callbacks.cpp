#include "callbacks.h"

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    glutSwapBuffers();
}

void reshape(int width, int height) {  // ANCHOR - reshape SIZE
    glViewport(Constants::SCREEN_POS_X, Constants::SCREEN_POS_Y, Constants::VIEWPORT_SCALE, Constants::VIEWPORT_SCALE);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // I'm currently making this game in 2D.
    // In the future, I plan to switch to a 3D perspective.
    glOrtho(0, Constants::ROWS, 0, Constants::COLUMNS, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
}
