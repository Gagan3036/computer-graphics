#include <graphics.h>
void boundaryfill(int x, int y, int fillColor, int boundaryColor) {
    int currentColor = getpixel(x, y);
    if (currentColor != boundaryColor && currentColor != fillColor) {
        putpixel(x, y, fillColor);
        boundaryfill(x+1, y, fillColor, boundaryColor); // Right
        boundaryfill(x, y+1, fillColor, boundaryColor); // Down
        boundaryfill(x-1, y, fillColor, boundaryColor); // Left
        boundaryfill(x, y-1, fillColor, boundaryColor); // Up
    }
}
void drawPolygon(int vertices[][2], int n) {
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        line(vertices[i][0], vertices[i][1], vertices[next][0], vertices[next][1]);
    }
}
void drawRectangle(int x1, int y1, int x2, int y2) {
    rectangle(x1, y1, x2, y2);
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); 
    printf("Boundary fill Algorithm");
    int triangleVertices[][2] = {{100, 100}, {200, 100}, {150, 200}};
    int triangleCount = sizeof(triangleVertices) / sizeof(triangleVertices[0]);
    int rectX1 = 300, rectY1 = 100, rectX2 = 400, rectY2 = 200;
    drawPolygon(triangleVertices, triangleCount);
    drawRectangle(rectX1, rectY1, rectX2, rectY2);
    int triangleFillColor = RED;
    int rectangleFillColor = BLUE;
    int boundaryColor = WHITE;
    int triangleFillX = 150, triangleFillY = 150;
    boundaryfill(triangleFillX, triangleFillY, triangleFillColor, boundaryColor);
    int rectFillX = 350, rectFillY = 150;
    boundaryfill(rectFillX, rectFillY, rectangleFillColor, boundaryColor);
    delay(7000);
    closegraph(); // Close graphics mode
    return 0;
}

