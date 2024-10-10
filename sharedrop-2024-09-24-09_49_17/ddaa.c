#include <graphics.h>
#include <math.h>
void main( )
{
 printf("DDA line drawing algorithm");
float x,y,x1,y1,x2,y2,dx,dy,step;

int i,gd=DETECT,gm;
initgraph(&gd,&gm,"");
printf("DDA line drawing algorithm");
setbkcolor(BLACK);  
x1 = 100 , y1 = 200, x2 = 500, y2 = 300;  
dx=abs(x2-x1);
dy=abs(y2-y1);
if(dx>=dy)
step=dx;
else
step=dy;
dx=dx/step;
dy=dy/step;
x=x1;
y=y1;
i=1;
while(i<=step)
{
putpixel(x,y,7);
x=x+dx;
y=y+dy;
i=i+1;
delay(100);
}

closegraph();
}
