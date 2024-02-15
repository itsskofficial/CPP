//including libraries and using namespace std
#include<iostream>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<conio.h>
using namespace std;

//driver code
int main()
{
    int x=250,y=250; //initial position of ball
    int dx, dy; //change in coordinates
    char ch; //choice
    int gd=DETECT,gm, flag;
    char *msg; //char pointer for msg
    msg[0]='s';
    initgraph(&gd,&gm,NULL);
    while(1)
    {
        flag = 0;
        dx = 0, dy = 0;
        circle(x,y,30); //draw circle with radius 30
        outtextxy(400,400,msg); //display text at a specific position

        if(kbhit()) //check for keystrokes
        {
            ch=getch();
            flag = 1;
        }

        if(int(ch)==72) //if up arrow key is pressed
        {
            dx=0;
            dy=-5;
        }

        else if(int(ch)==75) //if left arrow key is pressed
        {
            dx=-5;
            dy=0;
        }

        else if(int(ch)==77) //if right arrow key is pressed
        {
            dx=5;
            dy=0;
        }

        else if(int(ch)==80) //if down arrow key is pressed
        {
            dx=0;
            dy=5;
        }

        else if(int(ch)==27) //if escape key is pressed
        {
            exit(0);
        }

        if (flag==1) //if keystroke is pressed change coordinates for next iteration of loop
        {
            x=x+dx;
            y=y+dy;
            delay(50);
            cleardevice();
        }
    }
    
    return 0;
}
    