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
  Card(Rank r, Suit s)
    : bits((unsigned)s << 4 | (unsigned)r)
    { }

  // Returns the rank. The "const" guarantees
  // that the function does not modify the data
  // members of the class (or call any other
  // member function that does).
  //
  // This is an accessor function, or getter, or
  // observer.
  Rank get_rank() const {
    return (Rank) (0b001111 & bits); // 0xf & bits
    }

  // Same as above.
  Suit get_suit() const {
        return (Suit)((0b110000 & bits) >> 4);
    }

  bool operator==(Card c) const {
        return bits == c.bits;
    }

    // This friend function is not a member of class, but has access to private members of the class that it is friends with
    friend bool operator==(Card a, Card b)
    {
        return a.bits == b.bits;
    }


private:
    unsigned char bits;
};


// This makes sure that when two cards are equal they have the same rank and suit
inline bool operator==(Card a, Card b)
{
    return a.bits == b.bits;
}

// This is the not equal version when they are not equal
inline bool operator!=(Card a, Card b)
{
    return !(a == b);
}
