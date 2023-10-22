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
    char play[3] = (*g).turn == PLAYER_ONE ? "one" : "two";
    (*g).turn = (*g).turn == PLAYER_ONE ? PLAYER_TWO : PLAYER_ONE;

    printf("\n\n\n\n\n");
    printf("Player %s's turn: \n", play);
    printBoard(g);
    printf("\n\n\n\n\n");

    int res = 9;

    while (res == 9) {
        res = getInput();
        if (res == 9) {
            printf("Invalid play. Either that spot is taken or you had a typo. \n\
            Please type only two characters, the row and colum of your desired\
             play, with no spaces in between. For example \"A1\"");
        }
    }

    (*g).board[res] = (*g).turn == PLAYER_ONE ? 'X' : 'O';
    // mark that a turn has happened
    (*g).turns++;
}

size_t getInput() {
    char response[20];
    printf("Please input your move: ");
    scanf("%s", response);
    if (response[1] == '1' && (response[0] == 'A' || response[0] == 'a')) {
        return 0;
    } else if (response[1] == '1' && (response[0] == 'B' || response[0] == 'b')) {
        return 1;
    } else if (response[1] == '1' && (response[0] == 'C' || response[0] == 'c')) {
        return 2;
    } else if (response[1] == '2' && (response[0] == 'A' || response[0] == 'a')) {
        return 3;
    } else if (response[1] == '2' && (response[0] == 'B' || response[0] == 'b')) {
        return 4;
    } else if (response[1] == '2' && (response[0] == 'C' || response[0] == 'c')) {
        return 5;
    } else if (response[1] == '3' && (response[0] == 'A' || response[0] == 'a')) {
        return 6;
    } else if (response[1] == '3' && (response[0] == 'B' || response[0] == 'b')) {
        return 7;
    } else if (response[1] == '3' && (response[0] == 'C' || response[0] == 'c')) {
        return 8;
    } else {
        return 9;
    }
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