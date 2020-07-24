#include "game.h"

// Variables are used in DrawAndUpdateSnake()
int SnakeX = SnakeConstants::START_X;
int SnakeY = SnakeConstants::START_Y;
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

Snake::Snake() {  // Snake constructor
    segment head = {SnakeConstants::START_X, SnakeConstants::START_Y};
    body.push_back(head);
}

void SendRulesToOutputStream() {
    std::cout << "Hello. This is a serpent game by Zack Sargent made\n";
    std::cout << "to learn the basics of graphics in C++.\n\n";
    std::cout << "Instructions:\n";
    std::cout << "\tUse WASD to control the serpent.\n";
    std::cout << "\tDo not run into yourself or the walls.\n";
    std::cout.flush();
}

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

// REVIEW - should rename to fit naming conventions? Or is everything else
// wrong?
void drawGrid() {
    std::cout << "\nX = " << snake.GetSegment(0).X << std::endl;
    std::cout << "Y = " << snake.GetSegment(0).Y << std::endl;
    for (float x = 0; x < Constants::ROWS; x++) {
        for (float y = 0; y < Constants::COLUMNS; y++) {
            glColor3f(GridColor::RED, GridColor::GREEN, GridColor::BLUE);
            drawSquare(x, y);
        }
    }
}

void DrawAndUpdateSnake() {
    UpdateSnake();

    // REVIEW - change for all segments
    glColor3f(SnakeConstants::RED, SnakeConstants::GREEN, SnakeConstants::BLUE);
    glRectd(snake.GetSegment(0).X, snake.GetSegment(0).Y,
            snake.GetSegment(0).X + 1, snake.GetSegment(0).Y + 1);
}

void UpdateSnake() {
    MoveSnake();
    WrapSnake();
}

void MoveSnake() {
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
    int XPos = snake.GetSegment(0).X;
    int YPos = snake.GetSegment(0).Y;

    if (snake.GetSegment(0).X == -1) {
        snake.SetSegment(0, Constants::COLUMNS - 1, YPos);
    } else if (snake.GetSegment(0).Y == -1) {
        snake.SetSegment(0, XPos, Constants::ROWS - 1);
    } else if (snake.GetSegment(0).X == Constants::COLUMNS) {
        snake.SetSegment(0, 0, YPos);
    } else if (snake.GetSegment(0).Y == Constants::ROWS) {
        snake.SetSegment(0, XPos, 0);
    }
}