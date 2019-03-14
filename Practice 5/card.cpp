//Anthony Tung

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

//Overload the operator to display Joker card
std::ostream& operator<<(std::ostream& out, Joker c)
{
    return out << c.getColour();
}
//Overload the operator to display card color
std::ostream& operator<<(std::ostream& out, Color c)
{
    if(c == Black)
        return out << "Black Joker";
    else
        return out << "Red Joker";
}
//Overload the << operator to display the card kind
std::ostream& operator<<(std::ostream& out, Kind k)
{
    if(k == StandardKind)
        return out << "Standard Card";
    else
        return out << "Joker Card";
}

PlayingCard::PlayingCard() { }

//Gets the color for joker
Color Joker::getColor() const
{
    return color;
}

//Gets the kind of card
Kind PlayingCard::getKind() const
{
    return kind;
}

//Gets the rank
Rank Standard::getRank() const
{
    return rank;
}

//Gets the suit
Suit Standard::getSuit() const
{
    return suit;
}
