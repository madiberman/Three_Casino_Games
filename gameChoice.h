#include <iostream>
#include <cstdlib>
#include "guessTheNumber.h"
#include "slotMachine.h"
#include "blackJack.h"

using namespace std;

void game(int gameNo, int bettingMoney, int totalMoney)
{
    if (gameNo == 0)
    {
        //guessTheNumber.h
        //run the guess the number game
        guessTheNumber(bettingMoney, totalMoney);
    }
    else if (gameNo == 1)
    {
        //slotMachine.h
        //run the slot machine game
        slotMachine(bettingMoney, totalMoney);
    }
    else if (gameNo == 2)
    {
        //blackJack.h
        //run the blackJack game
        blackJack(bettingMoney, totalMoney);
    }
    else if (gameNo == 3)
    {
        //game quits in Casino_Demo.cpp
    }
    else
    {
        cout << "Error running selected game";
    }
}