// All important constants should be accessable from this file,
// so that they can be easily changed.

#ifndef CONSTANTS_H
#define CONSTANTS_H
// ANCHOR - constants
class Constants {  // General constants
   public:
    // screen sizing
    static inline const int SCREEN_WIDTH = 645;
    static inline const int SCREEN_HEIGHT = 645;

    // viewport handling - smaller = larger
    static inline const int VIEWPORT_SCALE = 600;

    // screen positioning
    static inline const int SCREEN_POS_X = 20;
    static inline const int SCREEN_POS_Y = 20;

    // grid sizing
    static inline const int COLUMNS = 10;
    static inline const int ROWS = 10;

    // Frames per second
    // REVIEW - This might be changed later - Should not be constant?
    static inline const int FPS = 1;
};

class GridColor {
   public:
    static inline const float RED = 0.892;
    static inline const float GREEN = 0.751;
    static inline const float BLUE = 0.694;
};

class SnakeConstants {
   public:
    static inline const int START_X = Constants::COLUMNS / 2;
    static inline const int START_Y = Constants::ROWS / 2;

    static inline const int UP = 1;
    static inline const int DOWN = -1;
    static inline const int RIGHT = 2;
    static inline const int LEFT = -2;

    static inline const float RED = 0.65;
    static inline const float GREEN = 0.0;
    static inline const float BLUE = 0.0;

    static inline const float HEAD_RED = 0.8;
    static inline const float HEAD_GREEN = 0.0;
    static inline const float HEAD_BLUE = 0.0;

    static inline const float TAIL_RED = 0.5;
    static inline const float TAIL_GREEN = 0.0;
    static inline const float TAIL_BLUE = 0.0;
};

class FoodConstants {
   public:
    static inline const float RED = 0.0;
    static inline const float GREEN = 1.0;
    static inline const float BLUE = 1.0;
};
#endif