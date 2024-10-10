#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>

void main() {
    int gm, gd = DETECT;
    int x1, y1, x2, y2, x3, y3;
    int nx1, ny1, nx2, ny2, nx3, ny3;
    float sx, sy; // Scaling factors

    printf("\t Program for 2D Scaling of a Triangle\n");
    printf("\n\t Enter the coordinates of the triangle:\n");
    printf("Format: x1 y1 x2 y2 x3 y3\n");
    
    // Take all triangle coordinates in one line
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

    printf("\nEnter the scaling factors (sx sy): ");
    scanf("%f%f", &sx, &sy); // Take scaling factors separately

    initgraph(&gd, &gm, ""); // Initialize graphics mode

    // Draw the original triangle
    setcolor(WHITE); // Original triangle color
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Calculate new coordinates after scaling
    nx1 = x1 * sx;
    ny1 = y1 * sy;
    nx2 = x2 * sx;
    ny2 = y2 * sy;
    nx3 = x3 * sx;
    ny3 = y3 * sy;

    // Draw the scaled triangle
    setcolor(RED); // Change color for the scaled triangle
    line(nx1, ny1, nx2, ny2);
    line(nx2, ny2, nx3, ny3);
    line(nx3, ny3, nx1, ny1);

    delay(5000); // Wait for 5 seconds
    closegraph(); // Close graphics mode
}

