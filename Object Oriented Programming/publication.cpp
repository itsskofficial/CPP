//including libraries and using namespace std
#include <iostream>
#include <string>
using namespace std;

class publication                     // base class
{
   protected:
        string title;
        float price;

   public:
        void add()                               //get data function
        {
            cout << "Enter Title: ";
            cin >> title;                       
            cout << "Enter price: ";
            cin >> price;
        }

        void display()                         //display function
        {
            cout << "\nTitle: " << title;
            cout << "\nPrice: " << price;
        }
};


class book : protected publication               // derived class with protected inheritance
{
   private:
        int page_count;

   public:
        void add_books()
        {
            try
            {
                add(); //call base class function
                cout << "Enter page count of book: "; 
                cin >> page_count;

                if (page_count<=0)
                    throw page_count;
            }

            catch(int pages) //catch page count
            {
                cout << "Invalid page count: " << pages;
                page_count = 0; // redeclaring property to default value
            }
            
        }

        void display_books()
        {
            display();
            cout << "\nPage count is : " << page_count;
        }
};


class tape : protected publication                // derived class with protected inheritance
{
   private:
        float play_time;

   public:
        void add_tapes()
        {
            try
            {
                add(); //calling base class function
                cout << "Enter playing time: "; 
                cin >> play_time;

                if(play_time<=0)
                    throw play_time;
            }

            catch(int time)
            {
                cout << "\nInvalid play time: " << time;
                play_time = 0;
            }
            
        }
            
        void display_tapes()
        {
            display();
            cout << "\nPlaying time: " << play_time;
        }
};

int main()
{
    book b1[3];                        // define books
    tape t1[3];                        // define tapes
    int ch,b_count,t_count;

    do
    {
        cout<<"\n***Publication Information System***";
        cout<<"\n***MENU***";
        cout<<"\n1. Add information of books ";
        cout<<"\n2. Add information of tapes ";
        cout<<"\n3. Display information to books ";
        cout<<"\n4. Display information to tapes ";
        cout<<"\n5. Exit";
        cout<<"\n Enter choice: ";
        cin>>ch;

        switch (ch)
        {
            case 1:                                        //add books
                b1[b_count].add_books();
                b_count++;
                break;

            case 2:
                t1[t_count].add_tapes();
                t_count++;
                break;

            case 3:
                cout<<"\n***Publication Information System(BOOKS)***";

                for (int j=0;j<b_count;j++)
                {
                    b1[j].display_books();
                }
                break;

            case 4:
                cout<<("\n***Publication Information System(TAPES)***");

                for (int j=0;j<t_count;j++)
                {
                    t1[j].display_tapes();
                }

                break;

            case 5:
                exit(0);
        }
    }
    while(ch!=3);

    return 0;
}


                    
