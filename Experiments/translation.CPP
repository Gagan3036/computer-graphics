#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>

void main(){
    int gd = DETECT, gm;
    int x1, x2, x3, y1, y2, y3;
    int nx1, nx2, nx3, ny1, ny2, ny3;
    int xt, yt;

    printf("\tProgram For Basic Translation Of Triangle\n");
    printf("\n\tEnter the points of Triangle(x1, y1, x2, y2, x3, y3): ");
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

    printf("\nEnter the translation factor(xt, yt): ");
    scanf("%d%d", &xt, &yt);

    initgraph(&gd, &gm, "C:\\turboc3\\bgi");

    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);

    nx1 = x1 + xt;
    nx2 = x2 + xt;
    nx3 = x3 + xt;
    ny1 = y1 + yt;
    ny2 = y2 + yt;
    ny3 = y3 + yt;

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

(xt, yt) = (50, 50)
*/