//I tried to make this Tic-tac-toe game in C, so enjoy this game and hope you like this.

#include <stdio.h>   // Provides standard input and output functions
#include <ctype.h>   // Provides character handling functions (not used in this code)
#include <stdlib.h>  // Provides functions like rand(), srand(), and system commands
#include <time.h>    // Provides time functions to seed random number generator

// Global variables to represent the game board and players
char board[3][3];             // 3x3 board for the Tic Tac Toe game
const char PLAYER = 'X';      // Symbol for the player
const char COMPUTER = 'O';    // Symbol for the computer

// Function declarations
void resetBoard();            // Resets the game board to its initial state
void printBoard();            // Prints the current state of the board
int checkFreeSpaces();        // Counts the number of free spaces on the board
void playerMove();            // Handles the player's move
void computerMove();          // Handles the computer's move
char checkWinner();           // Checks if there's a winner
void printWinner(char);       // Prints the result of the game

int main() {
    printf("\n\n");
    printf("****************************************************\n");
    printf("         Welcome to the Tic Tac Toe game!           \n");
    printf("****************************************************\n");
    printf("\n* Instructions \n\n");
    printf("\tPlayer 1 sign = X\n");
    printf("\tPlayer 2 sign = O\n\n");

    char winner = ' ';  // Variable to store the winner ('X', 'O', or ' ' for no winner)

    resetBoard();  // Initialize the game board

    // Main game loop: runs until there's a winner or no free spaces
    while (winner == ' ' && checkFreeSpaces() != 0) {
        printBoard();  // Display the current board

        playerMove();  // Player makes their move
        winner = checkWinner();  // Check if the player won
        if (winner != ' ' || checkFreeSpaces() == 0) {
            break;  // Exit the loop if the game is over
        }

        computerMove();  // Computer makes its move
        winner = checkWinner();  // Check if the computer won
        if (winner != ' ' || checkFreeSpaces() == 0) {
            break;  // Exit the loop if the game is over
        }
    }

    printBoard();  // Display the final board
    printWinner(winner);  // Announce the result

    return 0;  // Exit the program
}

// Resets the board to its initial empty state
void resetBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';  // Fill each cell with a space
        }
    }
}

// Prints the current state of the board
void printBoard() {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n\n");
}

// Counts and returns the number of free spaces on the board
int checkFreeSpaces() {
    int freeSpaces = 9;  // Start with all spaces free
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != ' ') {
                freeSpaces--;  // Reduce count for each occupied space
            }
        }
    }
    return freeSpaces;
}

// Handles the player's move
void playerMove() {
    int x, y;

    do {
        printf("Enter row #(1-3): ");
        scanf("%d", &x);
        x--;  // Adjust for 0-based indexing
        printf("Enter column #(1-3): ");
        scanf("%d", &y);
        y--;  // Adjust for 0-based indexing
        printf("\n");

        if (board[x][y] != ' ') {  // Check if the cell is already occupied
            printf("Invalid move! Try again!\n");
            printf("\n");
        } else {
            board[x][y] = PLAYER;  // Place the player's symbol
            break;
        }
    } while (board[x][y] != ' ');  // Repeat until a valid move is made
}

// Handles the computer's move
void computerMove() {
    srand(time(NULL));  // Seed the random number generator
    int x, y;

    if (checkFreeSpaces() > 0) {  // Ensure there are free spaces
        do {
            x = rand() % 3;  // Generate a random row index (0-2)
            y = rand() % 3;  // Generate a random column index (0-2)
        } while (board[x][y] != ' ');  // Repeat if the cell is occupied

        board[x][y] = COMPUTER;  // Place the computer's symbol
    }
}

// Checks if there's a winner and returns the winning symbol or ' ' if no winner
char checkWinner() {
    // Check rows for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];  // Return the winner's symbol
        }
    }

    // Check columns for a win
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return board[0][i];  // Return the winner's symbol
        }
    }

    // Check diagonals for a win
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];  // Return the winner's symbol
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];  // Return the winner's symbol
    }

    return ' ';  // Return ' ' if there's no winner
}

// Prints the result of the game based on the winner
void printWinner(char winner) {
    if (winner == PLAYER) {
        printf("\n\t --- Game Over --- \n");
        printf("  *** Congratulations, You won!! ***\n");
        printf(":: Thanks for playing Tic Tac Toe game! :: \n");
    } else if (winner == COMPUTER) {
        printf("\n\t --- Game Over --- \n");
        printf("  *** Sorry, you lost. Better luck next time! ***\n");
        printf(":: Thanks for playing Tic Tac Toe game! :: \n");
    } else {
        printf("\n\t --- Game Over --- \n");
        printf("  *** It's a tie! ***\n");
        printf(":: Thanks for playing Tic Tac Toe game! :: \n");
    }
}


