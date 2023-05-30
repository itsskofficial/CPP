#include<iostream>
#include<math.h>
using namespace std;

struct Bstnode
{
 int data;
 Bstnode *left = NULL;
 Bstnode *right = NULL;
 
};

class Btree
{
 
  int n;
  int x;
  int flag;
  
public:
  Bstnode * root;
 Btree()
 {
  root = NULL;
 }
 
 Bstnode *GetNewNode(int x)
 {
  Bstnode * ptr = new Bstnode();
  ptr->data = x;
  ptr->left = NULL;
  ptr->right = NULL;
  return ptr;
 }
 
 Bstnode *insert( Bstnode *root , int x)
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
 
 int search(Bstnode *root ,int x)
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
 
 
 void minvalue(Bstnode *root)
 {
  while(root->left != NULL)
  {
   root = root->left;
  }
  cout<<"MINIMUM VALUE = "<<root->data<<endl;
 }
   
 void mirror(Bstnode *root)
 {
  if(root == NULL)
  {
   return;
  }
  else
  {
   Bstnode *ptr;
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
 
 void inorder(Bstnode *root)
 {
  if(root != NULL)
  {
   inorder(root->left);
   cout<<root->data<<"  ";
   inorder(root->right);
  }
 } 
 
 void postorder(Bstnode *temp)
 {
  if(temp != NULL)
  {
   postorder(temp->left);
   postorder(temp->right);
   cout<<temp->data<<" ";
  }
 }
 
 void preorder(Bstnode *temp)
 {
  if(temp != NULL)
  {
   cout<<temp->data<<" ";
   preorder(temp->left);
   preorder(temp->right);
  }
 } 
 
 int depth(Bstnode *temp)
 {
  if(temp == NULL) 
   return 0;
  return (max((depth(temp->left)),(depth(temp->right))) +1);  
 }
};

int main()
{
 Btree obj;
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