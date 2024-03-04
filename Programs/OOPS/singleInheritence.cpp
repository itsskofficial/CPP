#include<iostream>
using namespace std;

class Animal{
    protected:
    int legs;
    public:
        void sleep(){
            cout<<"Sleeping";
        }
        void eat(){
            cout<<"Eating";
        }
};

class Dog: protected Animal{
    public:
    void bark(){
        cout<<"Barking...";
    }
    void find(){
        cout<<"Legs:  "<<legs;
    }
};

int main(){
    Animal a;
    Dog d;
    // d.eat();
    // d.sleep();
    d.bark();
    return 0;
}