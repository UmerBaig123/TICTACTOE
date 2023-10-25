#include <iostream>
// #include <windows.h>
using namespace std;

bool checkWin(char arr[3][3], string oponent)
{
    cout << endl
         << endl;
    if (((arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2]) || (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0])) && (arr[0][0] != ' '))
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
    else if (((arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2]) || (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1])) && (arr[1][1] != ' '))
    {
        if (arr[1][1] == 'X')
        {
            cout << "P1 wins" << endl;
        }
        else
        {
            cout << oponent << " wins" << endl;
        }

        return true;
    }
    else if (((arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2]) || (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2])) && (arr[2][2] != ' '))
    {
        if (arr[2][2] == 'X')
        {
            cout << "P1 wins" << endl;
        }
        else
        {
            cout << oponent << " wins" << endl;
        }
        return true;
    }
    else if (((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) || (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])) && (arr[1][1] != ' '))
    {
        if (arr[1][1] == 'X')
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
string checkPosition(char arr[3][3], char user)
{
    if ((arr[0][0] == arr[0][1]) && (arr[0][0] == user) && (arr[0][2] == ' '))
    {
        return "02";
    }
    else if ((arr[0][1] == arr[0][2]) && (arr[0][1] == user) && (arr[0][0] == ' '))
    {
        return "00";
    }
    else if ((arr[0][0] == arr[0][2]) && (arr[0][0] == user) && (arr[0][1] == ' '))
    {
        return "01";
    }
    else if ((arr[1][0] == arr[1][1]) && (arr[1][0] == user) && (arr[1][2] == ' '))
    {
        return "12";
    }
    else if ((arr[1][1] == arr[1][2]) && (arr[1][1] == user) && (arr[1][0] == ' '))
    {
        return "10";
    }
    else if ((arr[1][0] == arr[1][2]) && (arr[1][0] == user) && (arr[1][1] == ' '))
    {
        return "11";
    }
    else if ((arr[2][0] == arr[2][1]) && (arr[2][0] == user) && (arr[2][2] == ' '))
    {
        return "22";
    }
    else if ((arr[2][1] == arr[2][2]) && (arr[2][1] == user) && (arr[2][0] == ' '))
    {
        return "20";
    }
    else if ((arr[2][0] == arr[2][2]) && (arr[2][0] == user) && (arr[2][1] == ' '))
    {
        return "21";
    }
    else if ((arr[0][0] == arr[1][0]) && (arr[0][0] == user) && (arr[2][0] == ' '))
    {
        return "20";
    }
    else if ((arr[1][0] == arr[2][0]) && (arr[1][0] == user) && (arr[0][0] == ' '))
    {
        return "00";
    }
    else if ((arr[0][0] == arr[2][0]) && (arr[0][0] == user) && (arr[1][0] == ' '))
    {
        return "10";
    }
    else if ((arr[0][1] == arr[1][1]) && (arr[0][1] == user) && (arr[2][1] == ' '))
    {
        return "21";
    }
    else if ((arr[1][1] == arr[2][1]) && (arr[1][1] == user) && (arr[0][1] == ' '))
    {
        return "01";
    }
    else if ((arr[0][1] == arr[2][1]) && (arr[0][1] == user) && (arr[1][1] == ' '))
    {
        return "11";
    }
    else if ((arr[0][2] == arr[1][2]) && (arr[0][2] == user) && (arr[2][2] == ' '))
    {
        return "22";
    }
    else if ((arr[1][2] == arr[2][2]) && (arr[1][2] == user) && (arr[0][2] == ' '))
    {
        return "02";
    }
    else if ((arr[0][2] == arr[2][2]) && (arr[0][2] == user) && (arr[1][2] == ' '))
    {
        return "12";
    }
    else if ((arr[0][0] == arr[1][1]) && (arr[0][0] == user) && (arr[2][2] == ' '))
    {
        return "22";
    }
    else if ((arr[1][1] == arr[2][2]) && (arr[1][1] == user) && (arr[0][0] == ' '))
    {
        return "00";
    }
    else if ((((arr[0][0] == arr[2][2]) && (arr[0][0] == user)) || ((arr[2][0] == arr[0][2]) && (arr[2][0] == user))) && (arr[1][1] == ' '))
    {
        return "11";
    }
    else if ((arr[0][2] == arr[1][1]) && (arr[0][2] == user) && (arr[2][0] == ' '))
    {
        return "20";
    }
    else if ((arr[1][1] == arr[2][0]) && (arr[1][1] == user) && (arr[0][2] == ' '))
    {
        return "02";
    }
    else
    {
        return "none";
    }
}
void computerPick(char arr[3][3], char user, char opp)
{
    if (checkPosition(arr, user) != "none")
    {
        string pos = checkPosition(arr, user);
        int row = pos[0] - '0';
        int col = pos[1] - '0';
        arr[row][col] = user;
    }
    else if (checkPosition(arr, opp) != "none")
    {
        string pos = checkPosition(arr, opp);
        int row = pos[0] - '0';
        int col = pos[1] - '0';
        arr[row][col] = user;
    }
    else if (arr[1][1] == ' ')
    {
        arr[1][1] = user;
    }
    else if (arr[0][0] == ' ')
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