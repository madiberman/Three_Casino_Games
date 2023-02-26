#include <iostream>
#include <cstdlib>
#include <istream>
#include <string>

using namespace std;

void guessTheNumber(int bettingMoney, int totalMoney)
{
    int numberGuessed;

    //while loop breaks after the user correctly chooses a number 
    while (true)
    {
        cout << "Pick a number [1-10]\n\n";
        cin >> numberGuessed;
        cout << "\n";
        //if the cin succeeds and the Player entered an acceptable number
        if (numberGuessed >= 1 && numberGuessed <= 10 && !cin.fail())
        {
            break;
        }
        //clear the cin and ignore it, run an error if the number is not between [1-10] or is not a number
        else if (numberGuessed <= 1 && numberGuessed >= 10 || cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nError: ";
        }
    }
    //initialized a random number generator with the current unix timestamp as the seed
    srand(time(NULL));
    //creates a random int between 1 and 10
    int randomNo = 1 + (rand() % 10);
    
    //if the random number generated is the same as the Player's guess
    if (randomNo == numberGuessed)
    {
        //betOutcome.h
        //win, double money
        betOutcome(0, bettingMoney, totalMoney);
    }
    else
    {
        //betOutcome.h
        //lose
        betOutcome(1, bettingMoney, totalMoney);
        cout << "\nRandom number was: " << randomNo << "\n\n";
    }
}