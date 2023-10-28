#include <iostream>
#include "Functions.h"
using namespace std;

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