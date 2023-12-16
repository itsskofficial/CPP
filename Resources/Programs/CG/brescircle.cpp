//including the libraries and using namespace std
#include <iostream>
#include <graphics.h>
using namespace std;

//eight way circle drawing method
void  drawCircle(int x, int y, int xc, int yc)
{
     putpixel(x+xc,y+yc,WHITE);
     putpixel(-x+xc,y+yc,WHITE);
     putpixel(x+xc,-y+yc,WHITE);
     putpixel(-x+xc,-y+yc,WHITE);
     putpixel(y+xc,x+yc,WHITE);
     putpixel(y+xc,-x+yc,WHITE);
     putpixel(-y+xc,x+yc,WHITE);
     putpixel(-y+xc,-x+yc,WHITE);
}

int main()
{
     int gd = DETECT, gm, xc, yc, r;
     initgraph(&gd, &gm, NULL); //initialize graph
     cout << "Enter center coordinates: ";
     cin >> xc >> yc;
     cout << "Enter radius of circle: ";
     cin >> r;
     int x = 0;
     int y = r;
     int d = 3 - 2 * r;

     //bresenham algorithm
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
          
          drawCircle(x,y,xc,yc);
          delay(50);
     }

     getch();
     closegraph(); //close graph
     return 0;
}


 






















