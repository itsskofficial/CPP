//include the libraries and use namespace std
#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

//using dda line algo
void drawLine(int x1, int y1, int x2, int y2)
{
    float x, y, dx, dy, step, temp;
    int i;

    dx=abs(x2-x1);
    dy=abs(y2-y1);

    if(dx>dy)
        step=abs(dx);
    else
        step=abs(dy);

    //this condition is important
    dx = (x1 > x2) ? -dx / step : dx / step;
    dy = (y1 > y2) ? -dy / step : dy / step;

    x=x1;
    y=y1;

    //dda algorithm
    for(int i=1;i<=step;i++)
    {
        putpixel(x,y,WHITE);
        x=x+dx;
        y=y+dy;
    }
}

//eight way circle drawing method
void drawCircle(int xc, int yc, int x, int y)
{
    putpixel(xc+x, yc+y, WHITE);
    putpixel(xc-x, yc+y, WHITE);
    putpixel(xc+x, yc-y, WHITE);
    putpixel(xc-x, yc-y, WHITE);
    putpixel(xc+y, yc+x, WHITE);
    putpixel(xc-y, yc+x, WHITE);
    putpixel(xc+y, yc-x, WHITE);
    putpixel(xc-y, yc-x, WHITE);
}

void bresCircle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;
    while(x<=y)
    {
        x++;
        
        if (d>0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }

        else
        {
            d = d + 4*x + 6;
        }

        drawCircle(xc,yc,x,y);
        delay(50);
    }
}

//triangle drawing method
void drawTriangle(int x1,int y1, int x2, int y2, int x3, int y3)
{
    drawLine(x1, y1, x2, y2);
    drawLine(x1, y1, x3, y3);
    drawLine(x2, y2, x3, y3);
}

//function to calculate radius and center coordinates using simple math
void inCircle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int xc, yc, r, h, a;
    xc = (x1 + x2 + x3) / 3;
    yc = (y1 + y2 + y3) / 3;
    a = sqrt((abs(x2 - x1) * abs(x2 - x1)) - abs((y2 - y1) * (y2 - y1)));
    h = (1.71 * a) / 2;
    r = h / 3;
    bresCircle(xc, yc, r);
}

//function to calculate radius and center coordinates using simple math
void circumCircle(int x1, int y1, int x2, int y2, int x3, int y3) 
{   
    int xc, yc, r, h, a;     
    xc = (x1 + x2 + x3) / 3; 
    yc = (y1 + y2 + y3) / 3;     
    a = sqrt((abs(x2 - x1) * abs(x2 - x1)) - abs((y2 - y1) * (y2 - y1)));     
    h = (1.71 * a) / 2;     
    r = (2 * h) / 3;     
    bresCircle(xc, yc, r); 
}  

//driver code
int main()
{
    int x1, y1, x2, y2,x3,y3, gd=DETECT, gm;
    initgraph(&gd, &gm, NULL); //initialize graph

    cout << "Enter coordinates of first point: ";
    cin >> x1 >> y1;
    cout << "\nEnter coordinates of second point: ";
    cin >> x2 >> y2;
    cout << "\nEnter coordinates of third point: ";
    cin >> x3 >> y3;

    drawTriangle(x1, y1, x2, y2, x3, y3);
    inCircle(x1, y1, x2, y2, x3, y3);
    circumCircle(x1, y1, x2, y2, x3, y3);    

    getch();
    closegraph(); //close the grapg
    return 0;
}