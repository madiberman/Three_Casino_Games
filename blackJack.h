#include <iostream>
#include <cstdlib>
#include <istream>
#include <string>
#include <list>
#include <iterator>

using namespace std;
list<string> cardDeck;
list<string>::iterator itr;
string cardFaces[13] = {"A", "Q", "K", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2"};
bool firstPlay = true;
bool firstCard = true;
bool playersTurn;
int playerTotal;
int dealerTotal;

void pullCardPlayer();
void pullCardDealer();
bool dealerChoice();
int getCardValue(string card);
string getCard();

void blackJack(int bettingMoney, int totalMoney)
{
    // point the iterator to the first card in the deck
    itr = cardDeck.begin();
    // initilized first play/card/values
    firstPlay = true;
    firstCard = true;
    playerTotal = 0;
    dealerTotal = 0;

    // create the deck of cards with an embedded for loop
    for (int i = 0; i < 13; i++)
    {
        // create a string for each of the 13 card face types
        string addedCard = cardFaces[i];
        for (int j = 0; j < 4; j++)
        {
            // add each card face to the deck 4 times
            cardDeck.push_back(addedCard);
        }
    }

    // initial 2 cards pulled for each
    pullCardPlayer();
    pullCardDealer();

    // while loop breaks when game ends
    while (true)
    {
        int hitPassChoice;

        // if the player wins
        if (playerTotal == 21 || dealerTotal > 21)
        {
            // betOutcome.h
            // double winnings
            betOutcome(2, bettingMoney, totalMoney);
            break;
        }
        // if the player loses
        else if (dealerTotal == 21 || playerTotal > 21)
        {
            // betOutcome.h
            betOutcome(1, bettingMoney, totalMoney);
            break;
        }
        else
        {
            // while loop breaks when the Player inputs a valid response
            while (true)
            {
                cout << "\nWould you like to hit [0] or pass [1]?\n";
                cin >> hitPassChoice;
                // if the cin succeeds and the input is valie
                if (!cin.fail() && (hitPassChoice == 1 || hitPassChoice == 0))
                {
                    break;
                }
                // clear and ignore Player entries
                // will repeat the while loop and prompt the user for input again
                else
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n\nError: ";
                }
            }
            //player chooses to hit
            if (hitPassChoice == 0)
            {
                pullCardPlayer();
                //if the player value exceeds 21
                if (playerTotal > 21)
                {
                    //betOutcome.h
                    //lose
                    betOutcome(1, bettingMoney, totalMoney);
                    break;
                }
                else
                {
                    //if the player did not exceed 21, the dealer takes their turn
                    //if the dealer chooses to hit
                    if (dealerChoice())
                    {
                        pullCardDealer();
                    }
                    //if the dealer chooses to pass
                    else
                    {
                        cout << "\n\nDealer has passed\n";
                    }
                }
            }
            //if the Player passes
            else if (hitPassChoice == 1)
            {
                cout << "\nYou passed\n";
                //if the dealer chooses to pass as well, the game concludes
                if (!dealerChoice())
                {
                    //if the Player has a higher total than the dealer
                    if (playerTotal > dealerTotal)
                    {
                        //betOutcome.h
                        //double winnings
                        betOutcome(2, bettingMoney, totalMoney);
                        break;
                    }
                    //if there is a tie in value
                    else if (playerTotal == dealerTotal)
                    {
                        //betOutcome.h
                        //break even
                        betOutcome(4, bettingMoney, totalMoney);
                        break;
                    }
                    //if the Player has a lower value than the dealer
                    else
                    {
                        //betOutcome.h
                        //lose
                        betOutcome(1, bettingMoney, totalMoney);
                        break;
                    }
                }
                //if the dealer chooses to hit
                else if (dealerChoice())
                {
                    pullCardDealer();
                }
            }
            else
            {
                cout << "Error hitting or passing";
            }
        }
    }
}

// https://www.blackjacktactics.com/blackjack/odds/
// dealer's decisions are based on black jack statistics
bool dealerChoice()
{
    // the dealer will always hit if they have 11 or less
    if (dealerTotal <= 11)
    {
        // hit
        return true;
    }
    // the dealer will hit 2/3 of the time if they have a value of 12 or 13
    else if (dealerTotal == 12 || dealerTotal == 13)
    {
        // initialized a random number generator with the current unix timestamp as the seed
        srand(time(NULL));
        // random number 0-2
        int randomNo = (rand() % 3);
        if (randomNo == 0)
        {
            // pass
            return false;
        }
        else
        {
            // hit
            return true;
        }
    }
    // the dealer will hit 1/2 of the time if they have a value of 14 or 15
    else if (dealerTotal == 14 || dealerTotal == 15)
    {
        // initialized a random number generator with the current unix timestamp as the seed
        srand(time(NULL));
        // random number 0-1
        int randomNo = (rand() % 1);
        if (randomNo == 0)
        {
            // hit
            return true;
        }
        else
        {
            // pass
            return false;
        }
    }
    // the dealer will hit 1/3 of the time if they have a value of 16
    else if (dealerTotal == 16)
    {
        // initialized a random number generator with the current unix timestamp as the seed
        srand(time(NULL));
        // random number 0-2
        int randomNo = (rand() % 3);
        if (randomNo == 0)
        {
            // hit
            return true;
        }
        else
        {
            // pass
            return false;
        }
    }
    // the dealer will hit 1/4 of the time if they have a value of 17
    else if (dealerTotal == 17)
    {
        // initialized a random number generator with the current unix timestamp as the seed
        srand(time(NULL));
        // random number 0-3
        int randomNo = (rand() % 4);
        if (randomNo == 0)
        {
            // hit
            return true;
        }
        else
        {
            // pass
            return false;
        }
    }
    // the dealer will hit 1/6 of the time if they have a value of 18 or 19
    else if (dealerTotal == 18 || dealerTotal == 19)
    {
        // initialized a random number generator with the current unix timestamp as the seed
        srand(time(NULL));
        // random number 0-5
        int randomNo = (rand() % 6);
        if (randomNo == 0)
        {
            // hit
            return true;
        }
        else
        {
            // pass
            return false;
        }
    }
    // the dealer will hit 1/10 of the time if they have a 20
    else if (dealerTotal == 20)
    {
        // initialized a random number generator with the current unix timestamp as the seed
        srand(time(NULL));
        // random number 0-9
        int randomNo = (rand() % 10);
        if (randomNo == 0)
        {
            // hit
            return true;
        }
        else
        {
            // pass
            return false;
        }
    }
    else
    {
        // the dealer will not hit if they have 21
        return false;
    }
}

void pullCardPlayer()
{
    //marks that it is the Player's turn, important for getCard() & getCardValue(string card)
    playersTurn = true;

    //if this is the first time playing, 2 cards are pulled
    if (firstPlay == true)
    {
        cout << "Your first two cards are: " << getCard() << " & ";
        //marks that the first play has been made
        firstCard = false;
        cout << getCard() << "\n"
             << "Your starting value is: " << playerTotal;
    }
    //if this is not the first time playing, only one card is pulled
    else
    {
        cout << "\nYour hit: " << getCard() << "\nYour current value is: " << playerTotal << "\n";
    }

    //marks the end of the Player's turn
    playersTurn = false;
}

string getCard()
{
    int currentCard;
    string pulledCard;

    // initializes a random number generator with the current unix timestamp as the seed
    srand(time(NULL));
    //randSize integer initilized as the size of the deck minus 1
    int randSize = cardDeck.size() - 1;
    //random number 0 : card deck size - 1
    currentCard = (rand() % randSize);
    //move the iterator to the currentCard randomly generated number
    advance(itr, currentCard);
    //pulledCard is set to the value of the index that the iterator is pointing to
    pulledCard = *itr;
    //if it is the Player's turn
    if (playersTurn == true)
    {
        //add the card value to the Player total
        playerTotal += getCardValue(pulledCard);
    }
    //if it is not the Player's turn
    else
    {
        //add the card value to the dealer's total
        dealerTotal += getCardValue(pulledCard);
    }
    return pulledCard;
    //remove the index in the list that the iterator is pointing to
    cardDeck.erase(itr);
}

void pullCardDealer()
{
    //sets to not Player's turn, important for getCard() & getCardValue(string card)
    playersTurn = false;

    //if this is the first time playing, 2 cards are pulled
    if (firstPlay == true)
    {
        cout << "\n\nDealer's first two cards are: " << getCard() << " & " << getCard() << "\n"
             << "Dealer's starting value is: " << dealerTotal << "\n";
    }
    //if this is not the first time playing, only one card is pulled
    else
    {
        cout << "\nDealer's hit: " << getCard() << "\nDealer's current value is: " << dealerTotal << "\n";
    }
    //ends the first play
    firstPlay = false;
}

//sets values for each face value
int getCardValue(string card)
{
    if (card == "Q" || card == "K" || card == "J" || card == "10")
    {
        return 10;
    }
    else if (card == "9")
    {
        return 9;
    }
    else if (card == "8")
    {
        return 8;
    }
    else if (card == "7")
    {
        return 7;
    }
    else if (card == "6")
    {
        return 6;
    }
    else if (card == "5")
    {
        return 5;
    }
    else if (card == "4")
    {
        return 4;
    }
    else if (card == "3")
    {
        return 3;
    }
    else if (card == "2")
    {
        return 2;
    }
    //if the card is an Ace
    else if (card == "A")
    {
        //if it is the Player's turn and this is not the first card they have pulled
        if (playersTurn && !firstCard)
        {
            int numberIn;
            //while loop breaks when the Player input is valid
            while (true)
            {
                cout << "\n\n An Ace! Would you like your Ace to be worth 1 or 11?\n";
                cin >> numberIn;
                //cin succeeds and the Player inputs 1 or 11
                if ((numberIn == 1 || numberIn == 11) && !cin.fail())
                {
                    return numberIn;
                    break;
                }
                //clear and ignore all Player entries if they attempt to bet more than they have
                //will repeat the while loop and prompt the user for input again
                else if ((numberIn != 1 || numberIn != 11) || cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nError: ";
                }
            }
        }
        //if the Ace is the very first card pulled it will automatically be an 11
        else if (playersTurn && firstCard)
        {
            return 11;
        }
        else
        {
            //if the dealer has a value of 10 or less the Ace will be worth 11
            if (dealerTotal <= 10)
            {
                return 11;
            }
            //if the dealer has a value above 10, the Ace will be worth 1
            else
            {
                return 1;
            }
        }
    }
    else
    {
        return 0;
    }
}