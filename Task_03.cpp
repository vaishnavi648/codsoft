#include <iostream>
#include <vector>

using namespace std;

class TicTacToe
{
public:
    TicTacToe()
    {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
    }

    void playGame()
    {
        bool gameEnded = false;
        while (!gameEnded)
        {
            displayBoard();
            playerInput();
            gameEnded = checkWin() || checkDraw();
            if (!gameEnded)
            {
                switchPlayer();
            }
        }
        displayBoard();
        if (checkWin())
        {
            cout << "Player " << currentPlayer << " wins!" << endl;
        }
        else if (checkDraw())
        {
            cout << "The game is a draw!" << endl;
        }
        if (playAgain())
        {
            resetGame();
            playGame();
        }
    }

private:
    vector<vector<char>> board;
    char currentPlayer;

    void displayBoard()
    {
        cout << "Current board state:" << endl;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cout << board[i][j];
                if (j < 2)
                    cout << " | ";
            }
            cout << endl;
            if (i < 2)
                cout << "---------" << endl;
        }
    }

    void playerInput()
    {
        int row, col;
        while (true)
        {
            cout << "Player " << currentPlayer << ", enter yo1ur move (row and column: 0 1 2): ";
            cin >> row >> col;
            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
            {
                board[row][col] = currentPlayer;
                break;
            }
            else
            {
                cout << "Invalid move, try again." << endl;
            }
        }
    }

    bool checkWin()
    {
        for (int i = 0; i < 3; ++i)
        {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;
        return false;
    }

    bool checkDraw()
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (board[i][j] == ' ')
                {
                    return false;
                }
            }
        }
        return true;
    }

    void switchPlayer()
    {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    bool playAgain()
    {
        char choice;
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        return choice == 'y' || choice == 'Y';
    }

    void resetGame()
    {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
    }
};

int main()
{
    TicTacToe game;
    game.playGame();
    return 0;
}
