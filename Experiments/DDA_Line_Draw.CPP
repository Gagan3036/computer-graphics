#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

void drawline(int x1, int y1, int x2, int y2){
    int dx = x2 - x1;
    int dy = y2 - y1;
    
    int step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float x_inc = (float)dx/step;
    float y_inc = (float)dy/step;

    float x = x1, y = y1;

    while(1){
        if(x == x2 && y == y2){
            break;
        }
        putpixel(round(x), round(y), WHITE);
        x = x + x_inc;
        y = y + y_inc;
    }
}

int main(){
    int gdriver = DETECT, gmode, x1, y1, x2, y2;
    initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
    printf("Enter initial co-ordinates: ");
    scanf("%d%d", &x1, &y1);
    printf("Enter final co-ordinates: ");
    scanf("%d%d", &x2, &y2);
    drawline(x1, y1, x2, y2);
    getch();
    return 0;
}