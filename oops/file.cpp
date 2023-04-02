//including the libraries and using namespace std
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream file;                                    //object of fstream class
    file.open("sample.txt", ios::out);               //opening file "sample.txt" in out(write) mode

    if (!file)
    {
        cout<<"Error in creating the file."<<endl;
        return 0;
    }

    cout<<"File created successfully."<<endl;       
    file<<"Hello there!"<<endl;                     //Writing text into the file
    file.close();                                   //Closing the file

    file.open("sample.txt",ios::in);                //opening the file in <read> mode

    if(!file)
    {
        cout<<"Error in opening file!"<<endl;
        return 0;
    }

    char ch;                                        //to read single character
    cout<<"File content: ";

    while(!file.eof())                              //reading the file until it's end is found.
    {
        file>>ch;                                   //read single character from file
        cout<<ch;
    }

    file.close(); //close file
    
    return 0;
}
























