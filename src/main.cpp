#include <iostream>
#include <SDL2/SDL.h>

int main (int argc, char** argv)
{
    if (!SDL_Init(SDL_INIT_EVERYTHING))
        std::cout << "Everything running fine" << std::endl;
    return 0;
}