#include <GL/gl.h>
#include <GL/glut.h>

#include "callbacks.h"
#include "constants.h"
#include "game.h"

int main(int argc, char** argv) {  // ANCHOR - main
    SendRulesToOutputStream();
    glutInit(&argc, argv);

    // rgb mode with a double buffer
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowSize(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);
    glutCreateWindow("Serpent Game");  // argument is window name

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);

    glutKeyboardFunc(keypress);

    glClearColor(0, 0, 0, 1.0);  // default

    glutMainLoop();
    return 0;
}
