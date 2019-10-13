#+TITLE: Sudoku for MTL342 Prof. Niladri Chatterjee

The program consists of sudoku implementation done as an assignment for MTL342 by me under Prof. Niladri Chatterjee in the academic session 2019-20. The assignment was finished on 13-10-2019 and was submitted on the same day.

The program consists of three main files "sudoku.c" consisting of main, "sudoku_lib.h" as a library and "function.c" consisting of utility functions used in main.

*Operation:
	- To run the program, execute the Makefile in terminal(with the
	  same directory as program) by typing "make". It will generate an executable output file named "sudoku"

	- Now execute the output file by entering "./sudoku" followed by
	  entries to be entered with space after each entry.

*Format for entry:
	- Each entry is a string of 3 numerical digits where first digit in
	  1-9 tells the row position, secong digit in in 1-9 tells the column position and third digit tells the value of the entry. For example 543 will enter number 3 on the location (5,4) in the 9 X 9
	  matrix.


*For example:
	- So after running makefile if enter ./sudoku 111 124 546 991 
	  714 382, the generated sudoku will be.

	                X---------X---------X---------X
                    | 1  4    |         |         | 
                    |         |         |         | 
                    |         |         |    2    | 
                    X---------X---------X---------X
                    |         |         |         | 
                    |         | 6       |         | 
                    |         |         |         | 
                    X---------X---------X---------X
                    | 4       |         |         | 
                    |         |         |         | 
                    |         |         |       1 | 
                    X---------X---------X---------X

       and the reult will be displayed on terminal.

*Some more examples to test 

./sudoku 141 165 186 198 277 291 319 331 383 437 452 466 515 593 648 657 674 723 778 795 811 835 917 929 944 961

./sudoku 118 144 156 251 299 327 343 368 376 412 489 513 528 582 591 625 698 734 745 766 781 815 854 959 963 996

Custom exmpales can be done too. Make sure they are valid entries otherwise corresponding error will be reported.
Also, not all valid entries have a unique existing solution. If it happens, program returns error as no solution exists.