//Anthony Tung

#ifndef CARD_HPP_INCLUDED
#define CARD_HPP_INCLUDED

#include <iosfwd>

enum Suit {
    Clubs,
    Spades,
    Hearts,
    Diamonds,

};

enum Rank (
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,

);

struct Card {

    Rank rank;
    Suit suit;

};


#endif // CARD_HPP_INCLUDED
