//Anthony Tung

#include <iostream>
#include "card.hpp"

std::ostream&
operator << (std::ostream& os, Suit s)
{
    switch(s) {
    case Clubs: return "C";
    case Spades: return "S";
    case Hearts: return "H";
    case Diamonds: return "D";

    }
}

std::ostream&
operator<<(std::ostream& os, Rank r)
{
    switch(r) {
    case Ace: return "A";
    case Two: return "2";
    case Three: return "3";
    case Four: return "4";
    case Five: return "5";
    case Six: return "6";
    case Seven: return "7";
    case Eight: return "8";
    case Nine: return "9";
    case Ten: return "T";
    case Jack: return "J";
    case Queen: return "Q";
    case King: return "K";

    }
}

std::ostream&
operator<<(std::ostream& os, Card c)
{
    return os << c.rank << c.suit;
}
