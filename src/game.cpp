#include "game.h"

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

void drawGrid() {
    for (float x = 0; x < ROWS; x++) {
        for (float y = 0; y < COLUMNS; y++) {
            glColor3f(GRID_COLOR);
            drawSquare(x, y);
        }
    }
    glColor3f(1, 0, 0);  // Set the colour to red
    drawSquare(5.0, 5.0);
    drawSquare(4.0, 4.0);
}