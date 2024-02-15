//including libraries and using namespace std
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

//window drawing method
void window(float xmin,float xmax, float ymin, float ymax) //accepting window coordinates
{
	line(xmin,ymin,xmax,ymin);
	line(xmax,ymin,xmax,ymax);
	line(xmax,ymax,xmin,ymax);
	line(xmin,ymax,xmin,ymin);
}

void code(char code[4], float x, float y, float xmin, float xmax, float ymin, float ymax) //accepting code
{       
	//using ternary operator to get code
	code[0]=(x<xmin)?'1':'0';
	code[1]=(x>xmax)?'1':'0';
	code[2]=(y<ymin)?'1':'0';
	code[3]=(y>ymax)?'1':'0';
}

void clipping (char primary_code[], char secondary_code[], float &x, float &y, float m, float xmin, float xmax, float ymin, float ymax) //& used to implement changes on original argument
{
	int flag=1,i=0; //flag to verify boolean info

	for (i=0;i<4;i++)
	{
		if(primary_code[i]=='1' && secondary_code[i]=='1')
		{
			flag=0; //if both end points lie outside the window set flag to 0 and break
			break;
		}

		if(flag==1) //if one point lies outside and one inside
		{
			if(primary_code[0]=='1') //checking xmin
			{
				y=m*(xmin-x)+y; //formula
				x=xmin;
			}

			else if(primary_code[1]=='1') //checking xmax
			{
				y=m*(xmax-x)+y; //formula
				x=xmax;
			}

			else if(primary_code[2]=='1') //checking ymin
			{
				x=((ymin-y)/m)+x; //formula
				y=ymin;
			}

			else if(primary_code[3]=='1')  //checking ymax
			{
				x=((ymax-y)/m)+x; //formula
				y=ymax;
			}
		}

		if (flag==0)
			cout<<"Line lying outside";
	}
}

int main()
{
	int gd = DETECT, gm; 
	float x1,y1,x2,y2,xmin,ymin,xmax,ymax; //declare line and window coordinates
	float m; //declare slope
	char first_code[4],second_code[4]; //declare codes for both the line points
	int temp; //temporary variable

	initgraph(&gd, &gm, NULL); //initialize graph

	//get window coordinates
	cout << "Enter xmin and xmax for window: ";
	cin >> xmin >> xmax;
	cout << "Enter ymin and ymax for window: ";
	cin >> ymin >> ymax;

	//get line coordinates
	cout<<"Enter line coordinates";
	cin>>x1>>y1>>x2>>y2; 

	//display window and line before clipping
	cout<<"Before clipping";
	window(xmin,xmax,ymin,ymax);
	line(x1,y1,x2,y2);

	cin>>temp; //get a temporary number to proceed with further execution
	cleardevice(); //clear device

	m=float((y2-y1)/(x2-x1)); //get slope of line

	//get codes for both the points
	code(first_code,x1,y1,xmin,xmax,ymin,ymax);
	code(second_code,x2,y2,xmin,xmax,ymin,ymax);

	//clip the line for both the points swapping both codes alternately
	clipping(first_code,second_code,x1,y1,m,xmin,xmax,ymin,ymax);
	clipping(second_code,first_code,x2,y2,m,xmin,xmax,ymin,ymax);

	//display line and window after clipping
	cout<<"After Clipping";
	window(xmin,xmax,ymin,ymax);
	line(x1,y1,x2,y2);

	getch();
	closegraph(); //close the graph
	return 0;
}