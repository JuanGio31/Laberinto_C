// #include <SDL2/SDL.h>
// #include "stdbool.h"

// int main(int argc, char *args[])
// {
//     SDL_Init(SDL_INIT_VIDEO);

//     SDL_Window *window = SDL_CreateWindow("SDL2 Window",
//                                           SDL_WINDOWPOS_CENTERED,
//                                           SDL_WINDOWPOS_CENTERED,
//                                           640, 480,
//                                           SDL_WINDOW_SHOWN);
//     SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

//     SDL_Event event;
//     bool running = true;

//     while (running)
//     {
//         while (SDL_PollEvent(&event))
//         {
//             if (event.type == SDL_QUIT)
//             {
//                 running = false;
//             }
//         }

//         // Clear the screen
//         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//         SDL_RenderClear(renderer);

//         // Draw something
//         SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//         SDL_RenderDrawLine(renderer, 0, 0, 640, 480);

//         // Render
//         SDL_RenderPresent(renderer);
//     }

//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(window);
//     SDL_Quit();

//     return 0;
// }
