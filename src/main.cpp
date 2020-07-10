#include <GL/gl.h>
#include <GL/glut.h>

void display() { glutSwapBuffers(); }

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    // rgb mode with a double buffer

    glutInitWindowSize(500, 500);
    glutCreateWindow("Serpent Game");  // argument is window name

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
