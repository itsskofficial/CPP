#include <iostream>
using namespace std;

class Person
{
    public:
        string name;
        int age;  

    void show()
    {
        cout << name << endl;
        cout << age << endl;
    }

    void isEligible()
    {
        if (age >= 18)
            cout << name << "is eligible for driving";
        else 
            cout << name << " is not eligible for driving";
    }
};

int main()
{
    Person p1;
    p1.name = "Sarthak";
    p1.age = 10;
    p1.show();
    p1.isEligible();

    return 0;
}