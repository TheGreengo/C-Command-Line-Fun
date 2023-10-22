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

size_t getUInput() {
    char response[20];
    printf("Please input your move: ");
    scanf("%s", response);
    if (response[0] == '1' && (response[1] == 'A' || response[1] == 'a')) {
        return 0;
    } else if (response[0] == '1' && (response[1] == 'B' || response[1] == 'b')) {
        return 1;
    } else if (response[0] == '1' && (response[1] == 'C' || response[1] == 'c')) {
        return 2;
    } else if (response[0] == '2' && (response[1] == 'A' || response[1] == 'a')) {
        return 3;
    } else if (response[0] == '2' && (response[1] == 'B' || response[1] == 'b')) {
        return 4;
    } else if (response[0] == '2' && (response[1] == 'C' || response[1] == 'c')) {
        return 5;
    } else if (response[0] == '3' && (response[1] == 'A' || response[1] == 'a')) {
        return 6;
    } else if (response[0] == '3' && (response[1] == 'B' || response[1] == 'b')) {
        return 7;
    } else if (response[0] == '3' && (response[1] == 'C' || response[1] == 'c')) {
        return 8;
    } else {
        return 9;
    }
}

void makeMove(struct Game * g) {
    // start by printing board and announcing who's turn it is
    printf("\n\n\n\n\n");
    (*g).turn == PLAYER_ONE ? printf("Player one's turn: \n") : printf("Player two's turn: \n");
    printBoard(g);
    printf("\n\n\n\n\n");

    // loop to keep requesting input until valid input is received
    size_t res = 9;
    while (res == 9) {
        res = getUInput();
        if (res == 9) {
            printf("Invalid play. Either that spot is taken or you had a typo. \n\
            Please type only two characters, the row and colum of your desired\
             play, with no spaces in between. For example \"A1\"");
        }
    }

    // mark play
    (*g).board[res] = (*g).turn == PLAYER_ONE ? 'X' : 'O';

    // mark that a turn has happened
    (*g).turns++;    

    // switch players
    (*g).turn = (*g).turn == PLAYER_ONE ? PLAYER_TWO : PLAYER_ONE;

}

int main(void) {
    struct Game g;
    setup(&g);
    printBoard(&g);

    while (g.turns < 9) {
        makeMove(&g);
    }

    printBoard(&g);

    return 0;
}