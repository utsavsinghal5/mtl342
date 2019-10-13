#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "sudoku_lib.h"

int square(int i, int j);
void set_cell(int i, int j, int n);
int clear_cell(int i, int j);
void init_input_sudoku_position(size_t count, char** cells);
bool is_available(int i, int j, int n);
bool advance_cell(int i, int j);
void solve_sudoku(void);
void init_powers_of_two(void);
void print_matrix(void);
void print_separator(void);

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
    //Prepares input sudoku entries and checks them
    init_powers_of_two();
    init_input_sudoku_position(argc-1, argv+1);

    solve_sudoku();
    print_matrix();

    return 0;
}

/* Returns the index of the square the cell (i, j) belongs to. */

int square(int i, int j)
{
    return (i/3)*3 + j/3;
}

/* Stores the number n in the cell (i, j), and turns on the corresponding
powers_of_two in rows, cols, and squares. */
void set_cell(int i, int j, int n)
{
    if(!is_available(i,j,n)){
        printf("Wrong entered matrix\n");
        exit(1);
    }
    matrix[i][j] = n;
    rows[i] |= powers_of_two[n];
    cols[j] |= powers_of_two[n];
    squares[square(i, j)] |= powers_of_two[n];
}

/* Clears the cell (i, j) and turns off the corresponding powers_of_two in rows, cols,
and squares. Returns the number it contained. */
int clear_cell(int i, int j)
{
    int n = matrix[i][j];
    matrix[i][j] = 0;
    rows[i] &= ~powers_of_two[n];
    cols[j] &= ~powers_of_two[n];
    squares[square(i, j)] &= ~powers_of_two[n];
    return n;
}

/* Processes the program arguments. Each argument is assumed to be a string
with three digits row-col-number, 1-based, representing the input_sudoku_position cells in the
Sudoku. For example, "123" means there is a 3 in the cell (0, 1). */
void init_input_sudoku_position(size_t count, char** cells)
{
    for (int c = 0; c < count; ++c) {
        char* cell = cells[c];
        int i, j, n;
        if (sscanf(cell, "%1d%1d%1d", &i, &j, &n)) {
            set_cell(i-1, j-1, n);
            input_sudoku_position[i-1][j-1] = 1;
        } else {
            printf("bad input token: %s\n", cell);
            exit(EXIT_FAILURE);
        }
    }
}

/* Can we put n in the cell (i, j)? */
bool is_available(int i, int j, int n)
{
    return (rows[i] & powers_of_two[n]) == 0 && (cols[j] & powers_of_two[n]) == 0 && (squares[square(i, j)] & powers_of_two[n]) == 0;
}

/* Tries to fill the cell (i, j) with the next available number.
Returns a flag to indicate if it succeeded. */
bool advance_cell(int i, int j)
{
    int n = clear_cell(i, j);
    while (++n <= 9) {
        if (is_available(i, j, n)) {
            set_cell(i, j, n);
            return true;
        }
    }
    return false;
}

/* The main function, a fairly generic backtracking algorithm. */
void solve_sudoku(void)
{
    int pos = 0;
    while (1) {
        while (pos < 81 && input_sudoku_position[pos/9][pos%9]) {
            ++pos;
        }
        if (pos >= 81) {
            break;
        }
        if (advance_cell(pos/9, pos%9)) {
            ++pos;
        } else {
            do {
                --pos;
            } while (pos >= 0 && input_sudoku_position[pos/9][pos%9]);
            if (pos < 0) {
                printf("No valid solution exist for this set of sudoku entries.\nPlease try different values\n");
                exit(1);
            }
        }
    }
    return;
}

/* Initializes the array with powers of 2. */
void init_powers_of_two(void)
{
    for (int n = 1; n < 10; n++) {
        powers_of_two[n] = 1 << n;
    }
}

/* Prints the matrix using some ANSI escape sequences
to distinguish the originally input_sudoku_position numbers. */
void print_matrix(void)
{
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
}

/* Utility to print lines and crosses, used by print_matrix. */
void print_separator(void)
{
    for (int i = 0; i < 3; ++i) {
        printf("\e[1;34m+---------\e[0m");
    }
    printf("\e[1;34m+\n\e[0m");
}