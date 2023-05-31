#include<bits/stdc++.h>
using namespace std;

struct node
{
    char label[10];
    int child_count;
    struct node*child[10];
}* root;

class BookTree
{
    public:
        void create();
        void display(node*root);
        BookTree()
        {
            root=NULL;
        }
};

void BookTree::create()
{
    root=new node;
    cout<<"Enter book name:";
    cin>>root->label;
    cout<<"Enter number of chapters:";
    cin>>root->child_count;
    for (int i=0; i<root->child_count; i++)
    {
        root->child[i]=new node;
        cout<<"Enter name of chapter"<<i+1<<":";
        cin>>root->child[i]->label;
        cout<<"Enter number of sections:";
        cin>>root->child[i]->child_count;
        for (int j=0; j<root->child[i]->child_count; j++)
        {
            root->child[i]->child[j]=new node;
            cout<<"Enter name of section:"<<j+1<<":";
            cin>>root->child[i]->child[j]->label;
            cout<<"Enter number of sub-sections:";
            cin>>root->child[i]->child[j]->child_count;
            for (int k=0; k<root->child[i]->child[j]->child_count; k++)
            {
                root->child[i]->child[j]->child[k]=new node;
                cout<<"Enter name of sub-Section:"<<k+1<<":";
                cin>>root->child[i]->child[j]->label;
            }
        }
    }    
};

void BookTree::display(node*root)
{
    if(root!=NULL)
    { 
        cout<<"\nName of the book:"<<root->label;
        for (int i=0; i<root->child_count; i++)
        {
            cout<<"\nThe chapter"<<i+1<<"name:"<<root->child[i]->label;
            for (int j=0; j<root->child[i]->child_count; j++)
            {
                cout<<"\nThe section"<<j+1<<"name:"<<root->child[i]->child[j]->label;
                for (int k=0; k<root->child[i]->child[j]->child_count; k++)
                {
                    cout<<"\nThe sub-sections"<<i+1<<"name:"<<root->child[i]->child[j]->label;
                }
            }

        }
    }
}

int main(){
    int choice;
    BookTree gt;
    while(1){
        cout<<"Welcome To Book Hierarchy!";
        cout<<"Choose from the following:";
        cout<<"\n1.Create\n2.Display\n3.Exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            gt.create();
            break;

            case 2:
            gt.display(root);
            break;

            case 3:
            exit(1);

            default:
            cout<<"Wrong choice";

        }

    }

}





























