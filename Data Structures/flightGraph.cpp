//There are flight paths between cities. If there is a flight between city A and city B then there is an edge 
//between the cities. The cost of the edge can be the time that flight take to reach city B from A, or the 
//amount of fuel used for the journey. Represent this as a graph. The node can be represented by airport 
//name or name of the city. Use adjacency list representation of the graph or use adjacency matrix 
//representation of the graph. Check whether the graph is connected or not.

#include <bits/stdc++.h>
using namespace std;
int adj_mat[50][50] = {0, 0};
int visited[50] = {0};

class flight{
    int n;
    string cities[50];
    public:
        void input();
        void display();
};

void flight::input(){
    cout <<"\nEnter no. of cities: ";
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cout <<"Enter city "<<i+1<<" (Airport Code): ";
        cin >> cities[i];
    }
    cout << "\nYour cities are: ";
    for (int i=0; i<n; i++)
        cout <<"\ncity "<<i+1<<": "<<cities[i];
        
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            cout <<"\nEnter distance between "<< cities[i]<<" and "<<cities[j]<<" : ";
            cin >> adj_mat[i][j];
            adj_mat[j][i] = adj_mat[i][j];
        }
    }
}

void flight::display(){

    for (int i=0; i<n; i++)
    {
        cout<<"\t"<<cities[i]<<"\t";
    }
    for (int i=0; i<n; i++)
    {
        cout<<"\n"<< cities[i];
        for (int j=0; j<n; j++)
            cout<<"\t" << adj_mat[i][j] << "\t";
    }
}

int main(){
    flight obj;
    obj.input();
    obj.display();
    return 0;
}