#ifndef SNAKE_HPP_INCLUDED
#define SNAKE_HPP_INCLUDED


class window{

    public:
    int draw;
    int restart;
    int timer;
    Window get_window() const {return w;}
    Event get_e() const {return e;}


    private:

    Window window;
    Event e;

};


struct Snake
{
  int x, y;
} s[100];

struct Fruct
{
  int x, y;
} f;

#endif // SNAKE_HPP_INCLUDED
