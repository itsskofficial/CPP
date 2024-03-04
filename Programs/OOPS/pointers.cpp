#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int num = 12;
    int *p;
    p = &num;
    cout<<p<<endl;
    cout << &num << endl;
    cout << *p << endl;

    *p = 16;
    cout << "Value: " << num << endl;

    p++;
    *p = 34;
    cout << "Value: " << *p << endl;

    return 0;
}