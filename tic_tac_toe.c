/*
 * TIC-TAC-TOE - Console Edition
 * A polished console-based Tic-Tac-Toe game with enhanced visuals
 * 
 * Features:
 * - Beautiful ASCII art board with colored output
 * - Smart AI opponent with strategic moves
 * - Input validation and error handling
 * - Win/lose/draw detection
 * - Play again functionality
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_SCREEN system("cls")
    #define SLEEP(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define CLEAR_SCREEN system("clear")
    #define SLEEP(ms) usleep(ms * 1000)
#endif

/* Game Constants */
#define BOARD_SIZE 3
#define EMPTY ' '
#define PLAYER_X 'X'
#define PLAYER_O 'O'

/* Color codes for Windows console */
#ifdef _WIN32
    #define COLOR_RESET     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7)
    #define COLOR_RED       SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12)
    #define COLOR_GREEN     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10)
    #define COLOR_YELLOW    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14)
    #define COLOR_BLUE      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9)
    #define COLOR_CYAN      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11)
    #define COLOR_MAGENTA   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13)
#else
    #define COLOR_RESET     printf("\033[0m")
    #define COLOR_RED       printf("\033[1;31m")
    #define COLOR_GREEN     printf("\033[1;32m")
    #define COLOR_YELLOW    printf("\033[1;33m")
    #define COLOR_BLUE      printf("\033[1;34m")
    #define COLOR_CYAN      printf("\033[1;36m")
    #define COLOR_MAGENTA   printf("\033[1;35m")
#endif

/* Global Variables */
char board[BOARD_SIZE][BOARD_SIZE];
char currentPlayer;
int playerScore = 0;
int computerScore = 0;
int draws = 0;

/* Function Prototypes */
void initializeBoard(void);
void displayBoard(void);
void displayTitle(void);
void displayScoreboard(void);
int isValidMove(int row, int col);
int isBoardFull(void);
char checkWinner(void);
void playerMove(void);
void computerMove(void);
void displayResult(char winner);
int playAgain(void);
void displayInstructions(void);

/* Initialize the board with empty spaces */
void initializeBoard(void) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

/* Display the game title with ASCII art */
void displayTitle(void) {
    COLOR_CYAN;
    printf("\n");
    printf("  ╔════════════════════════════════════════════╗\n");
    printf("  ║                                            ║\n");
    printf("  ║     ████████╗██╗ ██████╗                   ║\n");
    printf("  ║     ╚══██╔══╝██║██╔════╝                   ║\n");
    printf("  ║        ██║   ██║██║                        ║\n");
    printf("  ║        ██║   ██║██║                        ║\n");
    printf("  ║        ██║   ██║╚██████╗                   ║\n");
    printf("  ║        ╚═╝   ╚═╝ ╚═════╝                   ║\n");
    printf("  ║     ████████╗ █████╗  ██████╗              ║\n");
    printf("  ║     ╚══██╔══╝██╔══██╗██╔════╝              ║\n");
    printf("  ║        ██║   ███████║██║                   ║\n");
    printf("  ║        ██║   ██╔══██║██║                   ║\n");
    printf("  ║        ██║   ██║  ██║╚██████╗              ║\n");
    printf("  ║        ╚═╝   ╚═╝  ╚═╝ ╚═════╝              ║\n");
    printf("  ║     ████████╗ ██████╗ ███████╗             ║\n");
    printf("  ║     ╚══██╔══╝██╔═══██╗██╔════╝             ║\n");
    printf("  ║        ██║   ██║   ██║█████╗               ║\n");
    printf("  ║        ██║   ██║   ██║██╔══╝               ║\n");
    printf("  ║        ██║   ╚██████╔╝███████╗             ║\n");
    printf("  ║        ╚═╝    ╚═════╝ ╚══════╝             ║\n");
    printf("  ║                                            ║\n");
    printf("  ╚════════════════════════════════════════════╝\n");
    COLOR_RESET;
}

/* Display the scoreboard */
void displayScoreboard(void) {
    printf("\n");
    COLOR_YELLOW;
    printf("  ┌─────────── SCOREBOARD ───────────┐\n");
    printf("  │                                  │\n");
    COLOR_GREEN;
    printf("  │   Player (X): %-3d                │\n", playerScore);
    COLOR_RED;
    printf("  │   Computer (O): %-3d              │\n", computerScore);
    COLOR_BLUE;
    printf("  │   Draws: %-3d                     │\n", draws);
    COLOR_YELLOW;
    printf("  │                                  │\n");
    printf("  └──────────────────────────────────┘\n");
    COLOR_RESET;
}

/* Display the game board with enhanced visuals */
void displayBoard(void) {
    printf("\n");
    COLOR_CYAN;
    printf("       1     2     3\n");
    printf("    ╔═════╦═════╦═════╗\n");
    COLOR_RESET;
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        COLOR_CYAN;
        printf("    ║     ║     ║     ║\n");
        printf("  %d ", i + 1);
        printf("║");
        COLOR_RESET;
        
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == PLAYER_X) {
                COLOR_GREEN;
                printf("  %c  ", board[i][j]);
                COLOR_RESET;
            } else if (board[i][j] == PLAYER_O) {
                COLOR_RED;
                printf("  %c  ", board[i][j]);
                COLOR_RESET;
            } else {
                printf("     ");
            }
            COLOR_CYAN;
            printf("║");
            COLOR_RESET;
        }
        printf("\n");
        
        COLOR_CYAN;
        printf("    ║     ║     ║     ║\n");
        
        if (i < BOARD_SIZE - 1) {
            printf("    ╠═════╬═════╬═════╣\n");
        } else {
            printf("    ╚═════╩═════╩═════╝\n");
        }
        COLOR_RESET;
    }
    printf("\n");
}

/* Check if a move is valid */
int isValidMove(int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return 0;
    }
    return board[row][col] == EMPTY;
}

/* Check if the board is full */
int isBoardFull(void) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

/* Check for a winner */
char checkWinner(void) {
    /* Check rows */
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != EMPTY && 
            board[i][0] == board[i][1] && 
            board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    
    /* Check columns */
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] != EMPTY && 
            board[0][i] == board[1][i] && 
            board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    
    /* Check diagonals */
    if (board[0][0] != EMPTY && 
        board[0][0] == board[1][1] && 
        board[1][1] == board[2][2]) {
        return board[0][0];
    }
    
    if (board[0][2] != EMPTY && 
        board[0][2] == board[1][1] && 
        board[1][1] == board[2][0]) {
        return board[0][2];
    }
    
    return EMPTY;
}

/* Handle player's move */
void playerMove(void) {
    int row, col;
    
    COLOR_GREEN;
    printf("  Your turn (X)\n");
    COLOR_RESET;
    
    while (1) {
        printf("  Enter row (1-3): ");
        if (scanf("%d", &row) != 1) {
            while (getchar() != '\n'); /* Clear input buffer */
            COLOR_RED;
            printf("  Invalid input! Please enter a number.\n");
            COLOR_RESET;
            continue;
        }
        
        printf("  Enter column (1-3): ");
        if (scanf("%d", &col) != 1) {
            while (getchar() != '\n'); /* Clear input buffer */
            COLOR_RED;
            printf("  Invalid input! Please enter a number.\n");
            COLOR_RESET;
            continue;
        }
        
        /* Convert to 0-indexed */
        row--;
        col--;
        
        if (isValidMove(row, col)) {
            board[row][col] = PLAYER_X;
            break;
        } else {
            COLOR_RED;
            printf("  Invalid move! Try again.\n");
            COLOR_RESET;
        }
    }
}

/* Smart AI computer move */
void computerMove(void) {
    int row, col;
    int bestRow = -1, bestCol = -1;
    
    COLOR_YELLOW;
    printf("  Computer is thinking");
    for (int i = 0; i < 3; i++) {
        SLEEP(300);
        printf(".");
        fflush(stdout);
    }
    printf("\n");
    COLOR_RESET;
    
    /* Strategy 1: Check if computer can win */
    for (row = 0; row < BOARD_SIZE; row++) {
        for (col = 0; col < BOARD_SIZE; col++) {
            if (isValidMove(row, col)) {
                board[row][col] = PLAYER_O;
                if (checkWinner() == PLAYER_O) {
                    return; /* Winning move found */
                }
                board[row][col] = EMPTY;
            }
        }
    }
    
    /* Strategy 2: Block player from winning */
    for (row = 0; row < BOARD_SIZE; row++) {
        for (col = 0; col < BOARD_SIZE; col++) {
            if (isValidMove(row, col)) {
                board[row][col] = PLAYER_X;
                if (checkWinner() == PLAYER_X) {
                    board[row][col] = PLAYER_O;
                    return; /* Blocking move */
                }
                board[row][col] = EMPTY;
            }
        }
    }
    
    /* Strategy 3: Take center if available */
    if (isValidMove(1, 1)) {
        board[1][1] = PLAYER_O;
        return;
    }
    
    /* Strategy 4: Take a corner */
    int corners[4][2] = {{0,0}, {0,2}, {2,0}, {2,2}};
    for (int i = 0; i < 4; i++) {
        if (isValidMove(corners[i][0], corners[i][1])) {
            board[corners[i][0]][corners[i][1]] = PLAYER_O;
            return;
        }
    }
    
    /* Strategy 5: Take any available edge */
    int edges[4][2] = {{0,1}, {1,0}, {1,2}, {2,1}};
    for (int i = 0; i < 4; i++) {
        if (isValidMove(edges[i][0], edges[i][1])) {
            board[edges[i][0]][edges[i][1]] = PLAYER_O;
            return;
        }
    }
}

/* Display the game result */
void displayResult(char winner) {
    printf("\n");
    if (winner == PLAYER_X) {
        COLOR_GREEN;
        printf("  ╔═══════════════════════════════════╗\n");
        printf("  ║                                   ║\n");
        printf("  ║      CONGRATULATIONS!             ║\n");
        printf("  ║      YOU WIN!                     ║\n");
        printf("  ║                                   ║\n");
        printf("  ╚═══════════════════════════════════╝\n");
        playerScore++;
    } else if (winner == PLAYER_O) {
        COLOR_RED;
        printf("  ╔═══════════════════════════════════╗\n");
        printf("  ║                                   ║\n");
        printf("  ║      GAME OVER!                   ║\n");
        printf("  ║      COMPUTER WINS!               ║\n");
        printf("  ║                                   ║\n");
        printf("  ╚═══════════════════════════════════╝\n");
        computerScore++;
    } else {
        COLOR_YELLOW;
        printf("  ╔═══════════════════════════════════╗\n");
        printf("  ║                                   ║\n");
        printf("  ║      IT'S A DRAW!                 ║\n");
        printf("  ║      WELL PLAYED!                 ║\n");
        printf("  ║                                   ║\n");
        printf("  ╚═══════════════════════════════════╝\n");
        draws++;
    }
    COLOR_RESET;
}

/* Ask if player wants to play again */
int playAgain(void) {
    char choice;
    
    printf("\n");
    COLOR_CYAN;
    printf("  Play again? (Y/N): ");
    COLOR_RESET;
    
    while (getchar() != '\n'); /* Clear input buffer */
    scanf("%c", &choice);
    
    return (choice == 'Y' || choice == 'y');
}

/* Display game instructions */
void displayInstructions(void) {
    COLOR_YELLOW;
    printf("\n  ┌─────────── HOW TO PLAY ───────────┐\n");
    printf("  │                                   │\n");
    printf("  │  1. You are X, Computer is O      │\n");
    printf("  │  2. Enter row (1-3) and column    │\n");
    printf("  │     (1-3) to place your mark      │\n");
    printf("  │  3. Get 3 in a row to win!        │\n");
    printf("  │                                   │\n");
    printf("  └───────────────────────────────────┘\n");
    COLOR_RESET;
}

/* Main game loop */
int main(void) {
    char winner;
    int gameActive;
    
    srand((unsigned int)time(NULL));
    
    do {
        CLEAR_SCREEN;
        displayTitle();
        displayScoreboard();
        displayInstructions();
        
        initializeBoard();
        winner = EMPTY;
        gameActive = 1;
        
        printf("\n  Press ENTER to start...");
        while (getchar() != '\n');
        getchar();
        
        while (gameActive) {
            CLEAR_SCREEN;
            displayTitle();
            displayScoreboard();
            displayBoard();
            
            /* Player's turn */
            playerMove();
            winner = checkWinner();
            
            if (winner != EMPTY || isBoardFull()) {
                gameActive = 0;
                break;
            }
            
            CLEAR_SCREEN;
            displayTitle();
            displayScoreboard();
            displayBoard();
            
            /* Computer's turn */
            computerMove();
            winner = checkWinner();
            
            if (winner != EMPTY || isBoardFull()) {
                gameActive = 0;
            }
        }
        
        CLEAR_SCREEN;
        displayTitle();
        displayBoard();
        displayResult(winner);
        displayScoreboard();
        
    } while (playAgain());
    
    CLEAR_SCREEN;
    displayTitle();
    displayScoreboard();
    
    COLOR_CYAN;
    printf("\n  Thanks for playing! Goodbye!\n\n");
    COLOR_RESET;
    
    return 0;
}
