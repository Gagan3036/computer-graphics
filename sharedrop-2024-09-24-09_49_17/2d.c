#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>

int main() {
    int gd = DETECT, gm;
    int x1, x2, x3, y1, y2, y3;
    int nx1, nx2, nx3, ny1, ny2, ny3;
    int xt, yt;

    printf("\tProgram for Basic Translation\n");
    printf("\nEnter the Points of Triangle (x1 y1 x2 y2 x3 y3): ");
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

    printf("\nEnter the Translation Factors (xt yt): ");
    scanf("%d%d", &xt, &yt);

    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    // Draw the original triangle
    setcolor(WHITE); // Set color for the original triangle
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Calculate new points after translation
    nx1 = x1 + xt;
    ny1 = y1 + yt;
    nx2 = x2 + xt;
    ny2 = y2 + yt;
    nx3 = x3 + xt;
    ny3 = y3 + yt;

    // Draw the translated triangle in a different color
    setcolor(YELLOW); // Set color for the translated triangle
    line(nx1, ny1, nx2, ny2);
    line(nx2, ny2, nx3, ny3);
    line(nx3, ny3, nx1, ny1);

    // Hold the screen to view the result
    delay(5000);

    // Close graphics mode
    closegraph();
    return 0;
}

