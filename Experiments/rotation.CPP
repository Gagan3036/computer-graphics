#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

void main(){
    int gd = DETECT, gm;
    int x1, x2, x3, y1, y2, y3;
    int nx1, nx2, nx3, ny1, ny2, ny3;
    float angle, t;

    printf("\tProgram Basic Rotation Of a Triangle\n");
    printf("\n\tEnter the points of Triangle(x1, y1, x2, y2, x3, y3): ");
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

    printf("\nEnter the angle rotation(In Degree): ");
    scanf("%f", &angle);

    t = angle * (3.14 / 180);

    initgraph(&gd, &gm, "C:\\turboc3\\bgi");

    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);

    nx1 = (int)(x1 * cos(t) - y1 * sin(t));
    nx2 = (int)(x2 * cos(t) - y2 * sin(t));
    nx3 = (int)(x3 * cos(t) - y3 * sin(t));
    ny1 = (int)(x1 * sin(t) + y1 * cos(t));
    ny2 = (int)(x2 * sin(t) + y2 * cos(t));
    ny3 = (int)(x3 * sin(t) + y3 * cos(t));

    line(nx1, ny1, nx2, ny2);
    line(nx2, ny2, nx3, ny3);
    line(nx3, ny3, nx1, ny1);

    getch();
    closegraph();
}
/*
Sample Coordinates:
(x1, y1) = (100, 100)
(x2, y2) = (200, 100)
(x3, y3) = (150, 50)

Angle = 45 degrees
*/