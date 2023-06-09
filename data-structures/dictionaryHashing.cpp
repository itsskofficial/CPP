#include<iostream>
#include<conio.h>
#include<stdlib.h>
# define max 10
using namespace std;

typedef struct list
{
int data;
struct list *next;
} node;

node *ptr[max], *root[max], *temp[max];

class Dictionary
{
    public:
        int index;
        Dictionary();
        void insert_element(int);
        void search_element(int);
        void delete_element(int);
};

Dictionary::Dictionary()
{
    index=-1;
    for(int i=0;i<max;i++)
        {
        root[i]=NULL;
        ptr[i]=NULL;
        temp[i]=NULL;
        }
}

void Dictionary::insert_element(int key)
{
    index=int(key%max);
    ptr[index]=(node*)malloc(sizeof(node));
    ptr[index]->data=key;

    if (root[index]==NULL)
    {
        root[index]=ptr[index];
        root[index]->next=NULL;
        temp[index]=ptr[index];
    }
    else
    {
        temp[index]=root[index];
        while(temp[index]->next!=NULL)
        temp[index]=temp[index]->next;
        temp[index]->next=ptr[index];
    }
    }

void Dictionary::search_element(int key)
{
    int flag=0;
    index=int(key%max);
    temp[index]=root[index];
    while(temp[index]!=NULL)
    {
    if(temp[index]->data==key)
    {
    cout<<"\nSearch key found";
    flag=1;
    break;
    }
    else temp[index]=temp[index]->next;
    }
    if (flag==0)
    cout<<"\nSearch key not found.......";
}

void Dictionary::delete_element(int key)
{
    index=int(key%max);
    temp[index]=root[index];
    while(temp[index]->data!=key && temp[index]!=NULL)
    {
    ptr[index]=temp[index];
    temp[index]=temp[index]->next;
    }
    ptr[index]->next=temp[index]->next;
    cout<<"\n"<<temp[index]->data<<" has been deleted.";
    temp[index]->data=-1;
    temp[index]=NULL;
    free(temp[index]);
}
int main()
{
    int val,ch,n,num;
    char c;
    Dictionary d;
    do
    {
        cout<<"\nMENU:\n1.Create dictionary";
        cout<<"\n2.Search element\n3.Delete element";
        cout<<"\nEnter your choice:";
        cin>>ch;
        
        switch(ch)
        {
            case 1:
                cout<<"\nEnter the number of elements to be inserted:";
                cin>>n;
                cout<<"\nEnter the elements to be inserted:";
                for(int i=0;i<n;i++)
                {
                    cin>>num;
                    d.insert_element(num);
                }
                break;

            case 2:
                cout<<"\nEnter the element to be searched:";
                cin>>n;
                d.search_element(n);
                break;

            case 3:
                cout<<"\nEnter the element to be deleted:";
                cin>>n;
                d.delete_element(n);
                break;

            default:
                cout<<"\nInvalid choice....";
        }

        cout<<"\nEnter y to continue......";
        cin>>c;
    } while(c=='y');

    getch();
    return 0;
}