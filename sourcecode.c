#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * display_board() function: takes the contents of the board and prints them on the screen.
 */
int display_board(char board[3][3]); // Prototype
int display_board(char board[3][3]) // Placeholder for display_board() function until I decide exactly how I'm going to do it
{
	int i = 0; // initialize loop counter
	int j = 0; // initialize loop counter
	/* for (i = 0; i < 3; i++) // Go through each row
	{
		for (j = 0; j < 3; j++) // Go through each column
		{
			printf("\n board[%i][%i] = %c \n", i, j, board[i][j]); // Statement for debugging
		}
	}
	*/
	for (i = 0; i < 3; i++) // Repeat the previous (now commented-out) loop, except format the output in more of a board-shape
	{
		printf(" \n "); // Each row should end in a newline
		for (j = 0; j < 3; j++) // Go through each column
		{
			printf(" %c ", board[i][j]); // Not just a statement for debugging this time around.
		}
	}
	printf(" \n "); // just some extra whitespace for no reason
	return 0;
}

/*
 * input() function: gets input for either row number or column number and returns it
 */
int input(int number); // Prototype
int input(int number) // Placeholder for input() function until I decide exactly how I'm going to do it
{
	int row_or_column = 0; // Initialize
	char* string_to_print[7]; // Declare but don't initialize yet, I want to initialize it conditionally
	if (number == 0) // what number should be the first time
	{
		*string_to_print = "row";
	} else if (number == 1) // what number should be the second time
	{
		*string_to_print = "column";
	} else {
		printf("\n This is not supposed to hapen. \n"); // Just in case
	}
	int valid = 0; // Initialize truth-flag for while loops
	while (valid == 0)
	{
		printf("\n Choose a %s> ", *string_to_print); // Display prompt
		scanf("%d", &row_or_column); // Get input 
		if (1 <= row_or_column && row_or_column <= 3)
		{
			printf("\n You have chosen %s #%d. \n", *string_to_print, row_or_column);
			valid = 1;
			// printf("\n valid = %i \n", valid); // Statement for debugging
		} else {
			printf("\n %s = %d \n", *string_to_print, row_or_column); // Statement for debugging
			printf("\n Invalid %s chosen, please try again. \n (The %s number must be either 1, 2, or 3.) \n", *string_to_print, *string_to_print);
			// row = 0; // re-initialize, just in case
		}
	}
	return row_or_column;
}

/*
 * winner() function: examines the board state and checks to see if there's a winner.
 */
int winner(char board[3][3]); // Prototype
int winner(char board[3][3]) // Placeholder for winner() function until I decide exactly how I'm going to do it
{
	int winner_number = 0; // Returned to main function later
	int blank = 0; // Used to tell if the game is over or there's a tie
	int i = 0; // Initialize loop-counter (used to go through board to detect blank spaces)
	int j = 0; // Initialize loop-counter (used to go through board to detect blank spaces)
	if (((board[0][0] == 'X') && (board[0][1] == 'X') && (board[0][2] == 'X')) || // first row
		((board[0][0] == 'X') && (board[1][0] == 'X') && (board[2][0] == 'X')) || // first column
		((board[0][0] == 'X') && (board[1][1] == 'X') && (board[2][2] == 'X')) || // diagonal 1
		((board[1][0] == 'X') && (board[1][1] == 'X') && (board[1][2] == 'X')) || // second row
		((board[2][0] == 'X') && (board[2][1] == 'X') && (board[2][2] == 'X')) || // third row
		((board[0][1] == 'X') && (board[1][1] == 'X') && (board[2][1] == 'X')) || // second column
		((board[0][2] == 'X') && (board[1][2] == 'X') && (board[2][2] == 'X')) || // third column
		((board[0][2] == 'X') && (board[1][1] == 'X') && (board[2][0] == 'X')) // diagonal 2
		)
	{
		winner_number = 1;
	} else if (((board[0][0] == 'O') && (board[0][1] == 'O') && (board[0][2] == 'O')) || // first row
			   ((board[0][0] == 'O') && (board[1][0] == 'O') && (board[2][0] == 'O')) || // first column
			   ((board[0][0] == 'O') && (board[1][1] == 'O') && (board[2][2] == 'O')) || // diagonal 1
			   ((board[1][0] == 'O') && (board[1][1] == 'O') && (board[1][2] == 'O')) || // second row
			   ((board[2][0] == 'O') && (board[2][1] == 'O') && (board[2][2] == 'O')) || // third row
			   ((board[0][1] == 'O') && (board[1][1] == 'O') && (board[2][1] == 'O')) || // second column
			   ((board[0][2] == 'O') && (board[1][2] == 'O') && (board[2][2] == 'O')) || // third column
			   ((board[0][2] == 'O') && (board[1][1] == 'O') && (board[2][0] == 'O')) // diagonal 2
			   )
	{
		winner_number = 2;
	} else {
		for (i = 0; i < 3; i++) // Go through each row
		{
			for (j = 0; j < 3; j++) // Go through each column
			{
				if (board[i][j] == '_') {
					blank = 1; // 1 means there's still a blank
				}
			}
		}
		if (blank == 0) { // It will still be 0 if no blanks were found
			winner_number = 3;
		}
	}
	// printf("\n winner_number = %i \n", winner_number); // Statement for debugging
	return winner_number;
}

/*
 * Main function
 */
int main (int argc, const char * argv[]) { // Template for arguments for main()
	int number = 0; // Initialize variable which is later passed to Input()
	int player = 1; // Represent players as numbers
	int flag = 0; // Used later in a while-loop
	printf("\n Message for security and/or debugging: \n This program's path is %s and it is running with %i argument(s). \n", argv[0], argc); // Statement for debugging
	char board[3][3] = {{'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'}}; // declare board per homework assignment
	int won = 0; // Initialize win condition flag
	// printf("\n won = %i \n", won); // Statement for debugging
	printf("\n Here is a blank Tic-Tac-Toe board for you and a friend to play Tic-Tac-Toe on: \n");
	display_board(board); // Show initial position of board (empty)
	while (won == 0) // Continue the game until a player wins
	{
		while (flag == 0) {
			printf("\n It is player #%i's turn. \n", player); // Statement for debugging
			int row = input(number); // Start game by getting row
			row--; // Decrement because the arrays actually go from 0 to 2, not 1 to 3
			// printf("\n row = %i \n", row); // Statement for debugging
			number++; // increment number passed to input function to tell it to get column instead of row
			int column = input(number); // Get column
			column--;  // Decrement because the arrays actually go from 0 to 2, not 1 to 3
			// printf("\n column = %i \n", column); // Statement for debugging
			// printf("\n board[%i][%i] = %c \n", row, column, board[row][column]); // Statement for debugging
			// printf("\n Player = Player #%i \n", player); // Statement for debugging
			if (player == 1 && board[row][column] == '_') {
				board[row][column] = 'X';
				// printf("\n board[%i][%i] = %c \n", row, column, board[row][column]); // Statement for debugging
				flag = 1;
			} else if (player == 2 && board[row][column] == '_') {
				board[row][column] = 'O';
				// printf("\n board[%i][%i] = %c \n", row, column, board[row][column]); // Statement for debugging
				flag = 2;
			} else if (board[row][column] == 'O') {
				printf("\n That space is taken by O. Please try again. \n");
			} else if (board[row][column] == 'X') {
				printf("\n That space is taken by X. Please try again. \n");
			} else {
				printf("This isn't supposed to happen"); // Just in case
				exit(1); // throw an error to get out of the loop
			}
			// printf("\n Flag = %i \n", flag); // Statement for debugging
			number = 0; // Reset
		}
		printf("\n The board now looks like this: \n");
		display_board(board); // Update board
		won = winner(board); // Check for winner
		// printf("\n won = %i \n", won); // Statement for debugging
		if (won == 1) { // Function winner() should return 1 if player 1 wins
			printf("\n Player 1 wins! \n");
		} else if (won == 2) { // Function winner() should return 2 if player 2 wins
			printf("\n Player 2 wins! \n");
		} else if (won == 3) { // Function winner() should return 3 if it's a tie.
			printf("\n It's a tie. \n");
		} else {
			flag = 0; // Reset
			won = 0;  // Reset
		}
		if (player == 1) { // Switch players (with below)
			player = 2; 
		} else if (player == 2) {
			player = 1;
		} else {
			printf("This isn't supposed to happen"); // Just in case
		}
	}
	printf(" \n "); // just some extra whitespace for no reason
    return 0;
}
