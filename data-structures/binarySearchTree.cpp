#include<iostream>
#include<math.h>
using namespace std;

struct node
{
 int data;
 node *left = NULL;
 node *right = NULL;
};

class BSTree
{
 
  int n;
  int x;
  int flag;
  
public:
  node * root;
  BSTree()
  {
    root = NULL;
  }
 
 node *GetNewNode(int x)
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
   root = GetNewNode(x);
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
  cout<<"ENTER NUMBER OF ELEMENTS IN THE BST : ";
  cin>>n;
  for(int i = 0 ; i < n ; i++)
  {
   cout<<"NUMBER = ";
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
    cout<<":-- RECORD FOUND --:"<<endl;
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
  else
  {
    return 0;
  }
  return 2;
 }
 
 
 void minvalue(node *root)
 {
  while(root->left != NULL)
  {
   root = root->left;
  }
  cout<<"MINIMUM VALUE = "<<root->data<<endl;
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
  cout<<endl<<"--- INORDER TRAVERSAL ---"<<endl;
  inorder(root);
  cout<<endl;
  cout<<endl<<"--- POSTORDER TRAVERSAL ---"<<endl;
  postorder(root);
  cout<<endl;
  cout<<endl<<"--- PREORDER TRAVERSAL ---"<<endl;
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
 
 void postorder(node *temp)
 {
  if(temp != NULL)
  {
   postorder(temp->left);
   postorder(temp->right);
   cout<<temp->data<<" ";
  }
 }
 
 void preorder(node *temp)
 {
  if(temp != NULL)
  {
   cout<<temp->data<<" ";
   preorder(temp->left);
   preorder(temp->right);
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
 BSTree obj;
 obj.input();
 obj.display();
 int a = 0;
 a = obj.search(obj.root,10);
 if( a == 0)
 {
  cout<<"ELEMENT NOT FOUND"<<endl;
 }
 else
  cout<<"ELEMENT FOUND"<<endl;                                                                                                       
 cout<<a<<endl;
 obj.minvalue(obj.root);
 obj.mirror(obj.root);
 obj.inorder(obj.root);
 //int d ;
 cout<<endl<<obj.depth(obj.root);
 //cout<<endl<<d<<endl;
 return 0;
}  