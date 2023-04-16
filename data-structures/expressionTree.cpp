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
	void nonrec_postorder(node *temp);
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

	node *pop()
	{
		return(stk[top--]);
	}
	
	node *Top()
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
				if(priority(ch)>priority(operator_st.Top()->data))
					operator_st.push(temp);
				else
				{
					while(!operator_st.empty() && priority(ch)<= operator_st.Top()->data)
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

void expressiontree :: nonrec_postorder(node *temp)
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

void expressionTree::

int main()
{
	expressiontree e;
	string str;
	int ch;
	
	do
	{
		cout<<"\n Enter Choice: ";
		cout<<"\n\t1.Create expression tree \n\t2.Non recursive Postorder Traversal \n\t3.Exit";
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
				e.nonrec_postorder(e.root);
				break;
            }

			case 3: break;
		}
	} while(ch != 3);
	
	return 0;
}