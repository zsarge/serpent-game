#include <GL/gl.h>
#include <GL/glut.h>

#include "callbacks.h"
#include "constants.h"
#include "game.cpp"

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
