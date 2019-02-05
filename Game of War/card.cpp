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
    // constructors
    Card( );            // initialize a card with default values
    Card(Suit, int);   // initialize a card with given values

    // data fields
    int rank;           // hold rank of card
    Suit suit;           // hold suit of card
};

Card::Card( )
// initialize a new Card
// default value is the ace of spades
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

std::ostream & operator << (std::ostream & outPut, Card & aCard)
// output a textual representation of a Card
{
    // first output rank
    switch (aCard.rank) {
        case 1: outPut << "Ace";   break;
        case 2: outPut << "Jack";  break;
        case 3: outPut << "Queen"; break;
        case 4: outPut << "King";  break;
        default:
        outPut << aCard.rank; break;
    }

    // then output suit
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

unsigned int randomInteger::operator () (unsigned int max)
{
    // rand return random integer
    // convert to unsigned to make positive
    // take remainder to put in range
    unsigned int rval = rand();
    return rval % max;
}

class Deck {
public:
    // constructor
    Deck ( );

    // operations
    void shuffle ( )
    {
        std::random_shuffle (cards, cards+52, randomizer);
    }
    bool    isEmpty ( )
    { return topCard <= 0; }
    Card    draw ( );

protected:
    Card    cards[52];
    int     topCard;
};

Deck::Deck ( )
// initialize a deck by creating all 52 cards
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

Card Deck::draw ( )
// return one card from the end of the deck otherwise return the ace of spades card
{
    if (! isEmpty())

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
        // constructor
        Player (Deck &);

        // operations
        Card draw( );
        void addPoints(int);
        int  score();
        void replaceCard(Deck &);

    protected:
        Card  myCards[3];
        int   myScore;
        int   removedCard;
};

Player::Player(Deck & aDeck)
// initialize the data fields for a player
{
    myScore = 0;
    for (int i = 0; i < 3; i++)

    myCards[i] = aDeck.draw();

    removedCard = 0;
}

Card Player::draw( )
// return a random card from our hand
{
    removedCard = randomizer(3);
    return myCards[removedCard];
}

void Player::addPoints (int howMany)
// add the given number of points to the current score
{
    myScore += howMany;
}

int Player::score( )
// return the current score
{
    return myScore;
}

void Player::replaceCard (Deck & aDeck)
// replace last card played with new card
{
    myCards[removedCard] = aDeck.draw();
}

int main()
{
    Deck deck; // create and shuffle the deck
    deck.shuffle();

    Player player1(deck); // create the two
    Player player2(deck); // players

    // play until deck is empty
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

