#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

// Function to draw a line using Bresenham's algorithm
void drawLine(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;
    int e2;

    while (1) {
        putpixel(x0, y0, WHITE);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx) { err += dx; y0 += sy; }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x0, y0, x1, y1;

    printf("Enter coordinates of the first point (x0 y0): ");
    scanf("%d %d", &x0, &y0);
    printf("Enter coordinates of the second point (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    // Draw a line using Bresenham's algorithm with user input coordinates
    drawLine(x0, y0, x1, y1);

    delay(5000); // Delay for 5 seconds before closing

    closegraph();
    return 0;
}

