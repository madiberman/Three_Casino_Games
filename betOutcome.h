#include <iostream>
#include <cstdlib>
#include <istream>
#include <string>

using namespace std;
int totalMoneyAfterBet;

void betOutcome(int winOrLose, int bettingMoney, int totalMoney)
{
    // 0 = ten times the bet
    // 1 = lose
    // 2 = double winnings
    // 3 = triple winnings
    // 4 = breakeven

    if (winOrLose == 0)
    {
        cout << "\nWINNER!!\n";
        //update the amount of money the user has, can be seen using totalAfterBet()
        totalMoney += bettingMoney * 10;
        totalMoneyAfterBet = totalMoney;
        cout << "Won: £" << bettingMoney << "\nRemaining: £" << totalMoney << "\n\n";
    }
    else if (winOrLose == 1)
    {
        cout << "\nYOU LOSE! Better luck next time!\n\n";
        //update the amount of money the user has, can be seen using totalAfterBet()
        totalMoney -= bettingMoney;
        totalMoneyAfterBet = totalMoney;
        cout << "Lost: £" << bettingMoney << "\nRemaining: £" << totalMoney << "\n\n";
    }
    else if (winOrLose == 2)
    {
        cout << "\nWINNER!!\n";
        //update the amount of money the user has, can be seen using totalAfterBet()
        totalMoney += bettingMoney;
        totalMoneyAfterBet = totalMoney;
        cout << "Won: £" << bettingMoney << "\nRemaining: £" << totalMoney << "\n\n";
    }
    else if (winOrLose == 3)
    {
        cout << "\nWINNER!!\n";
        //update the amount of money the user has, can be seen using totalAfterBet()
        totalMoney += bettingMoney * 2;
        totalMoneyAfterBet = totalMoney;
        cout << "Won: £" << bettingMoney << "\nRemaining: £" << totalMoney << "\n\n";
    }
    else if (winOrLose == 4)
    {
        cout << "You broke even!\n";
        cout << "Remaining: £" << totalMoney << "\n\n";
    }
    else
    {
        cout << "Error calculating betting outcome\n";
    }
}

//for encapsulation
int totalAfterBet()
{
    return totalMoneyAfterBet;
}