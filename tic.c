#include "stdio.h"

enum Turn {
    PLAYER_ONE,
    PLAYER_TWO,
    OVER
};

struct Game {
    enum Turn turn;
    char board[9];
};

void setup(struct Game * g) {
    for (size_t i = 0; i < 9; i++) {
        (*g).board[i] = ' ';
    }
    (*g).turn = PLAYER_ONE;
}

int main(void) {
    struct Game g;
    setup(&g);

    printf("%c", g.board[2]);
    printf("%d", (g.turn));

    return 0;
}