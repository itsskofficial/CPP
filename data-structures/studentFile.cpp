#include <bits/stdc++.h>
using namespace std;

struct student
{
    int rollno;
    char name[20];
    float marks;
    int status; // 0 when present 1 when deleted
};
class sequential
{ 
    char master[30];
    fstream fp;
    public:
        sequential(char *a)
        {
            strcpy(master,a);
        }
        void read();  
        void insert_student(student rec);
        int delete_student(int rollno);
        int search_student(int rollno);
        void pack();
        void update();
        void display(int recno) 
        { 
            student rec;
            fp.open(master,ios::binary | ios::in);
            fp.seekg(recno*sizeof(student),ios::beg);
            fp.read((char*) &rec,sizeof(student));
            cout<<"\n"<<rec.rollno<<" "<<rec.name<<" "<<setprecision(2)<<rec.marks;
            fp.close();
        }
};

void sequential::read()
{ 
    student current; int i=1,n;
    cout<<"\n*********Data File*********\n";
    fp.open(master,ios::binary | ios::in);
    fp.seekg(0,ios::end);
    n=fp.tellg()/sizeof(student);
    fp.seekg(0,ios::beg);
    for(i=1;i<=n;i++)
    { 
        fp.read((char*)&current,sizeof(student));
        if(current.status==0)
            cout<<"\n"<<i<<") "<<current.rollno<<" "<<current.name<<" "<<setprecision(2)<<current.marks;
        else
            cout<<"\n"<<i<<") "<<" ****** deleted *********";
    }

    fp.close();
}

void sequential::insert_student(student rec)
{ 
    student current;
    int n,i,k;
    fp.open(master,ios::in | ios::out);
    rec.status=0;
    fp.seekg(0,ios::end);
    n=fp.tellg()/sizeof(student);
    fp.seekg(0,)

    if(n==0)
    {
        fp.write((char*)&rec,sizeof(student)); 
        fp.close();
        return;
    }

    i=n-1;
    while(i>=0)
    { 
        fp.seekg(i*sizeof(student),ios::beg);
        fp.read((char*)&current,sizeof(student));

        if(current.rollno>rec.rollno)
        { 
            fp.seekp((i+1)*sizeof(student),ios::beg);
            fp.write((char*)&current,sizeof(student));
        }
        else
            break;
        i--;
    }
    /*insert the record at (i+1)th position */
    i++;
    fp.seekp(i*sizeof(student),ios::beg);
    fp.write((char*)&rec,sizeof(student));
    fp.close();
}

int sequential::delete_student(int rollno)
{ 
    student current;
    int i,n; 
    fp.open(master,ios::in | ios::out);
    fp.seekg(0,ios::end);
    n=fp.tellg()/sizeof(student);
    fp.seekg(0,ios::beg);

    for(i=0;i<n;i++)
    { 
        fp.read((char*)&current,sizeof(student));
        if(current.status==0)
        {
            if(current.rollno>rollno)
            {
                cout<<"\nRecord does not exist …";
                fp.close();
                return(0);
            }
            if(current.rollno==rollno)
            {
                current.status=1;
                fp.seekp(i*sizeof(student),ios::beg);
                fp.write((char*)&current,sizeof(student));
                fp.close();
                return(1);
            }
        }
    }

    return(0);
}

int sequential::search_student(int rollno)
{
    student current;
    int i,n;
    fp.open(master,ios::in | ios::out);
    fp.seekg(0,ios::end);
    n=fp.tellg()/sizeof(student);
    fp.seekg(0,ios::beg);

    for(i=0;i<n;i++)
    { 
        fp.read((char*)&current,sizeof(student));
        if(current.status==0)
        {
            if(current.rollno>rollno)
            {
                fp.close();
                return(-1);
            }
            if(current.rollno==rollno)
            { 
                fp.close();
                return(i);
            }
        }
    }

    return(-1);
}

void sequential::pack()
{ 
    fstream temp;
    student current;int i,n;
    fp.open(master,ios::binary | ios::in);
    temp.open("temp.txt",ios::out | ios::trunc | ios::binary);
    fp.seekg(0,ios::end);
    n=fp.tellg()/sizeof(student);
    fp.seekg(0,ios::beg);

    for(i=0;i<n;i++)
    { 
        fp.read((char*)&current,sizeof(student));
        if(current.status==0)
            temp.write((char*)&current,sizeof(student));
    }

    fp.close();
    temp.close();
    temp.open("temp.txt",ios::binary | ios::in);
    fp.open(master,ios::binary | ios::out | ios::trunc);
    temp.seekg(0,ios::end);
    n=temp.tellg()/sizeof(student);
    temp.seekg(0,ios::beg);

    for(i=0;i<n;i++)
    {
        temp.read((char*)&current,sizeof(student));
        fp.write((char*)&current,sizeof(student));
    }

    fp.close();
    temp.close();
}

void sequential::update()
{ 
    int rollno;
    student rec;
    cout<<"\n Enter the rollno of the record to be updated : ";
    cin>>rollno;
    cout<<"\nEnter a new record(roll no. name marks : ";
    cin>>rec.rollno>>rec.name>>rec.marks;

    if(delete_student(rollno))
        insert_student(rec);
    else
        cout<<"\n Record not found :";
}

int main()
{ 
    sequential object((char*)"master.txt");
    int rollno,ch,recno;
    student rec;

    do
    { 
        cout<<"\n\n1)Insert\n2)Read\n3)Delete\n4)Update";
        cout<<"\n5)Search\n6)Pack\n7)Quit";
        cout<<"\nEnter Your Choice:";
        cin>>ch;

        switch(ch)
        { 
             case 1:
            { 
                cout<<"\nEnter a record to be inserted(roll no,name,marks) : ";
                cin>>rec.rollno>>rec.name>>rec.marks;
                object.insert_student(rec);
                break;
            }

            case 2:
            { 
                object.read();
                break; 
            }
    
            case 3:
            { 
                cout<<"\nEnter the roll no.:";
                cin>>rollno;
                object.delete_student(rollno);
                break;
            }

            case 4:
            { 
                object.update(); 
                break;
            }

            case 5:
            { 
                cout<<"\nEnter a roll no. : ";
                cin>>rollno;
                recno=object.search_student(rollno);
                if(recno>=0)
                { cout<<"\n Record No.: "<< recno;
                object.display(recno);
                }
                else
                cout<<"\nRecord Not Found ";
                break;
            }

            case 6:
            { 
                object.pack();
                break;
            }
        }
    } while(ch!=7);

    return 0;
}



