#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;
int s;
void displaymenu(int s) {
        system("cls"); //to clear screen
        
        if (s == 1) {
            cout << "\t\t\t\t\t\t   Welcome to Tic-Tac-Toe!" << endl;
            cout << "\t\t\t\t\t\t   Select an option:" << endl;
            cout << "\t\t\t\t\t\t=> 1. One player (against computer)" << endl;
            cout << "\t\t\t\t\t\t   2. Two players" << endl;
        } else if (s == 2) {
            cout << "\t\t\t\t\t\t   Welcome to Tic-Tac-Toe!" << endl;
            cout << "\t\t\t\t\t\t   Select an option:" << endl;
            cout << "\t\t\t\t\t\t   1. One player (against computer)" << endl;
            cout << "\t\t\t\t\t\t=> 2. Two players" << endl;
        }
    }


class TicTacToe {
public:
    int playGame() {
        int select = 1;
        int keypressed;
    while (true) {
        displaymenu(select);
        keypressed = (int)getch();
        if (keypressed == 224) {
            keypressed = (int)getch(); // Read the actual key code
            if (keypressed == 80 && select != 2) // Down arrow
                select++;
            else if (keypressed == 72 && select != 1) // Up arrow
                select--;
        }
        else if (keypressed == 13) //for enter
            return select;
        else if ((select == 1 && keypressed == 72) || (select == 2 && keypressed == 80))
            cout << "\a";
        
    }
        }
        void playSinglePlayer() {
        Board board;
        int row, col;
        char player = 'X';

        while (!board.isTerminal() && !board.isFull()) {
            system("cls");
            cout << "\tSingle Player Mode - Player: " << player << endl;
            board.printBoard();

            if (player == 'X') {
                getPlayerMove(board, row, col);
                player = 'O';
            } else {
                computerMove(board);
                player = 'X';
            }
        }

        system("cls");
        cout << "\t\tSingle Player Mode" << endl;
        board.printBoard();
        int score = board.evaluate();

        if (score == 0) {
            cout << "\t\t\t\t\tIt's a draw!" << endl;
            cout<<"\t\tpress escape to exit, or any other key to return to main menu"<<endl;
        } else if (score == 10) {
            cout << "\t\t\t\t\tComputer wins!" << endl;
            cout<<"\t\tpress escape to exit, or any other key to return to main menu"<<endl;
        } else if (score == -10) {
            cout << "\t\t\t\t\tYou win!" << endl;\
            cout<<"\t\tpress escape to exit, or any other key to return to main menu"<<endl;
        }
    }

    void playTwoPlayers() {
    Board board;
    int row, col;
    char player = 'X';

    while (!board.isTerminal() && !board.isFull()) {
        system("cls");
        cout << "\t\t\t\t\tTwo Players Mode - Player: " << player << endl;
        board.printBoard();
        getPlayerMove(board, row, col);
        board.cells[row - 1][col - 1] = player;  // Update the board with the player's move
        player = (player == 'X') ? 'O' : 'X';
    }

    system("cls");
    cout << "Two Players Mode " << endl;
    board.printBoard();
    int score = board.evaluate();

    if (score == 0) {
        cout << "\t\t\t\t\tIt's a draw!" << endl;
        cout << "\t\tPress escape to exit, or any other key to return to the main menu" << endl;
    } else if (score == 10) {
        cout << "\t\t\t\t\tPlayer O wins!" << endl;
        cout << "\t\tPress escape to exit, or any other key to return to the main menu" << endl;
    } else if (score == -10) {
        cout << "\t\t\t\t\tPlayer X wins!" << endl;
        cout << "\t\tPress escape to exit, or any other key to return to the main menu" << endl;
    }
}


private:
    struct Board {
        char cells[3][3];

        Board() {
            reset();
        }

        void reset() {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    cells[i][j] = ' ';
                }
            }
        }

        bool isFull() const {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (cells[i][j] == ' ') {
                        return false;
                    }
                }
            }
            return true;
        }

        bool isTerminal() const {
            return evaluate() != 0;
        }

        int evaluate() const {
            // Check rows
            for (int i = 0; i < 3; ++i) {
                if (cells[i][0] == cells[i][1] && cells[i][0] == cells[i][2]) {
                    if (cells[i][0] == 'X') {
                        return -10;
                    } else if (cells[i][0] == 'O') {
                        return 10;
                    }
                }
            }

            // Check columns
            for (int j = 0; j < 3; ++j) {
                if (cells[0][j] == cells[1][j] && cells[0][j] == cells[2][j]) {
                    if (cells[0][j] == 'X') {
                        return -10;
                    } else if (cells[0][j] == 'O') {
                        return 10;
                    }
                }
            }

            // Check diagonals
            if (cells[0][0] == cells[1][1] && cells[0][0] == cells[2][2]) {
                if (cells[0][0] == 'X') {
                    return -10;
                } else if (cells[0][0] == 'O') {
                    return 10;
                }
            }
            if (cells[0][2] == cells[1][1] && cells[0][2] == cells[2][0]) {
                if (cells[0][2] == 'X') {
                    return -10;
                } else if (cells[0][2] == 'O') {
                    return 10;
                }
            }

            return 0; // Game is a draw
        }

        void printBoard() const {
            //cout<<"---------";
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    //cout<<"\t\t\t\t\t";
                    
                    cout <<cells[i][j];
                    
                    if (j < 2 ) {
                        //cout<<"\t\t\t\t\t";
                        cout << " | ";
                    }
                            }
                cout << endl;
                if (i < 2) {
                    cout << "---------" << endl;
                }
            }
            cout << endl;
        }
    };

    // void displayMenu(int s) {
    //     system("cls");
        
    //     if (s == 1) {
    //         cout << "\t\t\t\t\t   Welcome to Tic-Tac-Toe!" << endl;
    //         cout << "\t\t\t\t\t   Select an option:" << endl;
    //         cout << "\t\t\t\t\t=> 1. One player (against computer)" << endl;
    //         cout << "\t\t\t\t\t   2. Two players" << endl;
    //     } else if (s == 2) {
    //         cout << "\t\t\t\t\t   Welcome to Tic-Tac-Toe!" << endl;
    //         cout << "\t\t\t\t\t   Select an option:" << endl;
    //         cout << "\t\t\t\t\t   1. One player (against computer)" << endl;
    //         cout << "\t\t\t\t\t=> 2. Two players" << endl;
    //     }
    // }

    

    void getPlayerMove(Board& board, int& row, int& col) {
        while (true) {
            cout << "Enter the row (1 3): ";
            cin >> row;
            if (row < 1 || row > 3) {
                cout << "Invalid row. Please try again." << endl;
                continue;
            }
            cout << "Enter the column (1 3): ";
            cin >> col;

            if (col < 1 || col > 3) {
                cout << "Invalid column. Please try again." << endl;
                continue;
            }
            if (board.cells[row - 1][col - 1] != ' ') {
                cout << "Already occupied. Please try again." << endl;
                continue;
            }
            break;
        }
        board.cells[row - 1][col - 1] = 'X';
    }

    void computerMove(Board& board) {
        int bestScore = INT_MIN;
        int bestRow = -1;
        int bestCol = -1;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board.cells[i][j] == ' ') {
                    board.cells[i][j] = 'O';
                    //fill box to check whether this move is advantage for computer or not
                    int score = minimax(board, 0, false);
                    //this calls minmax function whether this move is increasing score
                    board.cells[i][j] = ' ';
                    //removing the "O" to make sure the board is same as before
                    if (score > bestScore) {
                        bestScore = score;
                        bestRow = i;
                        bestCol = j;}
                }
            }
        }board.cells[bestRow][bestCol] = 'O';
        //and then fill the box with the move which yeilds in maximum score
    }

    int minimax(Board& board, int depth, bool isMaximizingPlayer) {
        int score = board.evaluate();
        if (score != 0) {
            return score;}
        if (board.isFull()) {
            return 0;
        }
        if (isMaximizingPlayer) {
            //setting bestscore to minimum and then increasing it by heuristic approach
            int bestScore = INT_MIN;

            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (board.cells[i][j] == ' ') {
                        board.cells[i][j] = 'O';
                        int currentScore = minimax(board, depth + 1, false);
                        board.cells[i][j] = ' ';
                        bestScore = max(bestScore, currentScore);
                    }
                }
            }
            return bestScore; //returning the best score to computermove function

        } else {     //same as above but this time checking for X player(user)
            int bestScore = INT_MAX;

            for (int i = 0; i < 3; ++i) {
                
                for (int j = 0; j < 3; ++j) {
                    if (board.cells[i][j] == ' ') {
                        board.cells[i][j] = 'X';
                        int currentScore = minimax(board, depth + 1, true);
                        board.cells[i][j] = ' ';
                        bestScore = min(bestScore, currentScore);
                    }
                }
            }

            return bestScore;
        }
    }
};

int main() {
    int gamestop = 0;
    while (gamestop != 27) {
        TicTacToe game;
        int selectedOption = game.playGame();

        if (selectedOption == 1) {
            game.playSinglePlayer();
        } else if (selectedOption == 2) {
            game.playTwoPlayers();
        }
        gamestop = getch();  // Use getch() to get the ASCII value of the pressed key
        system("cls");
    }
    return 0;
}