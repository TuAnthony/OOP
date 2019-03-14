//Anthony Tung

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

class playingCard
{
    Kind kind;

public:
    playingCard();
    playingCard(Kind k) : kind(k) { }
    Kind getKind() const;
};

class Joker : playingCard
{
    Color color;

    public:
    Joker(Color cl) : color(cl) { }
    Color getColor() const;
};

class Standard : PlayingCard //PlayingCard
{
    Rank rank;
    Suit suit;

public:
    Standard(Rank r, Suit s) : rank(r), suit(s) { }
    Rank getRank() const;
    Suit getSuit() const;
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
std::ostream& operator<<(std::ostream& out, Standard c);
std::ostream& operator<<(std::ostream& out, Joker c);
std::ostream& operator<<(std::ostream& out, Colour c);
std::ostream& operator<<(std::ostream& out, Kind k);
std::ostream& operator<<(std::ostream& out, PlayingCard c);
