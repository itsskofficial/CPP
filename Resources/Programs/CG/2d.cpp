#include<iostream>
#include<graphics.h>
#include<winbgim.h>
#include<math.h>

using namespace std;

void findSCoordinate(int s[][2], int p[][1])
{
    int temp[2][1] = { 0 };
 
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 1; j++)
            for (int k = 0; k < 2; k++)
                temp[i][j] += (s[i][k] * p[k][j]);
 
    p[0][0] = temp[0][0];
    p[1][0] = temp[1][0];
}

void findTCoordinate(int t[][3], int p[][1])
{
    int temp[3][1] = {{0},{0},{1}};
 
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 1; j++)
            for (int k = 0; k < 3; k++)
            {
                temp[i][j] += (t[i][k] * p[k][j]);
            }
                

    cout << temp[0][0];
    cout << temp[0][1];
    p[0][0] = temp[0][0];
    p[1][0] = temp[1][0];
    p[2][0] = 1;
}

void findRCoordinate(float r[][3], int p[][1])
{
    float temp[3][1] = {{0},{0},{1}};
 
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 1; j++)
            for (int k = 0; k < 3; k++)
                temp[i][j] += (r[i][k] * p[k][j]);

    p[0][0] = temp[0][0];
    p[1][0] = temp[1][0];
    p[2][0] = 1;
}


void scale(int x[], int y[], int sx, int sy, int e)
{
    for (int i = 0; i < e; i++)
    {
        if (i==e-1)
        {
            line(x[i], y[i], x[0], y[0]);
        }

        else
            line(x[i],  y[i], x[i+1], y[i+1]);
    }
 
    int s[2][2] = { sx, 0, 0, sy };
    int p[2][1];
 
    for (int i = 0; i < e; i++)
    {
        p[0][0] = x[i];
        p[1][0] = y[i];
 
        findSCoordinate(s, p);
 
        x[i] = p[0][0];
        y[i] = p[1][0];
    }
 
    for (int i = 0; i < e; i++)
    {
        if (i==e-1)
        {
            line(x[i], y[i], x[0], y[0]);
        }

        else
            line(x[i],  y[i], x[i+1], y[i+1]);
    }
}

void translate(int x[], int y[], int tx, int ty, int e)
{
    for (int i = 0; i < e; i++)
    {
        if (i==e-1)
        {
            line(x[i], y[i], x[0], y[0]);
        }

        else
            line(x[i],  y[i], x[i+1], y[i+1]);
    }

    int t[3][3] = {{1, 0, tx},{0, 1, ty},{0,0, 1}};
    int p[3][1];

    for (int i = 0; i < e; i++)
    {
        p[0][0] =  x[i];
        p[1][0] =  y[i];
        p[2][0] = 1;

        findTCoordinate(t, p);

        x[i] = p[0][0];
        y[i] = p[1][0];
    }

    for (int i = 0; i < e; i++)
    {
        if (i==e-1)
        {
            line( x[i], y[i], x[0],y[0]);
        }

        else
            line(x[i], y[i], x[i+1], y[i+1]);
    }
}

void rotate(int x[], int y[], float theta, int e)
{
    for (int i = 0; i < e; i++)
    {
        if (i==e-1)
        {
            line(x[i], y[i], x[0], y[0]);
        }

        else
            line(x[i],  y[i], x[i+1], y[i+1]);
    }

    float r[3][3] = {{cos(theta),-sin(theta),0},{sin(theta),cos(theta),0},{0,0,1}};
    int p[3][1];

    for (int i = 0; i < e; i++)
    {
        p[0][0] = x[i];
        p[1][0] = y[i];
        p[2][0] = 1;


        findRCoordinate(r, p);

        x[i] = p[0][0];
        y[i] = p[1][0];
    }

    for (int i = 0; i < e; i++)
    {
        if (i==e-1)
        {
            line(x[i], y[i], x[0], y[0]);
        }

        else
            line(x[i],  y[i], x[i+1], y[i+1]);
    }

}

int main()
{
    int x[10];
    int y[10];
    int x1 = 300, y1 = 0, x2 = 300, y2 = 600;
    int x3 = 0, y3 = 250, x4 = 600, y4 = 250;
    int sx,sy ;
    int tx, ty;
    int gd = DETECT, gm = DETECT, choice, deg, e ,i ,j;
    float theta;
    initgraph(&gd, &gm, NULL);

    line(x1,y1,x2,y2);
    line(x3,y3,x4,y4);

    cout << "Enter no of edges: ";
    cin >> e;

    for (i = 0; i < e; i++)
    {
        cout << "Enter " << i + 1 << " edge coordinates: ";
        cin >> x[i] >> y[i];
        x[i] = x[i] + x1;
    }

    cout << "\nEnter your choice";
    cout<<"\n1.Translation"
            "\n2.Scaling"
            "\n3.Rotation\n\n";
    cin>>choice;
    
    switch(choice)
    {
        case 1:
            cout << "Enter translation coordinates: ";
            cin >> tx >> ty;
            translate(x, y, tx, ty,e);
            break;
        case 2:
            cout << "Enter scaling coordinates: ";
            cin >> sx >> sy;
            scale(x, y, sx,sy,e);
            break;
        case 3:
            cout << "Enter degree by which to rotate: ";
            cin >> deg;
            theta = deg * (3.14/180);
            rotate(x,y,theta,e);
            break;
        default:
            cout << "Wrong choice";
            break;
    }

    getch();
    return 0;
}