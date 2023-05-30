#include<bits/stdc++.h>
using namespace std;
#define ROW 10
#define COL 10
#define infi 999

class prims{
	int graph[ROW][COL], nodes;
	public:
		void createGraph();
		void primsAlgo();
};
void prims::createGraph(){
	int i,j;
	cout<<"Enter total offices: ";
	cin>>nodes;
	cout<<"\nEnter Adjacency Matrix: \n";
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
				graph[i][j]=infi;
		}
	}
}
void prims::primsAlgo(){
	int selected[ROW], i, j, ne=0;
	int zero = 0, one = 1, min = 0, x, y;
	int cost = 0;
	for (i=0; i< nodes; i++)
		selected[i] = zero;
	selected[0] = 2;
		while(ne<nodes-1){
			min = infi ;
			for (i=0;i<nodes;i++){
				if (selected[i] == 2){
					for (j=0;j<nodes;j++){
						if (selected[j] == zero){
							if (min>graph[i][j]){
								min=graph[i][j];
								x=i;
								y=j;
							}
						}
					}
				}
			}
		
		selected[x] = one;
		selected[y] = 2;
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