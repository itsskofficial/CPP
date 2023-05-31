#include<bits/stdc++.h>
using namespace std;

struct node
{
    char label[10];
    int ch_count;
    struct node*child[10];
}* root;

class BookTree
{
    public:
        void create_tree();
        void display(node*root);
        BookTree()
        {
            root=NULL;
        }
};

void BookTree::create_tree()
{
    int i,j,k;
    root=new node;
    cout<<"Enter book name:";
    cin>>root->label;
    cout<<"Enter number of chapters:";
    cin>>root->ch_count;
    for (int i=0; i<root->ch_count; i++)
    {
        root->child[i]=new node;
        cout<<"Enter name of chapter"<<i+1<<":";
        cin>>root->child[i]->label;
        cout<<"Enter number of sections:";
        cin>>root->child[i]->ch_count;
        for (int j=0; j<root->child[i]->ch_count; j++)
        {
            root->child[i]->child[j]=new node;
            cout<<"Enter name of Section:"<<j+1<<":";
            cin>>root->child[i]->child[j]->label;
            cout<<"Enter number of sub-sections:";
            cin>>root->child[i]->child[j]->ch_count;
            for (int k=0; k<root->child[i]->child[j]->ch_count; k++)
            {
                root->child[i]->child[j]->child[k]=new node;
                cout<<"Enter name of Sub-Section:"<<k+1<<":";
                cin>>root->child[i]->child[j]->label;
            }
        }
    }    
};

void BookTree::display(node*root)
{
    int i,j,k;
    if(root!=NULL)
    {
        
        cout<<"\nName of the book:"<<root->label;
        for (int i=0; i<root->ch_count; i++)
        {
            cout<<"\nThe chapter"<<i+1<<"name:"<<root->child[i]->label;
            for (int j=0; j<root->child[i]->ch_count; j++)
            {
                cout<<"\nThe section"<<j+1<<"name:"<<root->child[i]->child[j]->label;
            
                
                for (int k=0; k<root->child[i]->child[j]->ch_count; k++)
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
            gt.create_tree();
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





























