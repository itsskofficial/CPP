//including the libraries and using standard namespace
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Item
{
    //declaring properties and overload function in public access
    public:
        char name[10];
        int quantity;
        int cost;
        int code;

        //overloading used for less than operator
        bool operator<(const Item& i2)
        {
        if(cost<i2.cost)
            return 1;
        else
            return 0;
        }
};

vector<Item> o1; //vector object created with class item

//function to compare two items from sort method
bool compare(const Item &i1, const Item &i2)
{
    return i1.cost < i2.cost; //operator overloaded
}

//function to insert an item into vector object
void insert()
{
    Item i1;
    cout<<"\nEnter Item Name:";
    cin>>i1.name;
    cout<<"\nEnter Item Quantity:";
    cin>>i1.quantity;
    cout<<"\nEnter Item Cost:";
    cin>>i1.cost;
    cout<<"\nEnter Item Code:";
    cin>>i1.code;
    o1.push_back(i1);
}

//function to display every object of vector
void display()
{
    for_each(o1.begin(),o1.end(),print);
}

//applied on every object called by for each method in display function
void print(Item &i1)
{
    cout<<"\n";
    cout<<"\nItem Name:"<<i1.name;
    cout<<"\nItem Quantity:"<<i1.quantity;
    cout<<"\nItem Cost:"<<i1.cost;
    cout<<"\nItem Code:"<<i1.code;
}

//function to search an object with item code
void search()
{
    vector<Item>::iterator p;
    Item i1;
    cout<<"\nEnter Item Code to search:";
    cin>>i1.code;
    p=find(o1.begin(),o1.end(),i1);
    if(p==o1.end())
    {
        cout<<"\nNot found.";
    }

    else
    {
        cout<<"\nFound."<<endl;
        cout<<"Item Name : "<<p ->name<<endl;
        cout<<"Item Quantity : "<<p ->quantity<<endl;
        cout<<"Item Cost : "<<p ->cost<<endl;
        cout<<"Item Code: "<<p ->code<<endl;
    }
}

//function to delete an object from vector
void dlt()
{
    vector<Item>::iterator p;
    Item i1;
    cout<<"\nEnter Item Code to delete:";
    cin>>i1.code;
    p=find(o1.begin(),o1.end(),i1);

    if(p==o1.end())
    {
        cout<<"\nNot found.";
    }

    else
    {
        o1.erase(p);
        cout<<"\nDeleted.";
    }
}

//driver code
int main()
{
    int ch;
    do
    {
        cout<<"\n*** Menu ***";
        cout<<"\n1.Insert";
        cout<<"\n2.Display";
        cout<<"\n3.Search";
        cout<<"\n4.Sort";
        cout<<"\n5.Delete";
        cout<<"\n6.Exit";

        cout<<"\nEnter your choice:";
        cin>>ch;

        switch(ch)
        {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                sort(o1.begin(),o1.end(),compare); //this method takes two objects at a time out of the vector and applies the given method on them
                cout<<"\n\n Sorted on Cost";
                display();
                break;

            case 5:
                dlt();
                break;

            case 6:
                exit(0);
        }
    }
    while(ch!=7);
    
    return 0;
}
