#include<stdio.h>
#include<graphics.h>

void drawCircleAndCoordinates(int x_center, int y_center, int radius){
    int x = 0;
    int y = radius;
    int p = 1 - radius; 

    // Draw Circle Using midpoint Circle Algorithm 
    while(x < y){
        putpixel(x_center + x, y_center + y, WHITE);
        putpixel(x_center - x, y_center + y, WHITE);
        putpixel(x_center + x, y_center - y, WHITE);
        putpixel(x_center - x, y_center - y, WHITE);
        
        // If the generated point is on the line x = y then 
        // the perimeter points have already been printed
        if(x != y){
            putpixel(x_center + y, y_center + x, WHITE);
            putpixel(x_center - y, y_center + x, WHITE);
            putpixel(x_center + y, y_center - x, WHITE);
            putpixel(x_center - y, y_center - x, WHITE);
        }

        x++;

        if(p < 0){
            p = p + 2 * x + 1;
        }
        else{
            y--;
            p = p + 2 * (x - y) + 1;
        }
    }

    // Drawing Coordinates 
    char coordText[50];
    sprintf(coordText, "Center: (%d, %d)", x_center, y_center);
}

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");

    int x_center = 320;
    int y_center = 240;
    int radius = 100;

    drawCircleAndCoordinates(x_center, y_center, radius);

    getch();
    closegraph();

    return 0;
}