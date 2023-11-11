//including the libraries and using namespace std
#include<graphics.h>
#include<iostream>
using namespace std;

int main()
{
    float x,y,x1,y1,x2,y2,dx,dy,step;
    int i,gd=DETECT,gm;
    initgraph(&gd,&gm,NULL); //initialize graphic function

    cout<<"***DDA LINE****"<<endl;
    cout<<"Enter the value of x1 and y1 : ";
    cin>>x1>>y1;
    cout<<"Enter the value of x2 and y2: ";
    cin>>x2>>y2;

    dx=abs(x2-x1);
    dy=abs(y2-y1);

    if(dx>=dy)
        step=dx;
    else
        step=dy;

    //this condition is very important
    dx = (x1 > x2) ? -dx / step : dx / step; 
    dy = (y1 > y2) ? -dy / step : dy / step;

    x=x1;
    y=y1;

    //repeat till i reaches step
    for(int i=1;i<=step;i++)
    {
        putpixel(x,y,WHITE);
        x=x+dx;
        y=y+dy;
        delay(50);
    }

    return 0;
 }










 