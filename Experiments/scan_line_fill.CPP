#include <graphics.h>
#include <stdio.h>
#include <conio.h>

// Function to find the intersection points of the polygon edges with a scanline
void find_intersections(int y, int points[], int num_points, int intersections[], int *num_intersections) {
    int i, j = 0;
    for (i = 0; i < num_points; i++) {
        int x1 = points[2 * i];
        int y1 = points[2 * i + 1];
        int x2 = points[2 * ((i + 1) % num_points)];
        int y2 = points[2 * ((i + 1) % num_points) + 1];

        if (y1 != y2) { // Skip horizontal edges
            if ((y >= y1 && y < y2) || (y >= y2 && y < y1)) {
                // Calculate intersection of scanline and edge using line equation
                int x_intersection = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
                intersections[j++] = x_intersection;
            }
        }
    }
    *num_intersections = j;
}

// Function to fill the polygon using scanline algorithm
void scanline_fill(int points[], int num_points) {
    int y, i;
    int ymax = points[1], ymin = points[1];

    // Find the min and max y-values of the polygon
    for (i = 1; i < num_points; i++) {
        if (points[2 * i + 1] > ymax) ymax = points[2 * i + 1];
        if (points[2 * i + 1] < ymin) ymin = points[2 * i + 1];
    }

    // Fill polygon between ymin and ymax scanlines
    for (y = ymin; y <= ymax; y++) {
        int intersections[20];
        int num_intersections;

        // Find the intersections of polygon edges with the current scanline
        find_intersections(y, points, num_points, intersections, &num_intersections);

        // Sort the intersections in increasing order of x
        for (i = 0; i < num_intersections - 1; i++) {
            for (int j = 0; j < num_intersections - i - 1; j++) {
                if (intersections[j] > intersections[j + 1]) {
                    int temp = intersections[j];
                    intersections[j] = intersections[j + 1];
                    intersections[j + 1] = temp;
                }
            }
        }

        // Draw lines between pairs of intersections
        for (i = 0; i < num_intersections; i += 2) {
            line(intersections[i], y, intersections[i + 1], y);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");

    // Example convex polygon (pentagon)
    int polygon_points[] = {200, 150, 400, 150, 500, 300, 400, 450, 200, 450};
    int num_points = sizeof(polygon_points) / (2 * sizeof(polygon_points[0]));

    // Set drawing color and clear the screen
    setcolor(GREEN);
    cleardevice();

    // Draw the polygon outline
    for (int i = 0; i < num_points - 1; i++) {
        line(polygon_points[2 * i], polygon_points[2 * i + 1], polygon_points[2 * (i + 1)], polygon_points[2 * (i + 1) + 1]);
    }
    // Closing the polygon
    line(polygon_points[2 * (num_points - 1)], polygon_points[2 * (num_points - 1) + 1], polygon_points[0], polygon_points[1]);

    // Fill the polygon using scanline fill algorithm
    scanline_fill(polygon_points, num_points);

    getch();
    closegraph();
    return 0;
}
