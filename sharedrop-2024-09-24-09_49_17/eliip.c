#include <stdio.h> 
#include<graphics.h>
void mptellipse(int rx,int ry,int xc,int yc)
{
float dx,dy,d1,d2,x,y;
x = 0;
y =ry;
d1=(ry*ry)-(rx*rx*rx)+(0.25*rx*rx);
dx = 2*ry*ry+x;
dy = 2*ry*rx+y;
while(dx<dy)
{
printf("(%f %f)\n",x+xc,y+yc);
printf("(%f %f)\n",-x+xc,y+yc);
printf("(%f %f)\n",x+xc,y+yc);
printf("(%f %f)\n",-x+xc,y+yc);
if(d1<0)
{
x++;
dx=dx(2*ry*rx);
d1=d1+(rx*rx)-dy;
}
else
{
y--;
x++;
dx=dx+dx(2*ry*ry);
d2=d2+(dx*dx)-ry+rx;
}
}
}
int main(){
mptellipse(10,15,50,50);
return 0;
}

