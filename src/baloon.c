#include <SDL2/SDL.h>
#include <stdio.h>

int main(void)
{
    SDL_Window *window;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL ERROR: %s!\n", SDL_GetError());
        return 1;
    }

    if ((window = SDL_CreateWindow(
                    "test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                    600, 600, 0)
                ) == 0) {
        printf("SDL ERROR: %s!\n", SDL_GetError());
        return 1;
    }

    char running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
    }

    SDL_Quit();

    return 0;
}
