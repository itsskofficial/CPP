#include<iostream>
#include<string.h>
using namespace std;
class BTNode
{
 public:
 BTNode *left, *right;
 char data[10];
};
class Book
{
    public: BTNode *root, *temp;
    char d[20];
    Book()
    {
        temp = root = NULL;
    }
    void create()
    {
        char ans='y';

        do
        {
            temp = new BTNode();
            cout<<"\nEnter The Element:";
            cin>>temp->data;
            temp->left=NULL;
            temp->right=NULL;

            if(root == NULL)
            {
            root = temp;
            }
            else
            {
            insert(root, temp);
            }

            cout<<"\nDo You Want to Enter More Elements?(y/n)";
            cin>>ans;
        } while(ans == 'y'|| ans == 'Y');
    }

    void insert(BTNode *root, BTNode *temp)
    {
        char ch;
        cout<<"\nWhere to insert left/right?"<<root->data<<":";
        cin>>ch;

        if(ch == 'r' || ch == 'R')
        {
            if(root->right == NULL)
            {
                root->right = temp;
            }
            else
                insert(root->right, temp);
        }
        else
        {
            if(root->left == NULL)
            {
                root->left = temp;
            }
            else
                insert(root->left, temp);
        }
    }

        void rec_inorder(BTNode *root)
        {
            if(root!=NULL)
            {
                rec_inorder(root->left);
                cout<<root->data;
                rec_inorder(root->right);
            }
        }

        void printLevelOrder(BTNode *root)
        {
            int h = height(root);
            int i;
            for(i=1;i<=h;i++)
            {
                cout<<"\n";
                printLevel(root,i);
            }
        }

        void printLevel(BTNode *root, int level)
        {
        if(root == NULL)
        return;
        if(level == 1 )
        //
        cout<<" "<<root->data;
        else if (level>1)
        {
        printLevel(root->left,level-1);
        printLevel(root->right,level-1);
        }
        }
        int height(BTNode *node)
        {
        if(node == NULL)
        return 0;
        else
        {
            int lheight = height(node->left);
            int rheight = height(node->right);
            if(lheight>rheight)
            return (lheight+1);
            else
            return (rheight+1);
        }
        }
};
int main()
 {
 int choice;
 Book b1;
 do
 {
 cout<"\n\tMain Menu:";
 cout<<"\n1.Create";
 cout<<"\n2.Display";
 cout<<"\n3.Exit";
 cout<<"\nEnter Your Choice:";
 cin>>choice;
 switch(choice)
 {
 case 1: b1.create();break;
 case 2: if(b1.root==NULL)
 cout<<"\nTree Not Created";
 else
 b1.printLevelOrder(b1.root);
 break;
 }
 }while(choice <=2);
 return 0; }