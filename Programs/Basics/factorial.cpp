#include <iostream>
using namespace std;

int factorial(int n)
{
    int fact = 1;
    for (int i = n; i > 0; i--)
    {
        fact = fact * i;
    }
    return fact;
}

int main()
{
    int n;
    int fact;

    cout << "Enter a number: ";
    cin >> n;
    fact = factorial(n);
    cout << "The factorial of " << n << " is " << fact;

    return 0;
}
