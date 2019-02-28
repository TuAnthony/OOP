#include "card.hpp"
#include <iostream>
#include <random>
#include <strings>

//Overloads the operator of the suit to display suit of card
std::ostream& operator<<(std::ostream& out, Suit s)
{
    switch(s)
    {
        case Diamonds:
            return out << "D";
        case Clubs:
            return out << "C";
        case Hearts:
            return out << "H";
        case Spades:
            return out << "S";
    }
}

//Overloads the operator to display rank of card
std::ostream& operator<<(std::ostream& out, Rank r)
{
    switch(r)
    {
        case Ace:
            return out << "A";
        case Two:
            return out << "2";
        case Three:
            return out << "3";
        case Four:
            return out << "4";
        case Five:
            return out << "5";
        case Six:
            return out << "6";
        case Seven:
            return out << "7";
        case Eight:
            return out << "8";
        case Nine:
            return out << "9";
        case Ten:
             return out << "T";
        case Jack:
            return out << "J";
        case Queen:
            return out << "Q";
        case King:
            return out << "K";
    }
}

//Overload the operator to display entire card
std::ostream& operator<<(std::ostream& out, Card c)
{
    return out << c.getRank() << c.getSuit();
}



std::string makeBinary(int dec)
{
    std::stringstream binarySupp;
    int rem, i = 1, step = 1, binary = 0;
    while (decimal != 0)
    {
        rem = decimal % 2;
        decimal /= 2;
        binary += rem * i;
        i *= 10;
    }
    binarySupp << binary;
    return binarySupp.str();
}

int createDecInt(std::string bin)
{

    int decimal = 0, i = 0, rem, num;
    std::stringstream binarySupp;
    binarySupp << binary;
    binarySupp >> num;
    while (num != 0)
    {
        rem = num % 10;
        num /= 10;
        decimal += rem * pow(2,i);
        ++i;
    }
    return decimal;
}

std::string createBinary(std::string s, int m)
{
    std::stringstream binary;
    binary <<  std::setw(4) << setfill('0') << s;
    binary <<  std::setw(4) << setfill('0') << makeBinary(m);
    return binary.str();
}


void Game::createDec(Deck & deck)
{
    for (int i = 0; i < 54; ++i)
    {
        if(i < 13)
            deck.push_back(createBinary("0000", i));
        else if(i < 26 && i >= 13)
            deck.push_back(createBinary("0001", i - 13));
        else if(i < 39 && i >= 26)
            deck.push_back(createBinary("0010", i - 26));
        else if(i < 52 && i >= 39)
            deck.push_back(createBinary("0011", i - 39));
        else if(i == 52)
            deck.push_back(createBinary("0100", 0));
        else if(i == 53)
            deck.push_back(createBinary("1000", 0));
    }
}


//Function is part of game class where it takes an integer so that it can be called inside main and also returns void
//also took this code from the given code in class that was originally in main
void Game::warGame(int trial)
{
    //Declare counters for Player 1 and Player 2
    Player1 = 0;
    Player2 = 0;

    //Declare the set of 52 cards to relate suit and rank
    Deck d
    {
        {Ace, Diamonds},
        {Two, Diamonds},
        {Three, Diamonds},
        {Four, Diamonds},
        {Five, Diamonds},
        {Six, Diamonds},
        {Seven, Diamonds},
        {Eight, Diamonds},
        {Nine, Diamonds},
        {Ten, Diamonds},
        {Jack, Diamonds},
        {Queen, Diamonds},
        {King, Diamonds},

        {Ace, Hearts},
        {Two, Hearts},
        {Three, Hearts},
        {Four, Hearts},
        {Five, Hearts},
        {Six, Hearts},
        {Seven, Hearts},
        {Eight, Hearts},
        {Nine, Hearts},
        {Ten, Hearts},
        {Jack, Hearts},
        {Queen, Hearts},
        {King, Hearts},

        {Ace, Clubs},
        {Two, Clubs},
        {Three, Clubs},
        {Four, Clubs},
        {Five, Clubs},
        {Six, Clubs},
        {Seven, Clubs},
        {Eight, Clubs},
        {Nine, Clubs},
        {Ten, Clubs},
        {Jack, Clubs},
        {Queen, Clubs},
        {King, Clubs},

        {Ace, Spades},
        {Two, Spades},
        {Three, Spades},
        {Four, Spades},
        {Five, Spades},
        {Six, Spades},
        {Seven, Spades},
        {Eight, Spades},
        {Nine, Spades},
        {Ten, Spades},
        {Jack, Spades},
        {Queen, Spades},
        {King, Spades},
    };

    //Declares a integer as random in order to allow the game to shuffle the cards
    std::random_device rng;
    std::minstd_rand prng(rng());
    std::shuffle(d.begin(), d.end(), prng);

    for(int counter = 0; counter < 52; ++counter)
    {
        if(counter % 13 == 0)
            std::cout << std::endl;

        std::cout << d[counter] << " ";
    }

    std::cout << std::endl << std::endl;

    for(int counter = 0, index = 0, war = 0; counter < 52; counter += 2, ++index)
    {

        if(d[counter] > d[counter + 1])
        {
            std::cout << "Player 1 wins Round " << index - war + 1 << std::endl;

            Player1 += 2;
        }
        else if(d[counter] < d[counter + 1])
        {
            std::cout << "Player 2 wins Round " << index - war + 1 << std::endl;

            Player2 += 2;
        }
        else
        {
            std::cout << "WAR!" << std::endl;

            // Reshuffles the card
            std::shuffle(d.begin(), d.end(), prng);

            if(d[counter + 7] > d[counter + 8])
            {
                std::cout << "Player 1 won the war " << std::endl;

                //If there are less than ten cards remaining, the player wins the remaining cards
                if(10 <= (52 - (Player1 + Player2)))
                    Player1 += 10;
                else
                    Player1 += (52 - (Player1 + Player2));
            }
            else
            {
                std::cout << "Player 2 won the war " << std::endl;

                //If there are less than ten cards remaining, the player wins the remaining cards
                if(10 <= (52 - (Player1 + Player2)))
                    Player2 += 10;
                else
                    Player2 += (52 - (Player1 + Player2));
            }

            if(counter != 0)
                ++war;

            counter += 10;
        }

    }

    //Displays how much points player 1 and player 2 have
    std::cout << std::endl << "Total Points for Player 1: " << Player1 << std::endl;
    std::cout << "Total Points for Player 2: " << Player2 << std::endl;

    //Game reruns if the amount of points are the same, also displays who won
    if(Player1 > Player2)
        std::cout << "Player 1 wins!" << std::endl << std::endl;
    else if(Player1 < Player2)
        std::cout << "Player 2 wins!" << std::endl << std::endl;
    else if(Player1 == Player2)
        std::cout << "Its a tie! Play again!" << std::endl << std::endl;
}
