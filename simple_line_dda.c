// sudo apt-get install libsdl2-dev
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

// Function to draw a line using DDA algorithm
void drawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;
    float x = x1, y = y1;

    SDL_RenderDrawPoint(renderer, x, y);
    for (int i = 0; i < steps; i++) {
        x += xIncrement;
        y += yIncrement;
        SDL_RenderDrawPoint(renderer, (int)x, (int)y);
    }
}

int main() {
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create window
    window = SDL_CreateWindow("Line Drawing using SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Set draw color to red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);

    // Clear screen to white
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Set draw color back to red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);

   
    int x1 = 350, y1 = 350, x2 = 750, y2 = 750;

    // Draw line using DDA algorithm
    drawLine(renderer, x1, y1, x2, y2);

    // Update screen
    SDL_RenderPresent(renderer);

    // Wait for user to close window
    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    // Clean up resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
