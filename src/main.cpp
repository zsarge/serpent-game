#include <GL/gl.h>
#include <GL/glut.h>

#include "callbacks.cpp"
#include "constants.h"
#include "game.h"

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    glutSwapBuffers();
}

void reshape(int width, int height) {  // ANCHOR - reshape SIZE
    glViewport(SCREEN_POS_X, SCREEN_POS_Y, VIEWPORT_SCALE, VIEWPORT_SCALE);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // I'm currently making this game in 2D.
    // In the future, I plan to switch to a 3D perspective.
    glOrtho(0, ROWS, 0, COLUMNS, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
}



int main(int argc, char** argv) {  // ANCHOR - main
    glutInit(&argc, argv);

    // rgb mode with a double buffer
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow("Serpent Game");  // argument is window name

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glClearColor(0, 0, 0, 1.0);  // default

    glutMainLoop();
    return 0;
}
