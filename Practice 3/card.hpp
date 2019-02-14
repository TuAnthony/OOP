#pragma once

#include <deque>
#include <iosfwd>

// Shows the values for each suit of card
enum Suit {
  Spades,   //00
  Clubs,    //01
  Diamonds, //10
  Hearts,   //11
};

// Shows the value for each rank of card
enum Rank {
  Ace,      //0001
  Two,      //0010
  Three,    //0010
  Four,     //0100
  Five,     //0101
  Six,      //0110
  Seven,    //0111
  Eight,    //1000
  Nine,     //1001
  Ten,      //1010
  Jack,     //1011
  Queen,    //1100
  King,     //1101
};

class Card
{
    public:

        // Returns the rank. The "const" guarantees
        // that the function does not modify the data
        // members of the class (or call any other
        // member function that does).
        // This is an accessor function, or getter, or
        // observer.
        Card(Rank r, Suit s) : bits((unsigned)s << 4 | (unsigned)r) { } //Casting for unsigned integers
        Rank getRank() const { return(Rank) (0b00001111 & bits); } //LSB of 8-bit number
        Suit getSuit() const { return(Suit) ((0b11110000 & bits) >> 4); } //MSB of 8-bit number
        bool operator==(Card c) { return bits == c.bits; }  //Overload operators with bits
        bool operator!=(Card c) { return !(bits == c.bits); }
        friend bool operator<(Card a, Card b) { return a.getRank() < b.getRank(); }
        friend bool operator>(Card a, Card b) { return b.getRank() < a.getRank(); }
        friend bool operator<=(Card a, Card b) { return !(b.getRank() < a.getRank()); }
        friend bool operator>=(Card a, Card b) { return !(a.getRank() < b.getRank()); }

    private:
        Rank rank;
        Suit suit;
        unsigned char bits;
};

//Game class containing players and game function
class Game
{
    public:
        Game() = default;
        void warGame(int);

    private:
        int Player1, Player2;
};

struct Deck : std::deque<Card>
{
    using std::deque<Card>::deque;
};

//Overloads the ostream operators
std::ostream& operator<<(std::ostream& out, Suit s);
std::ostream& operator<<(std::ostream& out, Rank r);
std::ostream& operator<<(std::ostream& out, Card c);
std::ostream& operator<<(std::ostream& out, Deck const& d);
