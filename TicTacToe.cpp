#include <iostream>
using namespace std;

int moves(char arr[3][3])
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] != ' ')
            {
                count++;
            }
        }
    }
    return count;
}
// Function to check whether a player has won or not
bool checkWin(char arr[3][3], string oponent)
{
    cout << endl
         << endl;
    for (int i = 0; i < 3; i++)
    {
        if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2] && arr[i][0] != ' ')
        {
            if (arr[i][0] == 'X')
            {
                cout << "P1 wins" << endl;
            }
            else
            {
                cout << oponent << " wins" << endl;
            }

            return true;
        }
        else if (arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i] && arr[0][i] != ' ')
        {
            if (arr[0][i] == 'X')
            {
                cout << "P1 wins" << endl;
            }
            else
            {
                cout << oponent << " wins" << endl;
            }

            return true;
        }
    }
    if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && arr[0][0] != ' ')
    {
        if (arr[0][0] == 'X')
        {
            cout << "P1 wins" << endl;
        }
        else
        {
            cout << oponent << " wins" << endl;
        }

        return true;
    }
    else if (arr[0][2] == arr[1][1] && arr[2][0] == arr[0][2] && arr[2][0] != ' ')
    {
        if (arr[2][0] == 'X')
        {
            cout << "P1 wins" << endl;
        }
        else
        {
            cout << oponent << " wins" << endl;
        }
        return true;
    }
    else
    {
        return false;
    }
}
// Function to print the array in form of a tic tac toe board
void printArray(char arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
            if (j == 0 || j == 1)
            {
                cout << "| ";
            }
        }
        cout << endl;
        if (i == 0 || i == 1)
        {
            cout << "---------" << endl;
        }
    }
    cout << endl
         << endl;
}
// Function to let the user pick a position
void userPick(char arr[3][3], char user)
{
    int row = 1, col = 1;
    cout << "Enter the row and column: " << endl
         << endl
         << endl;
    printArray(arr);
    cin >> row >> col;
    if (row < 1 || row > 3 || col < 1 || col > 3 || arr[row - 1][col - 1] != ' ')
    {
        cout << "Enter a valid row and column ,";
        system("cls");
        userPick(arr, user);
    }
    else
    {
        arr[row - 1][col - 1] = user;
    }
}
// function to check whether a player is about to win (used by computer)
string checkPosition(char arr[3][3], char user, char opp)
{
    if (moves(arr) == 1)
    {
        if (arr[0][0] == opp)
        {
            return "22";
        }
        else if (arr[0][2] == opp)
        {
            return "20";
        }
        else if (arr[2][0] == opp)
        {
            return "02";
        }
        else if (arr[2][2] == opp)
        {
            return "00";
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (arr[i][0] == arr[i][1] && (arr[i][0] == user) && (arr[i][2] == ' '))
        {
            return to_string(i) + "2";
        }
        if (arr[i][2] == arr[i][1] && (arr[i][2] == user) && (arr[i][0] == ' '))
        {
            return to_string(i) + "0";
        }
        if (arr[i][0] == arr[i][2] && (arr[i][0] == user) && (arr[i][1] == ' '))
        {
            return to_string(i) + "1";
        }
        if (arr[0][i] == arr[1][i] && (arr[0][i] == user) && (arr[2][i] == ' '))
        {
            return "2" + to_string(i);
        }
        if (arr[2][i] == arr[1][i] && (arr[2][i] == user) && (arr[0][i] == ' '))
        {
            return "0" + to_string(i);
        }
        if (arr[0][i] == arr[2][i] && (arr[0][i] == user) && (arr[1][i] == ' '))
        {
            return "1" + to_string(i);
        }
    }
    if ((arr[0][0] == arr[2][2] && (arr[0][0] == user) && (arr[1][1] == ' ')) || (arr[0][2] == arr[2][0] && (arr[0][2] == user) && (arr[1][1] == ' ')))
    {
        return "11";
    }
    if (arr[1][1] == arr[2][2] && (arr[1][1] == user) && (arr[0][0] == ' '))
    {
        return "00";
    }
    if (arr[0][0] == arr[1][1] && (arr[0][0] == user) && (arr[2][2] == ' '))
    {
        return "22";
    }
    if (arr[0][2] == arr[1][1] && (arr[1][1] == user) && (arr[2][0] == ' '))
    {
        return "20";
    }
    if (arr[2][0] == arr[1][1] && (arr[2][0] == user) && (arr[0][2] == ' '))
    {
        return "02";
    }
    return "none";
}
// Function to check occurence of a character in a cell
string checkCell(char arr[3][3], char user)
{
    string pos = "none";
    if (arr[1][1] == user)
    {
        if (arr[0][0] == ' ' && arr[2][2] == ' ')
        {
            return "00";
        }
        else if (arr[0][2] == ' ' && arr[2][0] == ' ')
        {
            return "20";
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == user)
            {
                int count = 0;
                for (int k = 0; k < 3; k++)
                {
                    if (arr[i][k] == ' ')
                    {
                        count++;
                    }
                }
                if (count == 2)
                {
                    if (j == 0)
                    {
                        return to_string(i) + "1";
                    }
                    else if (j == 2)
                    {
                        return to_string(i) + "0";
                    }
                    else
                    {
                        return to_string(i) + "2";
                    }
                }
                else
                {
                    int count = 0;
                    for (int k = 0; k < 3; k++)
                    {
                        if (arr[k][j] == ' ')
                        {
                            count++;
                        }
                    }
                    if (count == 2)
                    {
                        if (i == 0)
                        {
                            return "1" + to_string(i);
                        }
                        else if (i == 2)
                        {
                            return "0" + to_string(i);
                        }
                        else
                        {
                            return "2" + to_string(i);
                        }
                    }
                }
            }
        }
    }
    return pos;
}
// Function to let the computer pick a position
void computerPick(char arr[3][3], char user, char opp)
{
    if (checkPosition(arr, user, opp) != "none")
    {
        string pos = checkPosition(arr, user, opp);
        int row = pos[0] - '0';
        int col = pos[1] - '0';
        arr[row][col] = user;
    }
    else if (checkPosition(arr, opp, user) != "none")
    {
        string pos = checkPosition(arr, opp, user);
        int row = pos[0] - '0';
        int col = pos[1] - '0';
        arr[row][col] = user;
    }
    else if (checkCell(arr, user) != "none")
    {
        int row = checkCell(arr, user)[0] - '0';
        int col = checkCell(arr, user)[1] - '0';
        arr[row][col] = user;
    }
    else
    {
        if (arr[0][0] == ' ')
        {
            arr[0][0] = user;
        }
        else if (arr[0][2] == ' ')
        {
            arr[0][2] = user;
        }
        else if (arr[2][0] == ' ')
        {
            arr[2][0] = user;
        }
        else if (arr[2][2] == ' ')
        {
            arr[2][2] = user;
        }
        else if (arr[1][1] == ' ')
        {
            arr[1][1] = user;
        }
        else if (arr[0][1] == ' ')
        {
            arr[0][1] = user;
        }
        else if (arr[1][0] == ' ')
        {
            arr[1][0] = user;
        }
        else if (arr[1][2] == ' ')
        {
            arr[1][2] = user;
        }
        else if (arr[2][1] == ' ')
        {
            arr[2][1] = user;
        }
    }
}
// Function to check whether the game is a draw
bool draw(char arr[3][3])
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] != ' ')
            {
                count++;
            }
        }
    }
    if (count == 9)
    {
        cout << "Its a draw" << endl;
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string gameType = "";
    while (true)
    {
        char arr[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
        cout << "Enter the game type 2p for 2 player and 1p for you vs computer type exit to quit" << endl;
        cin >> gameType;
        if (gameType == "exit")
        {
            break;
        }
        else
        {

            if (gameType == "1p")
            {
                char users[2] = {'X', 'O'};
                printArray(arr);
                while (!checkWin(arr, "Computer") && !draw(arr))
                {
                    system("cls");
                    userPick(arr, users[0]);
                    if (!checkWin(arr, "Computer") && !draw(arr))
                    {
                        computerPick(arr, users[1], users[0]);
                        printArray(arr);
                    }
                    else
                    {
                        printArray(arr);
                        break;
                    }
                }
            }
            else if (gameType == "2p")
            {
                char users[2] = {'X', 'O'};
                int turn = 0;
                printArray(arr);
                while (!checkWin(arr, "P2") && !draw(arr))
                {
                    system("cls");
                    userPick(arr, users[turn]);
                    if (turn == 0)
                    {
                        turn = 1;
                    }
                    else
                    {
                        turn = 0;
                    }
                    printArray(arr);
                }
            }
            else
            {
                cout << "Enter a valid game type" << endl;
            }
        }
    }
    return 0;
}