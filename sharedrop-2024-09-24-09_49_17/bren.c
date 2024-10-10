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
int x0, y0, x1, y1;
    initgraph(&gd, &gm, NULL);
printf("Bresenham's line drawing algorithm");
    // Draw a line from (100, 100) to (400, 300)
    drawLine(100, 100, 400, 300);
  delay(5000); // Delay for 5 seconds before closing
 closegraph();
    return 0;
}

