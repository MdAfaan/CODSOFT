//Task.3: Build a simple console-based Tic-Tac-Toe game that allows two players to play against each other.

#include <iostream>

using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

void drawBoard() {
    cout << "Tic-Tac-Toe Board:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "--|---|--" << endl;
    }
}

bool checkWin(char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void makeMove(char player) {
    int move;
    bool validMove = false;
    while (!validMove) {
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> move;
        move--; // Adjust for 0-based index
        int row = move / SIZE;
        int col = move % SIZE;
        if (move >= 0 && move < SIZE * SIZE && board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = player;
            validMove = true;
        } else {
            cout << "Invalid move. Please try again." << endl;
        }
    }
}

int main() {
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    while (!gameWon && !gameDraw) {
        drawBoard();
        makeMove(currentPlayer);
        gameWon = checkWin(currentPlayer);
        if (!gameWon) {
            gameDraw = checkDraw();
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    drawBoard();

    if (gameWon) {
        cout << "Player " << currentPlayer << " wins!" << endl;
    } else {
        cout << "The game is a draw!" << endl;
    }

    return 0;
}
