#include <SDL2/SDL.h>
#include <stdio.h>
#include "action.h"

int main(void)
{
    SDL_Window *window;

    ActionQueue queue;
    InitQueue(&queue);

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
                Action action = { .type = ACTION_QUIT };
                QueueAction(&action, &queue);
            }
        }
        if ((ProcessAction(&queue)).type == ACTION_QUIT) {
            running = 0;
            PrintQueue(&queue);
        }
    }

    SDL_Quit();

    return 0;
}
