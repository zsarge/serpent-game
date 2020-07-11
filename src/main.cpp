#include <GL/gl.h>
#include <GL/glut.h>

#include "callbacks.h"

int main(int argc, char** argv) {  // ANCHOR - main 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    // rgb mode with a double buffer

    glutInitWindowSize(500, 500);
    glutCreateWindow("Serpent Game");  // argument is window name
    glClearColor(0, 0, 0, 1.0);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
