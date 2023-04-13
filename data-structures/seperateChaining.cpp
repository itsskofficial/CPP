#include<iostream>
#define MAX 10
using namespace std;

class node {
    public:
        int data;
        node *next;
};

class hashtable{
    public:
        node *table[MAX];
        void initialise(){
            int n;
            for (n=0;n<MAX;n++){
                table[n]=NULL;
            }
        }
        void insert(int x){
            node *p,*q;
            p=new node;
            p->data=x;
            int loc;
            loc=x%MAX;
            if (table[loc]==NULL){
                table[loc]=p;
            }
            else{
                q=table[loc];
                while (q->next!=NULL){
                    q=q->next;
                }
                q->next=p;
            }
        }

        node* find(int x){
            node *p,*q;
            int loc;
            loc=x%MAX;
            p=table[loc];
            if (p->data==x){
                return p;
            }
            else{
                while (p->next!=NULL && p->data!=x){
                    p=p->next;
                }
                if (p->next==NULL && p->data!=x){
                    cout<<"Node not found";
                }
                else{
                    return p;
                }
            }
        }
};

int main(){
    hashtable h;
    node *p;
    int choice=0,x;
    cout<<"Welcome to Seperate Chaining";
    do{
        cout<<"\n"<<"Here are your options: "<<"\n";
        cout<<"1.Initialise table\n2.Insert data\n3.Find data\n4.Exit";
        cout<<"\n"<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                h.initialise();
            case 2:
                cout<<"\n"<<"Enter data to insert: ";
                cin>>x;
                h.insert(x);
            case 3:
                cout<<"\n"<<"Enter data to find: ";
                cin>>x;
                p=h.find(x);
                if (p){
                    cout<<"Element found";
                }
            case 4:
                exit(1);
        }
    }while (choice!=4);

    return 0;
}
