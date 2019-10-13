#ifndef _SUDOKU_LIB_H_
#define _SUDOKU_LIB_H_

/* An array with some powers of 2 to avoid shifting all the time. */
extern int powers_of_two[10];

/* The Sudoku matrix itself. */
extern int matrix[9][9];

/* Which numbers were given as input_sudoku_position in the problem. */
extern int input_sudoku_position[9][9];

/* An array of nine integers, each of which representing a sub-square.
Each integer has its nth-bit on iff n belongs to the corresponding sub-square. */
extern int squares[9];

/* An array of nine integers, each of which representing a row.
Each integer has its nth-bit on iff n belongs to the corresponding row. */
extern int rows[9];

/* An array of nine integers, each of which representing a column.
Each integer has its nth-bit on iff n belongs to the corresponding column. */
extern int cols[9];

void init_powers_of_two(void);
int square(int i, int j);
void set_cell(int i, int j, int n);
int clear_cell(int i, int j);
void init_input_sudoku_position(size_t count, char** cells);
bool is_available(int i, int j, int n);
bool advance_cell(int i, int j);
void solve_sudoku(void);
void print_matrix(void);


#endif