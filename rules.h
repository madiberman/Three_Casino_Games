#include <iostream>
#include <cstdlib>

using namespace std;

int gameChoice;

void printRules()
{
    //while loop breaks when the Player inputs a valid selection
    while (true)
    {
        cout << "[0] Guess the Number\n\n";
        cout << "[1] Slot Machine\n\n";
        cout << "[2] Blackjack\n\n";
        cout << "[3] Cashout & Quit\n\n";
        cin >> gameChoice;

        //print rules based on the game chosen
        if (gameChoice == 0)
        {
            cout << "\nTo play Guess the Number, input a number between [1-10]\nIf you guess correctly, you win 10x your bet amount!";
            break;
        }
        else if (gameChoice == 1)
        {
            cout << "\nIf you get one (1) SEVEN, you will break even,\nIf you get two (2) SEVENS or three (3) of the same fruit, you will win double your bet\nIf you get three SEVENS, you will win triple your bet";
            break;
        }
        else if (gameChoice == 2)
        {
            cout << "\nThe aim of Blackjack is to keep your total value under or equal to 21\nYou will play against a dealer & you will each start with two cards\nCard values match the card if it is numberical\nFace cards are worth 10 points\nAn Ace is worth 1 or 11 points (Player's choice)";
            break;
        }
        else if (gameChoice == 3)
        {
            break;
        }
        //loop will repeat here
        else
        {
            cout << "\nPlease select from the following options:\n\n";
        }
    }
}

//for encapsulation
int getGameChoice()
{
    return gameChoice;
}
