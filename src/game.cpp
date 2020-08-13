#include "game.h"

// Variables are used in DrawAndUpdateSnake()
short snakeDirection = SnakeConstants::RIGHT;
bool gameOver = false;

// define the main snake object
Snake snake;

segment Snake::GetSegment(int index) {
    // getter for snake object
    return body[index];
}

void Snake::SetSegment(int index, int X, int Y) {
    // setter for snake object
    body[index].X = X;
    body[index].Y = Y;
}

int Snake::GetLength() {
    // get length of vector body
    return body.size();
}

Snake::Snake() {  // Snake constructor
    segment head = {SnakeConstants::START_X, SnakeConstants::START_Y};
    body.push_back(head);
    segment temp = {SnakeConstants::START_X - 1, SnakeConstants::START_Y};
    body.push_back(temp);
}

void SendRulesToOutputStream() {
    std::cout << "Hello. This is a serpent game by Zack Sargent made\n";
    std::cout << "to learn the basics of graphics in C++.\n\n";
    std::cout << "Instructions:\n";
    std::cout << "\tUse WASD to control the serpent.\n";
    std::cout << "\tDo not run into yourself or the walls.\n" << std::endl;
    std::cout.flush();
}

void drawSquare(int x, int y) {  // ANCHOR - drawSquare
    glLineWidth(10.0);

    // 2f takes two floating points
    // REVIEW - this will need to be replaced when I switch to 3D

    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x + 1, y);
    glVertex2f(x + 1, y + 1);
    glVertex2f(x, y + 1);
    glEnd();

    glFlush();
}

// REVIEW - should rename to fit naming conventions? Or is everything else
// wrong?
void drawGrid() {
    for (float x = 0; x < Constants::ROWS; x++) {
        for (float y = 0; y < Constants::COLUMNS; y++) {
            glColor3f(GridColor::RED, GridColor::GREEN, GridColor::BLUE);
            drawSquare(x, y);
        }
    }
}

void DrawAndUpdateSnake() {
    UpdateSnake();

    for (int index = 0; index <= snake.GetLength() - 1; index++) {
        glColor3f(SnakeConstants::RED, SnakeConstants::GREEN,
                  SnakeConstants::BLUE);
        glRectd(snake.GetSegment(index).X, snake.GetSegment(index).Y,
                snake.GetSegment(index).X + 1, snake.GetSegment(index).Y + 1);
    }
}

void UpdateSnake() {
    MoveSnake();
    WrapSnake();
}

void MoveSnake() {
    // moves snake forward, started at end of snake
    for (int index = snake.GetLength() - 1; index > 0; index--) {
        segment nextPosition = snake.GetSegment(index - 1);
        snake.SetSegment(index, nextPosition.X, nextPosition.Y);
    }
    MoveHead();
}

void MoveHead() {
    // Check which direction the snake is moving,
    // and move it in that direction.
    int XPos = snake.GetSegment(0).X;
    int YPos = snake.GetSegment(0).Y;

    switch (snakeDirection) {
        case SnakeConstants::UP:
            snake.SetSegment(0, XPos, YPos + 1);
            break;
        case SnakeConstants::DOWN:
            snake.SetSegment(0, XPos, YPos - 1);
            break;
        case SnakeConstants::RIGHT:
            snake.SetSegment(0, XPos + 1, YPos);
            break;
        case SnakeConstants::LEFT:
            snake.SetSegment(0, XPos - 1, YPos);
            break;
        default:
            break;
    }
}

void WrapSnake() {
    for (int index = 0; index <= snake.GetLength() - 1; index++) {
        int XPos = snake.GetSegment(index).X;
        int YPos = snake.GetSegment(index).Y;

        switch (XPos) {
            case -1:  // too far left
                snake.SetSegment(index, Constants::COLUMNS - 1, YPos);
                break;
            case Constants::COLUMNS:  // too far right
                snake.SetSegment(index, 0, YPos);
                break;
        }
        switch (YPos) {
            case -1:  // too far down
                snake.SetSegment(index, XPos, Constants::ROWS - 1);
                break;
            case Constants::ROWS:  // too far up
                snake.SetSegment(index, XPos, 0);
                break;
        }
    }
}