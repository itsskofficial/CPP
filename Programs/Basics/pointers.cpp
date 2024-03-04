#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int num[] = {23,56,11,64,33};
    // int num = 12;
    int *p, i;
    p = &num[0];
    // cout<<p<<endl;
    // cout << &num << endl;
    // cout << *p << endl;
    for (i=0;i<5;i++){
        *p+=10;
        cout<<num[i]<<endl;
        p++;
    }
    for(i=0;i<5;i++)
        cout<<num[i]<<endl;
        

    // *p = 16;
    // cout << "Value: " << num << endl;

    // p++;
    // *p = 34;
    // cout << "Value: " << *p << endl;

    // p--;
    // cout << "Value " << *p << endl;

    return 0;
}