#include "stdio.h"

// Represents the state of the game (either someone's turn or finished)
enum Turn {
    PLAYER_ONE,
    PLAYER_TWO,
    OVER
};

// Simple struct for tracking the moves remaining, moves, and turn
struct Game {
    enum Turn turn;
    char board[9];
    size_t turns;
};

// initializes game with empty board set for Player One to go
void setup(struct Game * g) {
    for (size_t i = 0; i < 9; i++) {
        (*g).board[i] = ' ';
    }
    (*g).turn = PLAYER_ONE;
    (*g).turns = 0;
}

// Prints the current game layout to the command line
void printBoard(struct Game * g) {
    printf("\n  %c | %c | %c \n", (*g).board[0],(*g).board[1],(*g).board[2]);
    printf(" ___________\n");
    printf("  %c | %c | %c \n", (*g).board[3],(*g).board[4],(*g).board[5]);
    printf(" ___________\n");
    printf("  %c | %c | %c \n\n", (*g).board[6],(*g).board[7],(*g).board[8]);
}

void makeMove(struct Game * g) {
    if ((*g).turn == PLAYER_ONE) {
        printf("\n\n\n\n\n");
        printf("Player one's turn: \n");
        printBoard(g);
        printf("\n\n\n\n\n");

        printf("Enter move: ");


        (*g).turn = PLAYER_TWO;
    } else if ((*g).turn == PLAYER_TWO) {
        printf("\n\n\n\n\n");
        printf("Player two's turn: \n");
        printBoard(g);
        printf("\n\n\n\n\n");

        printf("Enter move: ");

        (*g).turn = PLAYER_ONE;
    }

    // mark that a turn has happened
    (*g).turns++;
}

int main(void) {
    struct Game g;
    setup(&g);
    printBoard(&g);

    while (g.turns < 9) {
        makeMove(&g);
    }

    return 0;
}