//Anthony Tung

#include "playingCard.h"

//return suit
Suit StanCard::getSuit() const
{
 	return suit;
}
//return rank
Rank StanCard::getRank() const
{
 	return rnk;
}
//prints standard card
void StanCard::print() const
{
	string out;
	switch (this->getRank())
	{
		case Two: out = "2"; break;
		case Three: out = "3"; break;
		case Four: out = "4"; break;
		case Five: out = "5"; break;
		case Six: out = "6"; break;
		case Seven: out = "7"; break;
		case Eight: out = "8"; break;
		case Nine: out = "9"; break;
		case Ten: out = "10"; break;
		case Jack: out = "Jack"; break;
		case Queen: out = "Queen"; break;
		case King: out = "King"; break;
		case Ace: out = "Ace"; break;
	}
	switch (this->getSuit())
	{
		case H: out += " of Hearts"; break;
		case D: out += " of Diamonds"; break;
		case C: out += " of Clubs"; break;
		case S: out += " of Spades"; break;
	}
	cout << out << endl;
}
//returns color of standard card
Color StanCard::getColor() const
{
	int suit = this->getSuit();
	switch (suit)
	{
		case H: return Red;
		case D: return Red;
		case C: return Black;
		case S: return Black;
		default: return Black;
	}
}
//returns rank of joker
Rank JokeCard::getRank() const
{
    return Two;
}
//returns color of joker
Color JokeCard::getColor() const
{
	return color;
}
//prints card for joker
void JokeCard::print() const
{
	int color = this->getColor();
	if (color == Black)
		cout << "Black Joker" << endl;
    else
        cout << "Red Joker" << endl;
}

//returns true if standard card
bool PlayingCard::isStan() const
{
	if (type == Stan)
		return true;
    return false;
}
//returns true if joker card
bool PlayingCard::isJoke() const
{
	if (type == Joke)
		return true;
    return false;
}
