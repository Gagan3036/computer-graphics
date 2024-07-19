#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

void drawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2);
void drawText(SDL_Renderer *renderer, int x, int y, const char *text, TTF_Font *font);

int main() {
    int x1, y1, x2, y2;

    printf("Enter Initial Coordinates: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter Final Coordinates: ");
    scanf("%d %d", &x2, &y2);

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() == -1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("DDA Line Drawing",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          640, 480, 0);
    if (!window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Set background color to white
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color
    SDL_RenderClear(renderer); // Clear the window with the background color

    // Draw the line in black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black color

    TTF_Font *font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf", 16);
    if (!font) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        return 1;
    }

    drawLine(renderer, x1, y1, x2, y2);
    char text1[20], text2[20];
    snprintf(text1, sizeof(text1), "(%d, %d)", x1, y1);
    snprintf(text2, sizeof(text2), "(%d, %d)", x2, y2);
    drawText(renderer, x1, y1, text1, font); // Coordinates in black
    drawText(renderer, x2, y2, text2, font); // Coordinates in black

    SDL_RenderPresent(renderer);

    // Event loop to keep the window open until manually closed
    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
    }

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void drawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = dx / (float) steps;
    float yIncrement = dy / (float) steps;
    float x = x1;
    float y = y1;

    SDL_RenderDrawPoint(renderer, x, y);

    for (int i = 0; i < steps; i++) {
        x += xIncrement;
        y += yIncrement;
        SDL_RenderDrawPoint(renderer, x, y);
    }
}

void drawText(SDL_Renderer *renderer, int x, int y, const char *text, TTF_Font *font) {
    SDL_Color color = {0, 0, 0}; // Black color
    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect destRect;
    destRect.x = x;
    destRect.y = y;
    destRect.w = surface->w;
    destRect.h = surface->h;

    SDL_FreeSurface(surface);

    SDL_RenderCopy(renderer, texture, NULL, &destRect);
    SDL_DestroyTexture(texture);
}
