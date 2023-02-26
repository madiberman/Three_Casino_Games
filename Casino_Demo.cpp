#include <iostream>
#include <cstdlib>
#include <istream>
#include <string>
#include "betOutcome.h"
#include "gameChoice.h"
#include "rules.h"

using namespace std;

int totalMoney;
int bettingMoney;

int main()
{
    cout << "\n\nWelcome to Madi's C++ Casino\n\n";

    // this while loop only breaks if a numeric value is entered
    while (true)
    {
        cout << "Please insert cash: \n£";
        cin >> totalMoney;
        cout << "\n\n";

        // if the cin succeeds in taking totalMoney (an int)
        if (!cin.fail())
        {
            break;
        }
        // if the cin is a non-integer: clear the cin and ignore it, run an error
        // will repeat the while loop and prompt the user for input again
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: ";
        }
    }

    // this while loop breaks when the Player has quit or runs out of money
    while (true)
    {
        // break if the Player runs out of money
        if (totalMoney == 0)
        {
            cout << "All out of money!\n";
            cout << "Thank you for playing!\n\n";
            break;
        }

        cout << "\n\nWhich game would you like to play?\n\n";
        printRules();
        cout << "\n\n";

        // game choice 3 == cashout & quit option
        if (getGameChoice() == 3)
        {
            cout << "Thank you for playing!\n";
            cout << "Total cashout: £" << totalMoney << "\n\n";
            break;
        }

        while (true)
        {
            // this while loop breaks when the Player inputs a valid bet
            while (true)
            {
                cout << "How much would you like to bet?\n£";
                cin >> bettingMoney;
                cout << "\n\n";

                // if the cin succeeds and the bet is less than the money the Player has left
                if (!cin.fail() && bettingMoney <= totalMoney)
                {
                    break;
                }
                // clear and ignore all Player entries if they attempt to bet more than they have
                // will repeat the while loop and prompt the user for input again
                else if (bettingMoney > totalMoney)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: you do not have enough funds\n";
                }
                // clear and ignore all player entries and run an error
                // will repeat the while loop and prompt the user for input again
                else
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: ";
                }
            }

            int playAgain;
            
            // runs the game based on the number input by the Player
            // gameChoice.h for game() & rules.h for the getGameChoice()
            game(getGameChoice(), bettingMoney, totalMoney);
            totalMoney = totalAfterBet();

            // if game ends and Player has run out of mouney, while loop breaks
            if (totalMoney == 0)
            {
                break;
            }

            // while loop breaks after the user correctly chooses whether or not to play again
            while (true)
            {
                cout << "Would you like to play again? [0 = yes / 1 = no]\n";
                cin >> playAgain;
                cout << "\n\n";

                // if the cin succeeds and the Player entered an acceptable number
                if (!cin.fail() && (playAgain == 1 || playAgain == 0))
                {
                    break;
                }
                // clear the cin and ignore it, run an error
                // will repeat the while loop and prompt the user for input again
                else
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Error: ";
                }
            }
            // breaks back to the loop that allows the Player to choose a new game or cashout & quit
            if (playAgain == 1)
            {
                break;
            }
        }
    }
    return 0;
}