#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>

void main(){
    int gd = DETECT, gm;
    int x1, x2, x3, y1, y2, y3;
    int nx1, nx2, nx3, ny1, ny2, ny3;
    int sx, sy;

    printf("\tProgram For 2D Scaling Of a Triangle\n");
    printf("\n\tEnter the points of Triangle(x1, y1, x2, y2, x3, y3): ");
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

    printf("\nEnter the scaling factor(xt, yt): ");
    scanf("%d%d", &sx, &sy);

    initgraph(&gd, &gm, "C:\\turboc3\\bgi");

    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);

    nx1 = (int)(x1 * sx);
    nx2 = (int)(x2 * sx);
    nx3 = (int)(x3 * sx);
    ny1 = (int)(y1 * sy);
    ny2 = (int)(y2 * sy);
    ny3 = (int)(y3 * sy);

    line(nx1, ny1, nx2, ny2);
    line(nx2, ny2, nx3, ny3);
    line(nx3, ny3, nx1, ny1);

    getch();
    closegraph();
}
/*
Input sample cordinates:
(x1, y1) = (100, 100)
(x2, y2) = (200, 100)
(x3, y3) = (150, 50)

(xt, yt) = (2, 2)
*/