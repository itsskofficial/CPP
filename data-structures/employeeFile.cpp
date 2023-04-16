#include<iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class Employee
{
    typedef struct emp
    {
        char name[10];
        int emp_id;
        int salary;
    } rec;

    typedef struct index
    {
        int emp_id;
        int position;
    } ind;

    rec records;
    ind ind_records;

    public:
        Employee();
        void Create();
        void Display();
        void Update();
        void Delete();
        void Append();
        void Search();
};

Employee::Employee()//constructor 
{
   strcpy(records.name,"");
}

void Employee::Create()
{
    int i,j;
    char ch='y';
    fstream seqfile;
    fstream indexfile;
    i=0;
    indexfile.open("IND.DAT",ios::in|ios::out|ios::binary);
    seqfile.open("EMP.DAT",ios::in|ios::out|ios::binary);

    do
    {
        cout<<"\n Enter Name: ";
        cin>>records.name;
        cout<<"\n Enter Emp_ID: ";
        cin>>records.emp_id;
        cout<<"\n Enter Salary: ";
        cin>>records.salary;
        seqfile.write((char*)&records,sizeof(records))<<flush;
        ind_records.emp_id=records.emp_id;
        ind_records.position=i;
        indexfile.write((char*)&ind_records,sizeof(ind_records))<<flush;
        i++;
        cout<<"\nDo you want to add more records?";
        cin>>ch;
    } while(ch=='y');

    seqfile.close();
    indexfile.close();
}

void Employee::Display()
{
    fstream seqfile;
    fstream indexfile;
    int n,i,j;
    seqfile.open("EMP.DAT",ios::in|ios::out|ios::binary);
    indexfile.open("IND.DAT",ios::in|ios::out|ios::binary);
    indexfile.seekg(0,ios::beg);
    seqfile.seekg(0,ios::beg);
    cout<<"\n The Contents of file are ..."<<endl;
    i=0;

    while(indexfile.read((char *)&ind_records,sizeof(ind_records)))
    {

        i=ind_records.position*sizeof(rec);//getting pos from index file
        seqfile.seekg(i,ios::beg);//seeking record of that pos from seq.file
        seqfile.read((char *)&records,sizeof(records));//reading record

        if (records.emp_id!=-1)//if rec. is not deleted logically
        {   //then display it
            cout<<"\nName: "<<records.name<<flush;
            cout<<"\nEmp_ID: "<<records.emp_id;
            cout<<"\nSalary: "<<records.salary;
            cout<<"\n";
        }

    }

    seqfile.close();
    indexfile.close();
}

void Employee::Update()
{
    int pos,id;
    char New_name[10];
    int New_emp_id;
    int New_salary;
    cout<<"\n For updation,";
    cout<<"\n Enter the Emp_ID for for searching ";
    cin>>id;
    fstream seqfile;
    fstream indexfile;
    seqfile.open("EMP.DAT",ios::in|ios::out|ios::binary);
    indexfile.open("IND.DAT",ios::in|ios::out|ios::binary);
    indexfile.seekg(0,ios::beg);
    pos=-1;

    //reading index file for getting the index
    while(indexfile.read((char *)&ind_records,sizeof(ind_records)))
    {
        if(id==ind_records.emp_id)//the desired record is found
        {
            pos=ind_records.position;//getting the position
            break;
        }
    }

    if(pos==-1)
    {
        cout<<"\n The record is not present in the file";
        return;
    }
    else
    {
        cout<<"\n Enter the values for updation...";
        cout<<"\n Name: ";cin>>New_name;
        cout<<"\n Salary: ";cin>>New_salary;
        //calculating the position of record in seq. file using the pos of ind. file
        int offset=pos*sizeof(Rec);
        seqfile.seekp(offset);//seeking the desired record for modification
        strcpy(records.name,New_name);//can be updated
        records.emp_id=id;//It's unique id,so don't change
        records.salary=New_salary;//can be updated
        seqfile.write((char*)&records,sizeof(records))<<flush;
        cout<<"\n The record is updated!!!";
    }

    seqfile.close();
    indexfile.close();
}

void Employee::Delete()
{
    int id,pos;
    cout<<"\n For deletion,";
    cout<<"\n Enter the Emp_ID for for searching ";
    cin>>id;
    fstream seqfile;
    fstream indexfile;
    seqfile.open("EMP.DAT",ios::in|ios::out|ios::binary);
    indexfile.open("IND.DAT",ios::in|ios::out|ios::binary);
    seqfile.seekg(0,ios::beg);
    indexfile.seekg(0,ios::beg);
    pos=-1;
    //reading index file for getting the index
    while(indexfile.read((char *)&ind_records,sizeof(ind_records)))
    {
        if(id==ind_records.emp_id) //desired record is found
        {
            pos=ind_records.position;
            ind_records.emp_id=-1;
            break;
        }
    }

    if(pos==-1)
    {
        cout<<"\n The record is not present in the file";
        return;
    }
    //calculating the position of record in seq. file using the pos of ind. file
    int offset=pos*sizeof(rec);
    seqfile.seekp(offset);//seeking the desired record for deletion
    strcpy(records.name,"");
    records.emp_id=-1; //logical deletion
    records.salary=-1; //logical deletion
    seqfile.write((char*)&records,sizeof(records))<<flush;//writing deleted status 
        //From index file also the desired record gets deleted as follows
    offset=pos*sizeof(ind);//getting position in index file
    indexfile.seekp(offset); //seeking that record
    ind_records.emp_id=-1; //logical deletion of emp_id
    ind_records.position=pos;//position remain unchanged
    indexfile.write((char*)&ind_records,sizeof(ind_records))<<flush;
    seqfile.seekg(0);
    indexfile.close();
    seqfile.close();
    cout<<"\n The record is deleted!!!";
}

void Employee::Append()
{
    fstream seqfile;
    fstream indexfile;
    int pos;
    indexfile.open("IND.DAT",ios::in|ios::binary);
    indexfile.seekg(0,ios::end);
    pos=indexfile.tellg()/sizeof(ind_records);
    indexfile.close();

    indexfile.open("IND.DAT",ios::app|ios::binary);
    seqfile.open("EMP.DAT",ios::app|ios::binary);

    cout<<"\n Enter the record for appending";
    cout<<"\nName: ";cin>>records.name;
    cout<<"\nEmp_ID: ";cin>>records.emp_id;
    cout<<"\nSalary: ";cin>>records.salary;
    seqfile.write((char*)&records,sizeof(records));//inserting rec at end in seq. file
    ind_records.emp_id=records.emp_id;           //inserting rec at end in ind. file
    ind_records.position=pos;                          //at calculated pos
    indexfile.write((char*)&ind_records,sizeof(ind_records))<<flush;
    seqfile.close();
    indexfile.close();
    cout<<"\n The record is Appended!!!";
    }
    
void Employee::Search()
{
    fstream seqfile;
    fstream indexfile;
    int id,pos,offset;
    cout<<"\n Enter the Emp_ID for searching the record ";
    cin>>id;
    indexfile.open("IND.DAT",ios::in|ios::binary);
    pos=-1;

    //reading index file to obtain the index of desired record
    while(indexfile.read((char *)&ind_records,sizeof(ind_records)))
        {
        if(id==ind_records.emp_id)//desired record found
        {
            pos=ind_records.position;//seeking the position
            break;
        }
    }

    if(pos==-1)
    {
        cout<<"\n Record is not present in the file";
        return;
    }
    //calculate offset using position obtained from ind. file
    offset=pos*sizeof(records);
    seqfile.open("EMP.DAT",ios::in|ios::binary);
    //seeking the record from seq. file using calculated offset
    seqfile.seekg(offset,ios::beg);//seeking for reading purpose
    seqfile.read((char *)&records,sizeof(records));

    if(records.emp_id==-1)
    {
        cout<<"\n Record is not present in the file";
        return;
    }
    else //emp_id=desired record’s id
    {
        cout<<"\n The Record is present in the file and it is...";
        cout<<"\n Name: "<<records.name;
        cout<<"\n Emp_ID: "<<records.emp_id;
        cout<<"\n Salary: "<<records.salary;
    }

    seqfile.close();
    indexfile.close();
}
void main()
{
 Employee List;
 char ans='y';
 int choice,key;
 clrscr();
 do
 {
  cout<<"\n             Main Menu             "<<endl;
  cout<<"\n 1.Create";
  cout<<"\n 2.Display";
  cout<<"\n 3.Update";
  cout<<"\n 4.Delete";
  cout<<"\n 5.Append";
  cout<<"\n 6.Search";
  cout<<"\n 7.Exit";
  cout<<"\n Enter your choice: ";
  cin>>choice;
  switch(choice)
  {
  case 1:List.Create();
      break;
  case 2:List.Display();
      break;
  case 3:List.Update();
      break;
  case 4:List.Delete();
      break;
  case 5:List.Append();
      break;
  case 6:List.Search();
      break;
  case 7:exit(0);
  }
 cout<<"\n\t Do you want to go back to Main Menu?";
 cin>>ans;
 }while(ans=='y');
}