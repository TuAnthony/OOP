// Anthony Tung

#include <cassert>
#include <iosfwd>
#include <vector>


enum Rank
{

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
};


enum Suit
{
	Spades,
	Clubs,
	Diamonds,
	Hearts,
};

enum Largeness
{
	Black,
	Red,
};


//Class for conditions of a regular card that includes just a Rank and a Suit
class RegularCard {
public:

	RegularCard() = default;

	RegularCard(Rank r, Suit s)
		: rank(r), suit(s){}

	Rank get_rank() const{
		return rank;
	}

	Suit get_suit() const{
		return suit;
	}

private:
	Rank rank;
	Suit suit;
};


//Class for joker
class JokerCard{
public:
	Joker(Largeness l)
		: size(l) {}

	Largeness get_size() const {
		return size;
	}

private:
	Largeness size;

};



class Card
{
public:
	enum Kind
    {
		Regular,
		Joker,
	};

private:
	union Value{
		Value(RegularCard c) : rc(c) {}
		Value(JokerCard c) : jc(c) {}

	RegularCard rc;
	JokerCard jc;
	};

public:

	Card(RegularCard c)
		: kind(Regular), val(c){}
	Card(JokerCard c)
		: kind(Joker), val(c){}

	Kind get_king() const {return kind;}
	bool is_regular() const { return kind == Regular;}
	bool is_joker() const { return kind == Joker; }


//Assertions

	RegularCard get_regular_card() const {
		assert(is_regular());
		return val.rc;
	}

	JokerCard get_joker_card() const {
		assert(is_joker());
		return val.jc;
	}


	Suit get_suit() const {
		return get_regular_card().get_suit();
	}


	Rank get_rank() const {
		return get_regular_card().get_rank();
	}


	Largeness get_size() const {
		return get_joker_card().get_size();
	}

private:
	Kind kind;
	Value val;
};
