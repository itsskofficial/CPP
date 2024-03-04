#include<iostream>
using namespace std;

class Shape {
    float radius;
    float height, width;
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
};

class Quadrangle: public Shape{
    float  calcArea(){
        float area = height *  width;
        return area;
    }
};

int main(){
    Quadrangle q;
    cout<<"Enter height and width: ";
    cin
    return 0;
}