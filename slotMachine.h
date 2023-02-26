#include <iostream>
#include <cstdlib>
#include <istream>
#include <string>

using namespace std;

void slotMachine(int bettingMoney, int totalMoney)
{
    //initialized a random number generator with the current unix timestamp as the seed
    srand(time(NULL));
    //each slot is a random number 0-5
    int firstSlot = (rand() % 6);
    int secondSlot = (rand() % 6);
    int thirdSlot = (rand() % 6);

    string slotOptions[6] = {"SEVEN", "Bananas", "Cherries", "Orange", "Watermelon", "Grapes"};

    cout << "------------------------------\n\n";
    //choose from the array of slotOptions based on the random number generated for each slot
    cout << slotOptions[firstSlot] << " * " << slotOptions[secondSlot] << " * " << slotOptions[thirdSlot];
    cout << "\n\n------------------------------\n\n";
    
    // Triple sevens
    if (firstSlot == 0 && secondSlot == 0 && thirdSlot == 0)
    {
        betOutcome(3, bettingMoney, totalMoney);
    }
    // Two sevens
    else if (firstSlot == 0 && secondSlot == 0 || secondSlot == 0 && thirdSlot == 0 || firstSlot == 0 && thirdSlot == 0)
    {
        betOutcome(2, bettingMoney, totalMoney);
    }
    // One seven
    else if (firstSlot == 0 && secondSlot != 0 && thirdSlot != 0 || firstSlot != 0 && secondSlot == 0 && thirdSlot != 0 || firstSlot != 0 && secondSlot != 0 && thirdSlot == 0)
    {
        betOutcome(4, bettingMoney, totalMoney);
    }
    // Triple fruits
    else if (firstSlot == secondSlot && secondSlot == thirdSlot)
    {
        betOutcome(2, bettingMoney, totalMoney);
    }
    //Lose
    else
    {
        betOutcome(1, bettingMoney, totalMoney);
    }
}