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

enum kin {

    Standkind,
    Jokerkind

};

enum color{

    Red,
    Black

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

class Joker
{
    Color color;

    public:
    Joker(Color cl) : color(cl) { }
    Color getColor() const { return color; }
};


union PlayCardUni
{
    Card standCard;
    Joker jokerCard;

    PlayCardUni(Rank r, Suit s) : standCard(r, s) { }
    PlayCardUni(Color cl) : jokerCard(cl) { }
};

class PlayingCard
{
    Kind kin;
    PlayCardUni playCardUni;

public:
    PlayingCard(Rank r, Suit s) : kin(StandKind), playCardUni(r, s) { }
    PlayingCard(Color cl) : kin(JokerKind), playCardUni(cl) { }
    bool isStandCard() const { return kin == StandKind; }
    bool isJokerCard() const { return kin == JokerKind; }
    //Get function for rank
    Rank getRank() const
    {
        assert(isStandCard());

        return playCardUni.standCard.getRank();
    }
    //Get function for suit
    Suit getSuit() const
    {
        assert(isStandCard());

        return playCardUni.standCard.getSuit();
    }
    //Get function for colour
    Color getColor() const
    {
        assert(isJokerCard());

        return playCardUni.jokerCard.getColour();
    }
    //Get function for Standard card
    Card getStandardCard() const
    {
        assert(isStandCard());

        return playCardUni.standCard;
    }
    //Get function for Joker card
    Joker getJokerCard() const
    {
        assert(isJokerCard());

        return playCardUni.jokerCard;
    }
};

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
