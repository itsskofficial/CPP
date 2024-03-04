#include<iostream>
using namespace std;

class Shape {
    public:

        // Function Overloading by  number of parameters
        float calcArea(int radius){
            float area = 3.14 * radius * radius;
            return area;
        }

        int calcArea(int height, int width){
            int area = height * width;
            return area;
        }

        // Function Overloadig by change in data type

//         int calcArea(int radius)
//         {
//             float area = 3.14 * radius * radius;
//             return area;
//         }

//         float calcArea(float radius)
//         {
//             float area = 3.14 * radius * radius;
//             return area;
//         }
};

int main(){

    float radius;
    int height, width;
    Shape s;
    cout<<"Enter radius of Circle: ";
    cin>>radius;
    cout<<"Area is: "<<s.calcArea(radius)<<endl;
    cout<<"Enter height and width of rectangle: ";
    cin>>height>>width;
    cout<<"Area is"<< s.calcArea(height, width);
    return 0;
}