#include<bits/stdc++.h>
using namespace std;

class Business
{
	int graph[100][100], offices;
	public:
		void createGraph();
		void findShortestPath();
};

void Business::createGraph()
{
	int i,j;
	cout<<"Enter total offices: ";
	cin>>offices;

	for (i=0; i<offices; i++)
	{
		for (j = i; j<offices; j++)
		{
			cout<<"\nEnter distance between "<<"office "<< i << " and "<<"office "<< j <<": ";
			cin>>graph[i][j];
			graph[j][i]=graph[i][j];
		}
	}
	for (i=0; i<offices; i++){
		for (j=0; j<offices; j++){
			if (graph[i][j]== 0)
				graph[i][j]=INT_MAX;
		}
	}
}
void Business::findShortestPath(){
	int visited[ROW], i, j, ne=0;
	int min = 0, x, y;
	int cost = 0;
	for (i=0; i< offices; i++)
		visited[i] = 0;
	visited[0] = 2;
		while(ne<offices-1){
			min = INT_MAX ;
			for (i=0;i<offices;i++){
				if (visited[i] == 2){
					for (j=0;j<offices;j++){
						if (visited[j] == 0){
							if (min>graph[i][j]){
								min=graph[i][j];
								x=i;
								y=j;
							}
						}
					}
				}
			}
		
		visited[x] = 1;
		visited[y] = 2;
		cout<< "\n" << x << " --> "<<y;
		cost += graph[x][y];
		ne++;
}
	cout<<"\nTotal cost is: "<< cost << endl;
}
int main()
{
	Business mst;
	cout << "\n--------Prims Algorithm to connect several offices------\n";
	mst.createGraph();
	mst.findShortestPath();
	return 0;
}