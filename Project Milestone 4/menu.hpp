//Anthony Tung
//Milestone 4

#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "snake.hpp"

#include "SFML/Graphics.hpp"

#define MAXIMUM 2

class Menu
{
    int index;
    sf::Font font;
    sf::Text menu[MAXIMUM];

    public:
        Menu();
        Menu(float width, float height);
        ~Menu()
        { }

        void draw(sf::RenderWindow &window);
        void Up();
        void Down();
        int Press() { return index; }
        void factorEvent();
};


#endif // MENU_HPP_INCLUDED
