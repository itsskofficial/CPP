//including the libraries and using standard namespace
#include <iostream>
#include <string>
using namespace std;

class Student
{   
    //declaring the members in private access
    private:
        int div, *roll_no;
        string name, dob, blood_grp, addr, year_class, mob;

    public:
        //friend class declared here
        friend class Faculty;

        //default constructor
        Student()                                                       
        {
            roll_no = new int;
            *roll_no = div = -1;
            name = blood_grp = dob = addr = year_class = mob = "";
        }

        //destructor used to free space
        ~Student()                                                     
        {
            delete roll_no;
        }

        //function to add data 
        void add_data()
        {
            cout<<"\n Enter student Information";
            cout<<"\nEnter name:"<<endl;
            cin >> name;
            cout << "Enter roll_no:";
            cin>>*roll_no;
            cout<<"Enter year(SE/TE/BE):";
            cin>>year_class;
            cout<<"Enter division(1/2/3/4/5):";
            cin>>div;
            cout<<"Enter dob:";
            cin>>dob;
            cout<<"Enter blood group:";
            cin>>blood_grp;
            cout<<"Enter mobile number:";
            cin>>mob;
            cout<<"Enter address:";
            cin>>addr;
        }
        
        //function to display the student data
        void display()
        {
            cout<<"\n----------------------------------";
            cout<<"\nName            :"<< name;
            cout<<"\nRoll no         :"<< *roll_no;
            cout<<"\nYear(SE/TE/BE)  :"<< year_class;
            cout<<"\nDiv(1/2/3/4/5)  :"<< div;
            cout<<"\nDoB             :"<< dob;
            cout<<"\nBlood group     :"<< blood_grp;
            cout<<"\nMobile number   :"<< mob;
            cout<<"\nAddress         :"<< addr;
            cout<<"\n----------------------------------";
        }

    //static function used to print header
    static void header()
        {
            cout<<"\n***STUDENT INFORMATION SYSTEM***";
        }
};

//friend class definition
class Faculty
{
    private:
        int id;

    public:
        //constructor with default parameters
        Faculty(int id = 0)
        {
            this->id = id;
        }

        //function to display student info faculty wise
        void f_display(Student &obj)
        {
                //exception handling
                try
                {
                    if (obj.div == id) //check if object's division is same as that of faculty
                        obj.display();
                    else
                        throw(obj.div); //esle throw division to catch it
                }
                catch(int div)
                {
                    cout<<"\nInvalid Division: "<<div; //output the invalid division
                }
        }
};

int main()
{
    Student s[5];
    int ch, id, count = 0;

    //use do while loop for menu driven system
    do
    {
        cout<<"\n***STUDENT INFORMATION SYSYTEM***";
        cout<<"\n***MENU***";
        cout<<"\n1. Add information";
        cout<<"\n2. Display Information";
        cout<<"\n3. Faculty wise information";
        cout<<"\n4.Exit";
        cout<<"\n Enter choice: ";
        cin>>ch;

        switch (ch)
        {
            case 1:
                s[count].add_data(); //add student info one by one
                count++;
                break;

            case 2:
                for(int j=0;j<count;j++)
                {
                    Student::header(); //scope resolution for static function
                    s[j].display();
                }

                break;

            case 3:
                cout<<"\n Enter division of faculty:";
                cin >> id;
                Faculty f(id); //pass id to faculty class constructor

                for (int j = 0; j < count; j++)
                {
                    cout<<"\n***Student information system(Faculty RAS)***";
                    f.f_display(s[j]); //call faculty display function with every student
                }

                break;

            case 4:
                exit(0);
            }
    }
    while ( ch!=4);

    return 0;
}








            

        







    