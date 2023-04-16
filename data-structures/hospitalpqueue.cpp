#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define MAX 30
struct node{
	int id,age;
	char patient_name[MAX];
	int priority;
	struct node *next;
};

node *front=NULL;
void vline(char ch)
{
	cout<<"\n";
	for (int i=80;i>0;i--)
		cout<<ch;
}

void insert(int id,int age,char patient_name[],int priority)
{
    node *temp,*ptr;
    temp= new node;
    temp->id=id;
    temp->age=age;
    strcpy(temp->patient_name,patient_name);
    temp->priority=priority;
    if (front == NULL || priority < front->priority) 
    {
        temp->next = front;
        front = temp;
    } 
    else
    {
        ptr = front;

        while (ptr->next != NULL && ptr->next->priority <= priority)
            ptr=ptr->next;
        
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void remove() 
{
    node *temp;
    if(front == NULL)
        cout<<"\nThere are no patients in the queue\n";
    else 
    {
        temp = front;
        cout<<"\npatient with id: "<<temp->id<<" and name: "<<temp->patient_name<<"("<<temp->age<<") has been left."<<endl;
        front = front->next;
        free(temp);
    }
}

void display() 
{
    node *ptr;
    ptr = front;
    if (front == NULL)
        cout<<"\nThere are no patients\n";
    else 
    {
        cout<<"\nPatients who are in queue are:\n";

        while(ptr != NULL) 
        {
            cout<<ptr->id<<"-"<<ptr->patient_name<<"("<<ptr->age<<")\n";
            ptr = ptr->next;
        }

        cout<<endl;
    }
}

int main() 
{
    int ch, id, priority,age,a,sub,i=0,j=0,p,sub2,dataid[40],dataage[40],dataprio[40];
    char name[40];
    string dataname[40];
    i=0;
    do 
    {
        vline('*');
        cout<<"\n1.Add patient\n";
        cout<<"2.Remove patient\n";
        cout<<"3.Display the queue\n";
        cout<<"4.List of all the patients admitted\n ";
        cout<<"5.Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        vline('*');
        switch(ch) 
        {
            case 1:
            {
                cout<<"\nEnter the patient id : ";
                cin>>id;
                dataid[i]=id;
                cout<<"Enter the patient name: ";
                cin>>name;
                dataname[i]=name;
                cout<<"Enter the patient age: ";
                cin>>age;
                dataage[i]=age;
                cout<<"\n1-Accident\n2-Other issues\n3-General Checkup\n4-visiting\n";
                cout<<"\nEnter the type of case : ";
                cin>>a;

                switch(a)
                {
                    case 1:
                    {
                        cout<<"\nChoose 1 or 2\n 1-Major Accidents\n 2-Minor accidents\n";
                        cin>>sub;

                        if(sub==1)
                        {
                            priority=1;
                            dataprio[i]=1;
                            cout<<"your priority is 1";
                        }

                        else
                        {
                            priority=2;
                            dataprio[i]=2;
                            cout<<"your priority is 2";
                        }
                        
                        break;
                    }

                    case 2:
                    {
                        cout<<"\nChoose 1 or 2\n 1-Poisioning\n 2-Allergies\n";
                        cin>>sub2;
                        if(sub2==1)
                        {
                            priority=3;
                            dataprio[i]=3;
                            cout<<"your priority is 3";
                        }

                        else
                        {
                            priority=4;
                            dataprio[i]=4;
                            cout<<"your priority is 4";
                        }
                    } 
                    break;
                    case 3:
                    {
                        priority=5;
                        dataprio[i]=5;
                        cout<<"your priority is 5";
                    }

                    case 4:
                    {
                        priority=6;
                        dataprio[i]=6;
                        cout<<"your priority is 6";
                    }

                    default:
                        cout<<"\nWrong choice";
                }

                insert(id,age,name,priority);
                i++;
                break;
            }

            case 2:
            {
                remove();
                break;
            }

            case 3:
            {
                display();
                break;
            }

            case 4:
            {
                for(j=0;j<=i;j++)
                {
                    cout<<"\n"<<dataid[j]<<"-"<<dataname[j]<<"("<<dataage[j]<<") - ";
                    p=dataprio[j];
                    switch(p){
                    case 1:
                    cout<<"Major Accidents";
                    break;
                    case 2:
                    cout<<"Minor Accidents";
                    break;
                    case 3:
                    cout<<"Poisioning";
                    break;
                    case 4:
                    cout<<"Allergies";
                    break;
                    case 5:
                    cout<<"General Check up";
                    break;
                    case 6:
                    cout<<"Visiting";
                    break;
                    }
                }

                break;
            }
            case 5:
            {
                cout<<"\nExit"<<endl;
                break;
                default :
                cout<<"\nWrong choice\n";
            }
        }
    } while(ch != 5);
    return 0;
}