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

void printBoard(struct Game * g) {
    printf("\n  %c | %c | %c \n", (*g).board[0],(*g).board[1],(*g).board[2]);
    printf(" ___________\n");
    printf("  %c | %c | %c \n", (*g).board[3],(*g).board[4],(*g).board[5]);
    printf(" ___________\n");
    printf("  %c | %c | %c \n\n", (*g).board[6],(*g).board[7],(*g).board[8]);
}

int main(void) {
    struct Game g;
    setup(&g);
    printBoard(&g);

    return 0;
}