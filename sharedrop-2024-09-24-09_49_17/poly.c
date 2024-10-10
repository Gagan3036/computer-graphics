#include <graphics.h>
#include <stdio.h>
void draw_polygon(int points[], int num_points) {
    int i;
    for (i = 0; i < num_points - 1; i++) {
        line(points[2*i], points[2*i + 1], points[2*(i+1)], points[2*(i+1) + 1]);
    }
    line(points[2*(num_points - 1)], points[2*(num_points - 1) + 1], points[0], points[1]);
}
int main() {
    int gd = DETECT, gm;
    int choice;
    int convex_points[] = {250, 180, 400, 150, 500, 300, 400, 450, 200, 450};
    int concave_points[] = {
        100, 100,  // Point A
        300, 100,  // Point B
        350, 150,  // Point C (sharp indentation)
        200, 200,  // Point D (crossing point)
        350, 250,  // Point E
        300, 300,  // Point F
        100, 250   // Point G
    };
    int num_convex_points = sizeof(convex_points) / sizeof(convex_points[0]) / 2;
    int num_concave_points = sizeof(concave_points) / sizeof(concave_points[0]) / 2;
    initgraph(&gd, &gm, "");
    cleardevice();
    printf("Enter 1 for Convex Polygon or 2 for Concave Polygon: ");
    scanf("%d", &choice);
    if (choice == 1) {
        setcolor(RED);
        draw_polygon(convex_points, num_convex_points);
    } else if (choice == 2) {
        setcolor(YELLOW);
        draw_polygon(concave_points, num_concave_points);
    } else {
        printf("Invalid choice. Please enter 1 or 2.\n");
    }
    getch(); // Wait for user to press a key
    delay(5000); // Keep the window open for 5 seconds
    closegraph();
    return 0;
}

