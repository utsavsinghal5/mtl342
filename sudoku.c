#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "sudoku_lib.h"



void row_separator(void);

/* The Sudoku matrix itself. */
int sudoku_matrix[9][9];

/* Which numbers were given as input_sudoku_position in the problem. */
int input_sudoku_position[9][9];

/* An array of nine integers, each of which representing a sub-square.
Each integer has its nth-bit on iff n belongs to the corresponding sub-square. */
int squares[9];

/* An array of nine integers, each of which representing a row.
Each integer has its nth-bit on iff n belongs to the corresponding row. */
int rows[9];

/* An array of nine integers, each of which representing a column.
Each integer has its nth-bit on iff n belongs to the corresponding column. */
int cols[9];

/* An array with some powers of 2 to avoid shifting all the time. */
int powers_of_two[10];


int main(int argc, char** argv)
{   
    //Initialize powers of two in a set to avoid
    //repeated multiplication with power of two
    //during execution. Stored in powers_of_two[10]
    init_powers_of_two();

    //Initializes input sudoku entries and checks its validity
    init_input_sudoku_position(argc-1, argv+1);

    // Solving of sudoku starts here
    solve_sudoku();


    // Below is the print function which outputs the sudoku 
    // in a proper square matrix format with proper boundaries.
    // It uses data stored in sudoku_matrix[9][9] and input_sudoku_position[9][9]
    printf("\n                         Input is in \e[1;31m'Red'\e[0m \n");
    printf("                         Output is in 'White' \n");   
    for (int i = 0; i < 9; ++i) {
        printf("                    ");
        if ((i % 3) == 0) {
            row_separator();
            printf("                    ");
        }
        for (int j = 0; j < 9; j++) {
            int cell = sudoku_matrix[i][j];
            if ((j % 3) == 0) {
                printf("\e[1;34m|\e[0m ");
            } else {
                printf(" ");
            }
            if (input_sudoku_position[i][j]) {
                printf("\e[1;31m%d\e[0m ", cell);
            } else {
                printf("%d ", cell);
            }
        }
        printf("\e[1;34m|\e[0m \n");
    }
    printf("                    ");
    row_separator();
    printf("\n");
    return 0;
}

/* Utility to print lines and crosses, used by print_matrix. */
void row_separator(void)
{
    for (int i = 0; i < 3; ++i) {
        printf("\e[1;34mX---------\e[0m");
    }
    printf("\e[1;34mX\n\e[0m");
}



