#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "sudoku_lib.h"



void print_separator(void);

/* An array with some powers of 2 to avoid shifting all the time. */
int powers_of_two[10];

/* The Sudoku matrix itself. */
int matrix[9][9];

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
    //during execution.
    init_powers_of_two();

    //Initializes input sudoku entries and checks its validity
    init_input_sudoku_position(argc-1, argv+1);

    solve_sudoku();
    
    for (int i = 0; i < 9; ++i) {
        if ((i % 3) == 0) {
            print_separator();
        }
        for (int j = 0; j < 9; j++) {
            int cell = matrix[i][j];
            if ((j % 3) == 0) {
                printf("\e[1;34m|\e[0m ");
            } else {
                printf(" ");
            }
            if (input_sudoku_position[i][j]) {
                printf("\e[1;34m%d\e[0m ", cell);
            } else {
                printf("%d ", cell);
            }
        }
        printf("|\n");
    }
    print_separator();

    return 0;
}



/* Utility to print lines and crosses, used by print_matrix. */
void print_separator(void)
{
    for (int i = 0; i < 3; ++i) {
        printf("\e[1;34m+---------\e[0m");
    }
    printf("\e[1;34m+\n\e[0m");
}



