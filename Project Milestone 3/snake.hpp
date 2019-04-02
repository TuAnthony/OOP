//Anthony Tung

#ifndef SNAKE_HPP_INCLUDED
#define SNAKE_HPP_INCLUDED


#include <stdio.h>
#include "main.cpp"


class windows{

    const int N = 30;
    const int M = 20;
    const int size = 16, width = size * N, height = size * M;
    int dir;
    int num = 4;
    float timer = 0
    float delay = 0.1;

public:
    void createWindow();
    void Tick();
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
