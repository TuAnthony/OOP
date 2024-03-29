/*
   COPYRIGHT (C) 2019 Student Name (abt25) All rights reserved.
   Object Oriented Programming Assignment 1
   Author.  Anthony Tung
            abt25@zips.uakron.edu
   Version. 1.00 1.29.2019
   Purpose: The purpose of this assignment is to code the game of war using what I learned.
*/

#include <iostream>
#include <algorithm>

enum Suit
{
    Diamonds,
    Clubs,
    Hearts,
    Spades,
};

class Card
{
public:

    Card( );
    Card(Suit, int);

    int rank;           // holds rank of card
    Suit suit;          // holds suit of card
};

// initialize a new Card, sets default value to ace of spades
Card::Card( )
{
    rank = 1;
    suit = Spades;
}

Card::Card(Suit s, int r)
// initialize a new Card using the argument values
{
    rank = r;
    suit = s;
}

// output a textual representation of a Card
std::ostream & operator << (std::ostream & outPut, Card & aCard)
{
    switch (aCard.rank) {
        case 1: outPut << "Ace";   break;
        case 2: outPut << "Jack";  break;
        case 3: outPut << "Queen"; break;
        case 4: outPut << "King";  break;
        default:
        outPut << aCard.rank; break;
    }

    switch (aCard.suit)
    {
        case Diamonds: outPut << " of Diamonds"; break;
        case Spades:   outPut << " of Spades";   break;
        case Hearts:   outPut << " of Hearts";   break;
        case Clubs:    outPut << " of Clubs";    break;
    }
    return outPut;
}

class randomInteger
{
public:
    unsigned int operator () (unsigned int);
} randomizer;

//return random integer, converts to unsigned because we got to make it positive and take remainder and put in range
unsigned int randomInteger::operator () (unsigned int max)
{
    unsigned int rval = rand();
    return rval % max;
}

class Deck
{
    public:
        Deck ( );

        void shuffle ( )
        {
            std::random_shuffle (cards, cards+52, randomizer);
        }
        bool isEmpty ( )
        {
            return topCard <= 0;
        }
        Card draw ( );

    private:
        Card  cards[52];
        int   topCard;
};

// initialize the deck by creating all 52 cards
Deck::Deck()
{
    topCard = 0;
    for (int i = 1; i <= 13; i++)
    {
        Card c1(Diamonds, i), c2(Spades, i), c3(Hearts, i), c4(Clubs, i);
        cards[topCard++] = c1;
        cards[topCard++] = c2;
        cards[topCard++] = c3;
        cards[topCard++] = c4;
    }
}

// return one card from the end of the deck otherwise return the ace of spades card
Card Deck::draw ()
{
    if (!isEmpty())

        return cards[--topCard];

    else
    {
        Card spadeAce(Spades, 1);
        return spadeAce;
    }
}

class Player
{
    public:

        Player(Deck &);
        Card draw( );
        void addPoints(int);
        int  score();
        void replaceCard(Deck &);

    private:
        Card myCards[3];
        int  myScore;
        int  removedCard;
};

//initialize the data fields for a player
Player::Player(Deck & aDeck)
{
    myScore = 0;
    for (int i = 0; i < 3; i++)

    myCards[i] = aDeck.draw();

    removedCard = 0;
}

Card Player::draw()
// return a random card from our hand
{
    removedCard = randomizer(3);
    return myCards[removedCard];
}

// add the given number of points to the current score
void Player::addPoints (int howMuch)
{
    myScore += howMuch;
}

// return the current score
int Player::score()
{
    return myScore;
}

// replace last card played with new card
void Player::replaceCard (Deck & aDeck)
{
    myCards[removedCard] = aDeck.draw();
}

int main()
{
    Deck deck; // creates and shuffle the deck
    deck.shuffle();

    //creates the two players
    Player player1(deck);
    Player player2(deck);

    // plays until the deck is empty
    while (!deck.isEmpty() )
        {
        Card card1  = player1.draw();
        std::cout << "Player 1 plays " << card1 << std::endl;
        Card card2 = player2.draw();
        std::cout << "Player 2 plays " << card2 << std::endl;

        //tie situation
        if (card1.rank == card2.rank)
        {
            player1.addPoints(1);
            player2.addPoints(1);
            std::cout << "\nPlayers War begins\n" << std::endl;
        }
        else if (card1.rank > card2.rank)
        {
			player1.addPoints(2);
			std::cout << "\nPlayer 1 wins round\n" << std::endl;
        }
		else
        {
			player2.addPoints(2);
			std::cout << "\nPlayer 2 wins round\n" << std::endl;
        }

			// now replace the cards drawn
		player1.replaceCard(deck);
		player2.replaceCard(deck);
	}
	std::cout << "Player 1 final score " << player1.score() << std::endl;
	std::cout << "Player 2 final score " << player2.score() << std::endl;
}

