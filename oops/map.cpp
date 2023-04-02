//including the libraries and using namespace std
#include<iostream>
#include<map>
using namespace std;

int main()
{
    typedef map<string,int> mapType; //creating a map class with key value data type string and int respectively
    mapType populationMap; //creating an object of class maptype

    //inserting key value pairs into populationmap
    populationMap.insert(pair<string, int>("Maharashtra", 7026357));
    populationMap.insert(pair<string, int>("Rajasthan", 6578936));
    populationMap.insert(pair<string, int>("Karanataka", 6678993));
    populationMap.insert(pair<string, int>("Punjab", 5789032));
    populationMap.insert(pair<string, int>("West Bengal", 6676291));

    //declaring an iterator for maptype
    mapType::iterator iter;

    cout<<"========Population of states in India==========\n";
    cout<<"\n Size of the Population Map is "<<populationMap.size()<<"\n"; //displays size of map

    string state_name;
    cout<<"\n Enter name of the state :";
    cin>>state_name;
    iter = populationMap.find(state_name); //searches the map for state name

    if( iter!= populationMap.end()) //if state name is found
    {
        cout<<state_name<<"'s population is "<<iter->second ;
    }

    else //if iterator reaches end meaning the invisible element at the end
    {
        cout<<"Key is not populationMap"<<"\n";
        populationMap.clear(); //clearing memory
    }

    return 0;
}