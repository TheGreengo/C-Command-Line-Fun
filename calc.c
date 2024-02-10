//***************************************************************************\\
//                                                                           \\
//        The idea here is to have a little calculator in the terminal       \\
//                                                                           \\
//***************************************************************************\\

#include "stdio.h"
#include "string.h"

/*
* This union makes it so that we can either have a character or a number
*/
typedef union {
    double f;
    char c;
} data;

/*
* Enum for the different types of symbols
*/
typedef enum {
    SYMBOL = 0,
    NUM = 1,
    OPEN_PAR = 2,
    CLOSE_PAR = 3
} symbol;

/*
* This is the struct for entries in our array
*/
typedef struct {
    data d;
    symbol s;
} entry;


/*
* This function should just get the number of symbols in the args
*/
unsigned short arg_size() {
    return 0;
}

/*
* This function should get the type of each symbol and populate the data array
* with structs that are have the type of 
*/
void get_types() {

}

/*
* This function should check if the 
*/
int get_valid() {

}

int main(int argc, char ** argv) {
    
    for (int i = 0; i < argc - 1; i++) {
        printf("%lu", sizeof(data));
    }

    return 0;
}
