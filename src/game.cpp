#include "game.h"

short snakeDirection = SnakeConstants::RIGHT;
int snakeSpeed = 0;

// define the main snake object
Snake snake;

// define the main food object
Food food;

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

void Snake::Grow() {
    segment head = snake.GetSegment(snake.GetLength() - 1);
    body.push_back(head);
    snakeSpeed += Constants::POINTS_PER_FOOD;
}

void Snake::Restart() {
    std::cout << "You died with " << snakeSpeed / Constants::POINTS_PER_FOOD
              << " food." << std::endl;
    snakeSpeed = 0;
    // clear length and restart game
    usleep(3000000);  // unix sleep command
    snakeDirection = SnakeConstants::RIGHT;
    body.clear();
    segment head = {SnakeConstants::START_X, SnakeConstants::START_Y};
    body.push_back(head);
    segment temp = {SnakeConstants::START_X - 1, SnakeConstants::START_Y};
    body.push_back(temp);
    food.MoveFood();
}

Snake::Snake() {  // Snake constructor
    segment head = {SnakeConstants::START_X, SnakeConstants::START_Y};
    body.push_back(head);
    segment temp = {SnakeConstants::START_X - 1, SnakeConstants::START_Y};
    body.push_back(temp);
}

Snake::~Snake() {  // Snake deconstructor
    body.clear();
}

Food::Food() {
    // food constructor
    srand(time(NULL)); // create seed for random food placement
    food.MoveFood();
}

void Food::MoveFood() {
    segment temp;
    bool overlaps = false;
    temp.X = RandomNumber(0, Constants::COLUMNS - 1);
    temp.Y = RandomNumber(0, Constants::ROWS - 1);

    for (int index = 0; index <= snake.GetLength() - 1; index++) {
        segment body = snake.GetSegment(index);
        if (temp.X == body.X && temp.Y == body.Y) {
            overlaps = true;
        }
    }

    if (overlaps) {
        // recursively call this function, until the food is not on the snake
        food.MoveFood();
    } else {
        piece = temp;
    }
}

segment Food::GetFood() {
    // Getter for Food
    return piece;
}

int RandomNumber(int bottom, int top) {
    // srand is called in object constructor
    return rand() % top + bottom;
}

void SendRulesToOutputStream() {
    std::cout << "Hello. This is a serpent game by Zack Sargent made\n";
    std::cout << "to learn the basics of graphics in C++.\n\n";
    std::cout << "Instructions:\n";
    std::cout << "\tUse WASD to control the serpent.\n";
    std::cout << "\tDo not run into yourself or the walls.\n" << std::endl;
    std::cout.flush();
}

void DrawSquare(int x, int y) {  // ANCHOR - DrawSquare
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
void DrawGrid() {
    for (float x = 0; x < Constants::ROWS; x++) {
        for (float y = 0; y < Constants::COLUMNS; y++) {
            glColor3f(GridColor::RED, GridColor::GREEN, GridColor::BLUE);
            DrawSquare(x, y);
        }
    }
}

void DrawAndUpdateGame() {
    UpdateSnake();
    ApplyFoodRules();

    // draw snake body
    glColor3f(SnakeConstants::RED, SnakeConstants::GREEN, SnakeConstants::BLUE);
    for (int index = 1; index <= snake.GetLength() - 2; index++) {
        segment body = snake.GetSegment(index);
        glRectd(body.X, body.Y, body.X + 1, body.Y + 1);
    }

    // draw snake tail
    glColor3f(SnakeConstants::TAIL_RED, SnakeConstants::TAIL_GREEN,
              SnakeConstants::TAIL_BLUE);
    segment body = snake.GetSegment(snake.GetLength() - 1);
    glRectd(body.X, body.Y, body.X + 1, body.Y + 1);

    // draw snake head
    glColor3f(SnakeConstants::HEAD_RED, SnakeConstants::HEAD_GREEN,
              SnakeConstants::HEAD_BLUE);
    segment head = snake.GetSegment(0);
    glRectd(head.X, head.Y, head.X + 1, head.Y + 1);

    // draw food
    glColor3f(FoodConstants::RED, FoodConstants::GREEN, FoodConstants::BLUE);
    segment piece = food.GetFood();
    glRectd(piece.X, piece.Y, piece.X + 1, piece.Y + 1);
}

void ApplyFoodRules() {
    // REVIEW - apply rules
    if (snake.GetSegment(0).X == food.GetFood().X &&
        snake.GetSegment(0).Y == food.GetFood().Y) {
        snake.Grow();
        food.MoveFood();
    }
}

void UpdateSnake() {
    CheckSnake();
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

void CheckSnake() {  // makes sure the snake is not running into itself.
    // REVIEW - This will benefit significantly from operator overloading
    segment head = snake.GetSegment(0);
    for (int index = 1; index <= snake.GetLength() - 1; index++) {
        if (head.X == snake.GetSegment(index).X &&
            head.Y == snake.GetSegment(index).Y) {
            snake.Restart();
        }
    }
}