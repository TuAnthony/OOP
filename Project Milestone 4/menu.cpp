//Anthony Tung
//Milestone 4

#include "menu.hpp"

//This creates a menu
Menu::Menu(float width, float height)
{
    //load a font from a file that I have chosen. You can change this to a different font if you choose
    if(!font.loadFromFile("/System/Library/Fonts/SFNSText.ttf"))
    exit(1);

    //We set the font, initialize the color and title option and position to the screen size
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Blue);
    menu[0].setString("Playing Snake");
    menu[0].setPosition(sf::Vector2f(width / 2.5, height / (MAXIMUM + 1)));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::Black);
    menu[1].setString("Exiting Snake");
    menu[1].setPosition(sf::Vector2f(width / 2.5, height / (MAXIMUM + 1) * 2));

    index = 0;
}

//Function creates a window for the menu to display
void Menu::draw(sf::RenderWindow &window)
{
    for(int counter = 0; counter < MAXIMUM; ++counter)
        window.draw(menu[counter]);
}

//Function moves the menu up
void Menu::Up()
{
    if(index - 1 >= 0)
    {
        menu[index].setColor(sf::Color::Black);

        --index;

        menu[index].setColor(sf::Color::Blue);
    }
}

//Function moves the menu down
void Menu::Down()
{
    if(index + 1 < MAXIMUM)
    {
        menu[index].setColor(sf::Color::Black);

        ++index;

        menu[index].setColor(sf::Color::Blue);
    }
}

//Function determines the cases when the keyboard is pressed up, down, and ways to return back to the menu
//Function is also processing out main program to create reusable framework
void factorEvent()
{
    //Creates the class 'object' for windows
    Windows object;

    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML");
    Menu menu(window.getSize().x, window.getSize().y);

    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::KeyReleased:
                    switch(event.key.code)
                {
                    case sf::Keyboard::Up:
                        menu.Up();
                        break;
                    case sf::Keyboard::Down:
                        menu.Down();
                        break;
                    case sf::Keyboard::Return:
                        switch(menu.Press())
                    {
                        case 0:
                            window.close();
                            object.CreateWindow();
                            break;
                        case 1:
                            window.close();
                            break;
                    }
                        break;
                }
                    break;

                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        window.clear(sf::Color::White);
        menu.draw(window);
        window.display();
    }
}
