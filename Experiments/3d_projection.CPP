#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include<conio.h>

// Function to project a 3D point to 2D
void projectPoint(float x, float y, float z, int *x2D, int *y2D) {
    float d = 300; // distance from the viewer
    *x2D = (int)(d * x / (d + z)); // Perspective projection formula for x
    *y2D = (int)(d * y / (d + z)); // Perspective projection formula for y
}

// Function to draw a 3D cube
void drawCube(int centerX, int centerY, int size) {
    // Vertices of the cube in 3D space
    float vertices[8][3] = {
        {-size, -size, -size}, {size, -size, -size}, {size, size, -size}, {-size, size, -size},
        {-size, -size, size},  {size, -size, size},  {size, size, size},  {-size, size, size}
    };

    int projected[8][2]; // Array to store projected 2D coordinates

    // Projecting vertices from 3D to 2D
    for (int i = 0; i < 8; i++) {
        int x2D, y2D;
        projectPoint(vertices[i][0] + centerX, vertices[i][1] + centerY, vertices[i][2] + 200, &x2D, &y2D);
        projected[i][0] = x2D;
        projected[i][1] = y2D;
    }

    // Drawing edges of the cube
    for (int j = 0; j < 4; j++) {
        // Front face
        line(projected[j][0], projected[j][1], projected[(j + 1) % 4][0], projected[(j + 1) % 4][1]);
        // Back face
        line(projected[j + 4][0], projected[j + 4][1], projected[(j + 1) % 4 + 4][0], projected[(j + 1) % 4 + 4][1]);
        // Connecting front and back face vertices
        line(projected[j][0], projected[j][1], projected[j + 4][0], projected[j + 4][1]);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");

    setcolor(WHITE);

    // Simple loop to draw the cube for a limited time
    for (int i = 0; i < 100; i++) {
        cleardevice();
        drawCube(getmaxx() / 2, getmaxy() / 2, 50); // Draw cube at the center of the screen
    }

    getch();
    closegraph();
    return 0;
}
