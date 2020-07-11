// Positions to size window
const int POS_X = 100;
const int POS_Y = 100;

void display() { glutSwapBuffers(); }

void reshape(int width, int height) { // ANCHOR - reshape
    glViewport(POS_X, POS_Y, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // I'm currently making this game in 2D.
    // In the future, I plan to switch to a 3D perspective.

    // TODO: Consider using glOrtho2D?

    // 40 wide, 40 tall, 
    glOrtho(0.0, 40.0, 0.0, 40.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
}
