//Anthony Tung

#include <algorithm>
#include <iostream>
#include "Cards.hpp"

int main()
{
    //Function prints the card
    Standard standardCard(Knight, Spades);
    std::cout << standardCard.getSuit() << "    " << standardCard.getRank() << std::endl;
    std::cout << standardCard << std::endl;

    //Returns the cards color
    Joker jokerCardBlack(Black), jokerCardRed(Red);
    std::cout << jokerCardBlack << "    " << jokerCardBlack.getColor() << "    " << jokerCardRed.getColor() << std::endl;

    //Goes into a query if the card is a standard or a joker card
    PlayingCard cardExampleStandard(StandardKind), cardExampleJoker(JokerKind);
    std::cout << cardExampleStandard.getKind() << "   " << cardExampleJoker.getKind() << std::endl;

    //End program
    return 0;
}
