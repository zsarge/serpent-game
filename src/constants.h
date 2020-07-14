#ifndef CONSTANTS_H
#define CONSTANTS_H
// ANCHOR - constants
class Constants {
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
};

class Grid {
   public:
    static inline const float RED = 0.892;
    static inline const float GREEN = 0.751;
    static inline const float BLUE = 0.694;
};
#endif