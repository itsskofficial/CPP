#include <iostream>
using namespace std;
class node
{
	public:
	string word;
	string meaning;
	node* left=NULL;
	node* right=NULL;

	node(string x, string y)
	{
		word = x;
		meaning = y;
		left = NULL;
		right = NULL;
	}

	friend class Dictionary;
};

class Dictionary
{

public:
	node *root, *parent;

	Dictionary()
	{
		root = NULL;
		parent = NULL;
	}

	void insertWord(node*, string, string);
	void display_ascending(node *);
	void display_descending(node *);
	void comparisons(node*, string);
	void updateWord(node*, string);
	void deleteWord(node*, string);
	node* min_node(node *);
};

void Dictionary::insertWord(node* root, string key, string keyMeaning)
{
	if(key < root->word)
	{
		if(root->left != NULL)
			insertWord(root->left, key, keyMeaning);
		else
			root->left = new node(key, keyMeaning);
	}
	else if(key > root->word)
	{
		if(root->right != NULL)
			insertWord(root->right, key, keyMeaning);
		else
			root->right = new node(key, keyMeaning);
	}
}

void Dictionary::display_ascending(node *root)		//inorder
{
	if(root->left!=NULL)
		display_ascending(root->left);
	cout<<"\n" << root->word<<" \t" << root->meaning;
	if(root->right!=NULL)
		display_ascending(root->right);
}

void Dictionary::display_descending(node *root)
{
	if(root->right!=NULL)
			display_descending(root->right);
	cout<<"\n" << root->word<<" \t" << root->meaning;
	if(root->left!=NULL)
		display_descending(root->left);
}

void Dictionary::comparisons(node* root, string key)
{
	static int count = 0;
	while(root!=NULL)
	{
		if(key < root->word)
		{
			count++;
			root = root->left;
		}

		else if(key > root->word)
		{
			count++;
			root = root->right;
		}

		else if(key == p->word)
		{
			count++;
			cout<<"Number of comparisons to find the word: " << count;
			return ;
		}
	}
	cout<<"\nWord not found!";
}

node* Dictionary::min_node(node *p)
{
	while(root->left != NULL)
	{
		parent = root;
		root = root->left;
	}
	return root;
}

void Dictionary::deleteWord(node* root, string key)
{
	node *s;
	while(root!=NULL)							//searching for word
	{
		if(key < root->word)
		{
			parent = root;
			root = root->left;
		}

		else if(key > root->word)
		{
			parent=p;
			p = root->right;
		}

		else if(key == root->word)				//word found
		{
			if(root->left==NULL && root->right==NULL)	//no child
			{
				if(parent->left==root)
				{
					delete root;
					parent->left=NULL;
				}

				if(parent->right==root)
				{
					delete root;
					parent->right=NULL;
				}

			}

			if(root->right!=NULL && root->left==NULL)	//right child only
			{
				if(parent->right == root)
				{
					parent->right = root->right;
					delete root;
				}

				else if(parent->left == root)
				{
					parent->left = root->right;
					delete root;
				}

			}

			else if(root->left!=NULL && root->right==NULL)	//left child only
			{
				if(parent->right == root)
				{
					parent->right = root->left;
					delete root;
				}

				else if(parent->left == root)
				{
					parent->left=root->left;
					delete root;
				}

			}

			else if(root->left!=NULL && root->right!=NULL)
			{
				s = min_node(root->right);
				root->word = s->word;
				root->meaning = s->meaning;
				deleteWord(s, s->word);

			}
		}
	}
	cout<<"\nWord NOT found!";
}

void Dictionary::updateWord(node* root, string key)
{
	while(root!=NULL)
	{
		if(key < root->word)
			root = root->left;

		else if(key > root->word)
			root = root->right;

		else if(key == root->word)
		{
			cout<<"\nEnter its new meaning: ";
			cin>>root->meaning;
			return;
		}
	}
	cout<<"\nWord not found!";
}


int main()
{
	int choice, n;
	string newWord, searchWord, newMeaning;
	Dictionary d1;
    do
    {
        cout<<"\n\nDICTIONARY: ";
        cout<<"\n\n1. Insert new words";
        cout<<"\n2. Display the dictionary in ascending order";
        cout<<"\n3. Display the dictionary in descending order";
        cout<<"\n4. Search and update a word";
        cout<<"\n5. Delete a word";
        cout<<"\n6. Comparisons";
        cout << "\n7. Exit";
        cout<<"\n\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"\nEnter the number of words to insert: ";
                cin >> n;
                for(int i=0 ; i<n ; i++)
                {
                    cout<<"\nEnter the word to be inserted: ";
                    cin >> newWord;
                    cout<<"\nEnter its meaning: ";
                    cin >> newMeaning;
                    if(d1.root == NULL)
                        d1. root = new node(newWord, newMeaning);
                    else
                        d1.insertWord(d1.root, newWord, newMeaning);
                }
                break;
            }

            case 2:
            {
                d1.display_ascending(d1.root);
                break;
            }

            case 3:
            {
                d1.display_descending(d1.root);
                break;
            }

            case 4:
            {
                cout<<"\nEnter the word to search: ";
                cin >> searchWord;
                d1.updateWord(d1.root, searchWord);
                break;
            }

            case 5:
            {
                cout<<"\nEnter the word to delete: ";
                cin>>searchWord;
                d1.deleteWord(d1.root, searchWord);
                break;
            }

            case 6:
            {
                cout<<"\nEnter the word to find comparisons: ";
                cin >> searchWord;
                d1.comparisons(d1.root, searchWord);
            }
            
            default:
                cout<<"\nExit!";
        }
    } while (choice != 7);

    return 0;
}