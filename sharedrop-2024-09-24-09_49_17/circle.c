#include <graphics.h>
#include <math.h>
void main() {
int x, y, xmid, ymid, radius, dp;
int gd = DETECT, gm;
printf(" Enter the coordinates");
scanf("%d %d", &xmid,&ymid);
printf(" Enter the radius");
scanf("%d", &radius);
 initgraph(&gd, &gm, "");
 printf("Midpoint circle drawing algorithm\n");
 x = 0;
 y = radius;
 dp = 1 - radius;
  do {
        putpixel(xmid + x, ymid + y, YELLOW);
        putpixel(xmid + y, ymid + x, WHITE);
        putpixel(xmid - y, ymid + x, YELLOW);
        putpixel(xmid - x, ymid + y, WHITE);
        putpixel(xmid - x, ymid - y, YELLOW);
        putpixel(xmid - y, ymid - x, WHITE);
        putpixel(xmid + y, ymid - x, YELLOW);
        putpixel(xmid + x, ymid - y, WHITE);

        if (dp < 0) {
            dp += 2 * x + 3;
        } else {
            dp += 2 * (x - y) + 5;
            y--;
        }
        x++;
    } while (x <= y);
  delay(5000); // Delay to show the circle before closing
    closegraph();
}

