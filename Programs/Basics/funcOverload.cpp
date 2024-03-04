#include<iostream>
using namespace std;

class Shape {
    public:

        float calcArea(int radius){
            float area = 3.14 * radius * radius;
            return area;
        }

        int calcArea(int height, int width){
            int area = height * width;
            return area;
        }
};

int main(){

    float radius;
    int height, width;
    Shape s;
    cout<<"Enter radius of Circle: ";
    cin>>radius;
    cout<< s.calcArea(radius);
    return 0;
}