#include "stdio.h"

// Represents the state of the game (either someone's turn or finished)
enum Turn {
    PLAYER_ONE,
    PLAYER_TWO,
    OVER
};

// Simple struct for tracking the moves remaining, moves, and turn
typedef struct {
    enum Turn turn;
    char board[9];
    size_t turns;
    size_t winner;
} Game;

// initializes game with empty board set for Player One to go
void setup(Game * g) {
    for (size_t i = 0; i < 9; i++) {
        (*g).board[i] = ' ';
    }
    (*g).turn = PLAYER_ONE;
    (*g).turns = 0;
    (*g).winner = 0;
}

// Prints the current game layout to the command line
void printBoard(Game * g) {
    printf("\n   A | B | C \n");
    printf("\n1  %c | %c | %c \n", (*g).board[0],(*g).board[1],(*g).board[2]);
    printf("  ___________\n");
    printf("2  %c | %c | %c \n", (*g).board[3],(*g).board[4],(*g).board[5]);
    printf("  ___________\n");
    printf("3  %c | %c | %c \n\n", (*g).board[6],(*g).board[7],(*g).board[8]);
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

void makeMove(Game * g) {
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

size_t checkWin(Game * g) {
    size_t one = (((*g).board[0] == (*g).board[1]) && ((*g).board[0] == (*g).board[2]) && ((*g).board[0] == 'X')) ||\
    (((*g).board[0] == (*g).board[3]) && ((*g).board[0] == (*g).board[6]) && ((*g).board[0] == 'X')) ||\
    (((*g).board[0] == (*g).board[4]) && ((*g).board[0] == (*g).board[8]) && ((*g).board[0] == 'X')) ||\
    (((*g).board[3] == (*g).board[4]) && ((*g).board[3] == (*g).board[5]) && ((*g).board[3] == 'X')) ||\
    (((*g).board[6] == (*g).board[7]) && ((*g).board[6] == (*g).board[8]) && ((*g).board[6] == 'X')) ||\
    (((*g).board[1] == (*g).board[4]) && ((*g).board[1] == (*g).board[7]) && ((*g).board[1] == 'X')) ||\
    (((*g).board[2] == (*g).board[5]) && ((*g).board[2] == (*g).board[8]) && ((*g).board[2] == 'X')) ||\
    (((*g).board[2] == (*g).board[4]) && ((*g).board[2] == (*g).board[6]) && ((*g).board[2] == 'X'));

    size_t two = (((*g).board[0] == (*g).board[1]) && ((*g).board[0] == (*g).board[2]) && ((*g).board[0] == 'O')) ||\
    (((*g).board[0] == (*g).board[3]) && ((*g).board[0] == (*g).board[6]) && ((*g).board[0] == 'O')) ||\
    (((*g).board[0] == (*g).board[4]) && ((*g).board[0] == (*g).board[8]) && ((*g).board[0] == 'O')) ||\
    (((*g).board[3] == (*g).board[4]) && ((*g).board[3] == (*g).board[5]) && ((*g).board[3] == 'O')) ||\
    (((*g).board[6] == (*g).board[7]) && ((*g).board[6] == (*g).board[8]) && ((*g).board[6] == 'O')) ||\
    (((*g).board[1] == (*g).board[4]) && ((*g).board[1] == (*g).board[7]) && ((*g).board[1] == 'O')) ||\
    (((*g).board[2] == (*g).board[5]) && ((*g).board[2] == (*g).board[8]) && ((*g).board[2] == 'O')) ||\
    (((*g).board[2] == (*g).board[4]) && ((*g).board[2] == (*g).board[6]) && ((*g).board[2] == 'O'));

    if (one == two) {
        return 0;
    } 
    return one > two ? 1 : 2;
}

int main(void) {
    Game g;
    setup(&g);

    while (g.turns < 9 && g.winner == 0) {
        makeMove(&g);
        g.winner = checkWin(&g);
    }

    printBoard(&g);
    if (g.winner) {
        g.winner == 1 ? printf("Player one wins!\n") : printf("Player two wins\n");
    } else {
        printf("Tied game!\n");
    }

    return 0;
}