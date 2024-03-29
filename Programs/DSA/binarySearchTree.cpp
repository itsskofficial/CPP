#include <bits/stdc++.h>
using namespace std;

struct node
{
 int data;
 node *left = NULL;
 node *right = NULL;
};

class BST
{
 
  int n;
  int x;
  
  public:

    node * root;
    BST()
    {
      root = NULL;
    }
  
    node *createNode(int x)
    {
      node * ptr = new node();
      ptr->data = x;
      ptr->left = NULL;
      ptr->right = NULL;
      return ptr;
    }
  
    node *insert( node *root , int x)
    {
        if( root == NULL )
        {
          root = createNode(x);
        }
        else if( root->data > x)
        {
          root->left = insert(root->left , x);
        }
        else
        {
          root->right = insert( root->right , x);
        }

        return root;
    }
    
    void input()
    {
        cout<<"Enter number of elements in the BST : ";
        cin>>n;

        for(int i = 0 ; i < n ; i++)
        {
          cout<<"Data = ";
          cin>>x;
          root = insert(root , x);
        }
    }
    
    int search(node *root ,int x)
    {
        if( root != NULL)
        {
          if(root->data == x)
          {
            return 1;
          }
          else if(x < root->data)
          {
            this->search(root->left, x);
          }
          else if(x > root->data)
          {
            this->search(root->right , x);
          }
        }

        return 0;
    }
    
    
    void minvalue(node *root)
    {
        while(root->left != NULL)
        {
        root = root->left;
        }
        cout<<"Minimum value = " <<root->data<<endl;
    }
      
    void mirror(node *root)
    {
        if(root == NULL)
        {
          return;
        }
        else
        {
          node *ptr;
          mirror(root->left);
          mirror(root->right);
          ptr = root->left;
          root->left = root->right;
          root->right = ptr; 
        }
    }
    
    void display()
    {
        cout<<endl<<"--- Inorder Traversal ---"<<endl;
        inorder(root);
        cout<<endl;
        cout<<endl<<"--- Postorder Traversal ---"<<endl;
        postorder(root);
        cout<<endl;
        cout<<endl<<"--- Preorder Traversal ---"<<endl;
        preorder(root);
        cout<<endl;
    }
    
    void inorder(node *root)
    {
        if(root != NULL)
        {
        inorder(root->left);
        cout<<root->data<<"  ";
        inorder(root->right);
        }
    } 
    
    void postorder(node *root)
    {
        if(root != NULL)
        {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
        }
    }
    
    void preorder(node *root)
    {
        if(root != NULL)
        {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
        }
    } 
    
    int depth(node *root)
    {
        if(root == NULL) 
          return 0;

        return (max((depth(root->left)),(depth(root->right))) +1);  
    }
};

int main()
{
  BST t;
  t.input();
  t.display();
  int a = 0;
  a = t.search(t.root,10);
  if( a == 0)
  {
    cout<<"Element not found"<<endl;
  }
  else
    cout<<"Element found"<<endl;    

  t.minvalue(t.root);
  t.mirror(t.root);
  t.inorder(t.root);
  cout<<endl<<t.depth(t.root);
  return 0;
}  