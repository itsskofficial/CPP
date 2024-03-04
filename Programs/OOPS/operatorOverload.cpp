#include<iostream>
using namespace std;

class Person
{
    public:
        string name;
        int age;
        int salary;

        Person(string n, int a, int salary)
        {
            name = n;
            age = a;
        }

Person operator + (Person &obj)
{
    obj.age = age + obj.age;
    obj.salary = salary + obj.salary;
    obj.name = "Saiee";

    return obj;
}

void show()
{
    cout << name << age << salary;
}
};

int main()
{
    Person p1("Sarthak", 24, 3000);
    Person p2("Aniket", 25, 3030);
    Person p3 = p1 + p2;
    p3.show();

    return 0;
}