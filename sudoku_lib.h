#ifndef _SUDOKU_LIB_H_
#define _SUDOKU_LIB_H_

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

#endif