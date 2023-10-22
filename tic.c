#include "stdio.h"

enum Turn {
    PLAYER_ONE,
    PLAYER_TWO,
    OVER
};

struct Game {
    enum Turn turn;
    char bord[9];
};

int main(void) {
    struct Game g;
    
    return 0;
}