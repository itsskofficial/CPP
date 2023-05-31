#include<bits/stdc++.h>
using namespace std;

class prims{
	int graph[100][100], nodes;
	public:
		void createGraph();
		void primsAlgo();
};
void prims::createGraph(){
	int i,j;
	cout<<"Enter total offices: ";
	cin>>nodes;
	cout<<"\nEnter adjacency matrix: \n";
	for (i=0; i<nodes; i++){
		for (j = i; j<nodes; j++){
			cout<<"\nEnter distance between "<< i << " and "<< j <<": ";
			cin>>graph[i][j];
			graph[j][i]=graph[i][j];
		}
	}
	for (i=0; i<nodes; i++){
		for (j=0; j<nodes; j++){
			if (graph[i][j]== 0)
				graph[i][j]=INT_MAX;
		}
	}
}
void prims::primsAlgo(){
	int visited[ROW], i, j, ne=0;
	int min = 0, x, y;
	int cost = 0;
	for (i=0; i< nodes; i++)
		visited[i] = 0;
	visited[0] = 2;
		while(ne<nodes-1){
			min = INT_MAX ;
			for (i=0;i<nodes;i++){
				if (visited[i] == 2){
					for (j=0;j<nodes;j++){
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
	prims mst;
	cout << "\n--------Prims Algorithm to connect several offices------\n";
	mst.createGraph();
	mst.primsAlgo();
	return 0;
}