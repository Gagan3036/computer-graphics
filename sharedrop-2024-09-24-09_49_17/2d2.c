#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>

void main() {
    int gm, gd = DETECT;
    int x1, y1, x2, y2, x3, y3; // Original triangle coordinates
    int nx1, ny1, nx2, ny2, nx3, ny3; // Rotated triangle coordinates
    float angle, t; // Angle in degrees and radians

    printf("\t Program for Triangle Rotation\n");
    printf("\n\t Enter the Points of Triangle:\n");
    printf("Format: x1 y1 x2 y2 x3 y3\n");
    
    // Input the coordinates of the triangle
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    
    printf("\nEnter the angle of rotation (in degrees): ");
    scanf("%f", &angle); // Input angle of rotation

    // Convert angle from degrees to radians
    t = angle * (M_PI / 180); // Using M_PI from math.h

    initgraph(&gd, &gm, ""); // Initialize graphics mode

    // Draw the original triangle
    setcolor(WHITE); // Original triangle color
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Calculate new coordinates after rotation
    nx1 = x1 * cos(t) - y1 * sin(t);
    ny1 = x1 * sin(t) + y1 * cos(t);
    nx2 = x2 * cos(t) - y2 * sin(t);
    ny2 = x2 * sin(t) + y2 * cos(t);
    nx3 = x3 * cos(t) - y3 * sin(t);
    ny3 = x3 * sin(t) + y3 * cos(t);

    // Draw the rotated triangle
    setcolor(RED); // Change color for the rotated triangle
    line(nx1, ny1, nx2, ny2);
    line(nx2, ny2, nx3, ny3);
    line(nx3, ny3, nx1, ny1);

    delay(5000); // Wait for 5 seconds to view the result
    closegraph(); // Close graphics mode
}

