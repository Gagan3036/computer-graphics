#include <stdio.h>
#include <graphics.h>
void drawEllipse(int rx, int ry, int xc, int yc) {
    int x = 0, y = ry;
    int d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    int dx = 2 * ry * ry * x;
    int dy = 2 * rx * rx * y;
    while (dx < dy) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        if (d1 < 0) {
            x++;
            dx += 2 * ry * ry;
            d1 += dx + (ry * ry);
        } else {
            x++;
            y--;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            d1 += dx - dy + (ry * ry);
        }
    }
 int d2 = (ry * ry) * ((x + 0.5) * (x + 0.5)) + (rx * rx) * ((y - 1) * (y - 1)) - (rx * rx * ry * ry);
    while (y >= 0) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        if (d2 > 0) {
            y--;
            dy -= 2 * rx * rx;
            d2 += (rx * rx) - dy;
        } else {
            y--;
            x++;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            d2 += dx - dy + (rx * rx);
        }
    }
}
int main() {

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
printf("MIDPOINT ellipse Drawing algorithm");
 drawEllipse(200, 100,280,230);
    getch(); // Wait for a key press
    closegraph(); // Close the graphics mode
    return 0;
}

