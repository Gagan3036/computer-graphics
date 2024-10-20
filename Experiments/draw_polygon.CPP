#include<graphics.h>
#include<stdio.h>
#include<conio.h>

void draw_polygon(int points[], int num_points){
    int i;
    for(i = 0; i < num_points - 1; i++){
        line(points[2*i], points[2*i + 1], points[2*(i+1)], points[2*(i+1) + 1]);
    }
    line(points[2*(num_points-1)], points[2*(num_points - 1) + 1], points[0], points[1]);
}

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");

    int choice;

    int convex_points[] = {200, 150, 400, 150, 500, 300, 400, 450, 200, 450};

    int concave_points[] = {200, 150, 300, 100, 400, 150, 450, 150, 450, 200, 
                            350, 250, 300, 200, 250, 250, 200, 200};

    int num_convex_points = sizeof(convex_points) / sizeof(convex_points[0]) / 2;
    int num_concave_points = sizeof(concave_points) / sizeof(concave_points[0]) / 2;

    printf("Enter 1 for convax polygon or 2 for concave polygon: ");
    scanf("%d", &choice);

    setcolor(WHITE);
    cleardevice();

    if(choice == 1){
        draw_polygon(convex_points, num_convex_points);
    }
    else if(choice == 2){
        draw_polygon(concave_points, num_concave_points);
    }
    else{
        printf("Invalid choice");
    }

    getch();
    closegraph();
    return 0;
}