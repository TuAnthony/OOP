#ifndef PLAYINGCARD_H_INCLUDED
#define PLAYINGCARD_H_INCLUDED

//Anthony Tung

#include <cassert>
#include <deque>
#include <string>
#include <iostream>
#include <ostream>
using std::ostream;
using std::string;
using std::cout;
using std::endl;

enum Suit
{
    H,
    D,
    C,
    S,
};

enum Rank
{
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
    Ace,
};

enum Color
{
    Red,
    Black,
};

enum CardType
{
    Stan,
    Joke,
};

class PlayingCard
{
protected:
    CardType type;

public:
    PlayingCard(CardType type_): type(type_){ }
    virtual void print() const = 0;
    virtual Color getColor() const = 0;
    virtual Rank getRank() const = 0;
    CardType getType();
    bool isStan() const;
    bool isJoke() const;
};

class StanCard : public PlayingCard
{
private:
	Suit suit;
    Rank rnk;

public:
    StanCard(Suit suit_, Rank rank_): PlayingCard(Stan), suit(suit_), rnk(rank_){}
	Rank getRank() const;
	Suit getSuit() const;
    void print() const;
    Color getColor() const;
};

class JokeCard : public PlayingCard
{
private:
    Color color;

public:
    JokeCard(Color color_): PlayingCard(Joke), color(color_){ }
    Color getColor() const;
    Rank getRank() const;
    void print() const;
};

struct Deck : std::deque<PlayingCard*>
{
  using std::deque<PlayingCard*>::deque;
};


#endif // PLAYINGCARD_H_INCLUDED
