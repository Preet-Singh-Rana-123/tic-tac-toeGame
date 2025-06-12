#include <iostream>
using namespace std;

char currentPlayer;
void showInstructionBoard(int arr[3][3])
{
    int a = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = a;
            a++;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << "|";
        }
        cout << endl;
    }
}

void showGameBoard(char arr[3][3])
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << "|";
        }
        cout << endl;
    }
}

void switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void makeMove(int move, char gameBoard[3][3])
{
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    gameBoard[row][col] = currentPlayer;
}

bool checkWinner(char arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (
            arr[i][0] == currentPlayer &&
            arr[i][1] == currentPlayer &&
            arr[i][2] == currentPlayer)
        {
            return 1;
        }
        if (
            arr[0][i] == currentPlayer &&
            arr[1][i] == currentPlayer &&
            arr[2][i] == currentPlayer)
        {
            return 1;
        }
    }

    if (
        arr[0][0] == currentPlayer &&
        arr[1][1] == currentPlayer &&
        arr[2][2] == currentPlayer)
    {
        return 1;
    }
    if (
        arr[0][2] == currentPlayer &&
        arr[1][1] == currentPlayer &&
        arr[2][0] == currentPlayer)
    {
        return 1;
    }

    return 0;
}

bool checkDraw(char arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] != 'X' && arr[i][j] != 'O')
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{

    cout << "TIC-TAC_TOE Game" << endl;
    cout << "Player 1 is X and Player 2 is O" << endl;
    cout << "INSTUCTION:" << " player will give input of location based on bellow board." << endl;
    int arr[3][3];
    showInstructionBoard(arr);

    char restartGame = 'y';

    while (restartGame == 'y')
    {
        char gameBoard[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                gameBoard[i][j] = ' ';
            }
        }

        int move;
        currentPlayer = 'X';

        while (true)
        {
            cout << "Player " << currentPlayer << " turn: ";
            cin >> move;

            makeMove(move, gameBoard);
            showGameBoard(gameBoard);

            if (checkWinner(gameBoard))
            {
                showGameBoard(gameBoard);
                cout << "Player " << currentPlayer << " wins!!" << endl;
                break;
            }
            if (checkDraw(gameBoard))
            {
                showGameBoard(gameBoard);
                cout << "Game Draw!!" << endl;
                break;
            }

            switchPlayer();
        }
        cout << "Do you want to play again (y/n): ";
        cin >> restartGame;
    }

    return 0;
}