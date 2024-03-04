#include<iostream>
using namespace std;
void swap(int x, int  y)        // call by value
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void new_swap(int *x, int  *y)      // call by reference
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    int num1 = 15, num2 = 34;
    swap(num1, num2);
    cout<<num1<<" "<<num2<<endl;
    new_swap(&num1,&num2);
    cout<<num1<<" "<<num2<<endl;
    return 0;
}