#include<iostream>
using namespace std;
#define MAX 10

class hashtable{
    public:
        int table[MAX];
        int flag[MAX] = {0};

        int insert(int x){
            int i;
            int loc = x % MAX;

            for (i = 0; i < MAX;i++){
                if (flag[loc]==0){
                    table[loc] = x;
                    flag[loc] = 1;
                    return loc;
                }
                    loc = (loc + 1) % MAX;
            }
            return -1;
        }

        int find(int x){
            int i;
            int loc = x % MAX;

            for (i = 0; i < MAX;i++){
                if (flag[loc]==1 && table[loc]==x){
                    return loc;
                }
                loc = (loc + 1) % MAX;
            }
            return -1;
        }

        void display(){
            int i;
            for (i = 0; i < MAX;i++){
                cout << i << "\n";
            }
        }
};

int main(){
    int choice=0,x,loc;
    hashtable h;
    cout << "Welcome to Linear Probing" << "\n";
    do {
            cout << "Here are your options: ";
            cout<<"1.Insert data\n2.Find data\n3.Display\n4.Exit";
            cout<<"\n"<<"Enter your choice: ";
            cin>>choice;
            switch(choice){
                case 1:
                    cout<<"\n"<<"Enter data to insert: ";
                    cin>>x;
                    loc=h.insert(x);
                    if (loc==-1){
                        cout << "Hashtable is full, can't insert element";
                    }
                    else{
                        cout << "Element inserted at location " << loc;
                    }
                case 2:
                    cout<<"\n"<<"Enter data to find: ";
                    cin>>x;
                    loc=h.find(x);
                    if (loc==-1){
                        cout<<"Element not found";
                    }
                    else{
                        cout << "Element found at location " << loc;
                    }
                case 3:
                    h.display();
                case 4:
                    exit(1);
                }
        }while(choice!=4);
    return 0;
}