#include<stdio.h>
#include<graphics.h>
#include<conio.h>

// Function to project 3D points to 2D using simple perspective projection
void project_3D_to_2D(int x, int y, int z, int *x2d, int *y2d, int d) {
    *x2d = x / (z + d);
    *y2d = y / (z + d);
}

// Function to draw a 3D cube projected onto a 2D screen
void draw_3D_cube() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Define the cube vertices in 3D space
    int cube_vertices[8][3] = {
        {-100, -100, -100}, // Vertex 0: (x, y, z)
        {100, -100, -100},  // Vertex 1
        {100, 100, -100},   // Vertex 2
        {-100, 100, -100},  // Vertex 3
        {-100, -100, 100},  // Vertex 4
        {100, -100, 100},   // Vertex 5
        {100, 100, 100},    // Vertex 6
        {-100, 100, 100}    // Vertex 7
    };

    // Distance from the screen (depth factor for projection)
    int d = 300;

    // Projected 2D coordinates
    int projected_2D[8][2];

    // Project all vertices from 3D to 2D
    for (int i = 0; i < 8; i++) {
        project_3D_to_2D(cube_vertices[i][0], cube_vertices[i][1], cube_vertices[i][2], 
                         &projected_2D[i][0], &projected_2D[i][1], d);
    }

    // Draw the front face of the cube
    line(projected_2D[0][0], projected_2D[0][1], projected_2D[1][0], projected_2D[1][1]);
    line(projected_2D[1][0], projected_2D[1][1], projected_2D[2][0], projected_2D[2][1]);
    line(projected_2D[2][0], projected_2D[2][1], projected_2D[3][0], projected_2D[3][1]);
    line(projected_2D[3][0], projected_2D[3][1], projected_2D[0][0], projected_2D[0][1]);

    // Draw the back face of the cube
    line(projected_2D[4][0], projected_2D[4][1], projected_2D[5][0], projected_2D[5][1]);
    line(projected_2D[5][0], projected_2D[5][1], projected_2D[6][0], projected_2D[6][1]);
    line(projected_2D[6][0], projected_2D[6][1], projected_2D[7][0], projected_2D[7][1]);
    line(projected_2D[7][0], projected_2D[7][1], projected_2D[4][0], projected_2D[4][1]);

    // Draw the edges connecting the front and back faces
    line(projected_2D[0][0], projected_2D[0][1], projected_2D[4][0], projected_2D[4][1]);
    line(projected_2D[1][0], projected_2D[1][1], projected_2D[5][0], projected_2D[5][1]);
    line(projected_2D[2][0], projected_2D[2][1], projected_2D[6][0], projected_2D[6][1]);
    line(projected_2D[3][0], projected_2D[3][1], projected_2D[7][0], projected_2D[7][1]);

    getch();
    closegraph();
}

void main() {
    draw_3D_cube();
}
