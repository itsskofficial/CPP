#include <iostream>
#include <string.h>
using namespace std;
#define max 30

class node
{ 

	public:
		char data;
		node *left, *right;
		node()
		{
			left=right=NULL;
		}

};

class expressiontree
{
	
public:
	node *root;

	expressiontree()
	{
		root=NULL;
	}

	void create(string str);
	void nonrecPostorder(node *temp);
    void deleteTree(node *temp);
    int priority(char ch);
	
};

class stack
{
	int top;
	node *stk[max];

	public:
		stack()
		{
			top=-1;
		}
		
		int empty()
		{
			if(top==-1)
				return 1;
			else 
				return 0;
		}

		void push(node *temp)
		{
			stk[++top]= temp;
		}

		node* pop()
		{
			return(stk[top--]);
		}
		
		node *top()
		{
			return(stk[top]);
		}

};

int expressiontree :: priority(char ch)
{
	switch(ch)
	{
		case '+': 
		case '-':
			return 0;
		case '*':
		case '/':	
			return 1;
		case '^':	
			return 2;			
		default:
			return -1;
	}
}

void expressiontree :: create(string str)
{
	stack operand_st, operator_st;
	int i=0;
	char ch;
	while(str[i]!= '\0')
	{
		ch = str[i];
		cout << str[i];

		node *temp = new node();
		temp->data = ch;
		
		if(isalpha(ch))
		{
			operand_st.push(temp);
		}
		else
		{
			if(operator_st.empty())
				operator_st.push(temp);
			else
				if(priority(ch)>priority(operator_st.top()->data))
					operator_st.push(temp);
				else
				{
					while(!operator_st.empty() && priority(ch)<= operator_st.top()->data)
					{
						node *operat = operator_st.pop();
						operat->right= operand_st.pop();
						operat->left = operand_st.pop();
						
						operand_st.push(operat);
					}
					operator_st.push(temp);
				}	
		}
		
		i++;
	}
	
	while(!operator_st.empty())
	{
		node *operat = operator_st.pop();
		operat->right= operand_st.pop();
		operat->left = operand_st.pop();
		
		operand_st.push(operat);
	}
	
	root= operand_st.pop();
	
}

void expressiontree :: nonrecPostorder(node *temp)
{
	if(root==NULL)
		cout<<"\n Empty";
	else
	{
		stack s1, s2;
		s1.push(temp);
		
		while(!s1.empty())
		{
			node *temp= s1.pop();
			s2.push(temp);
			if(temp->left)
				s1.push(temp->left);
			if(temp->right)
				s1.push(temp->right);
		}
		
		while(!s2.empty())
		{
			node *temp= s2.pop();
			cout<<temp->data<<" ";
		}
	}
}

void expressiontree :: deleteTree(node* temp)
{
    if (temp == NULL) 
        return;
 
    /* first delete both subtrees */
    deleteTree(temp->left);
    deleteTree(temp->right);
     
    /* then delete the node */
    cout << "\n Deleting node: " << temp->data;
    delete temp;
}

int main()
{
	expressiontree e;
	string str;
	int ch;
	
	do
	{
		cout<<"\n Enter Choice: ";
		cout<<"\n\t1.Create expression tree \n\t2.Non Recursive Postorder Traversal \n\t3.Delete tree\n\t4.Exit";
		cout<<"\n Choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
            { 
                cout<<"Enter Expression : ";
                cin >> str;
                e.create(str);
				break;
            }

			case 2:
            {
                cout<<"\n Non Recursive Postorder Traversal: "; 
				e.nonrecPostorder(e.root);
				break;
            }

			case 3:
            {
                cout << "Deleting the tree: ";
                e.deleteTree(e.root);
                break;
		    }

			default:
			{
				cout<< "Enter valid option";
				exit(1);
			}
        }
	} while(ch != 4);
	
	return 0;
}