#include<bits/stdc++.h>
using namespace std;
#define CURRENT 2
#define VISITED 1
#define NOT_VISITED 0

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

	for (i=0; i<offices; i++)
	{
		for (j=0; j<offices; j++)
		{
			if (graph[i][j]== 0)
				graph[i][j]=INT_MAX;
		}
	}
}
void Business::findShortestPath()
{
	int office_status[100], i, j, k=0;
	int min, source, destination;
	int cost = 0;

	for (i=0; i< offices; i++)
		office_status[i] = NOT_VISITED;

	office_status[0] = CURRENT;
		while(k<offices-1)
		{
			min = INT_MAX ;
			for (i=0;i<offices;i++)
			{
				if (office_status[i] == CURRENT)
				{
					for (j=0;j<offices;j++)
					{
						if (office_status[j] == NOT_VISITED)
						{
							if (min>graph[i][j])
							{
								min=graph[i][j];
								source=i;
								destination=j;
							}
						}
					}
				}
			}
		
		office_status[source] = VISITED;
		office_status[destination] = CURRENT;
		cout<< "\n" << source << " --> "<<destination;
		cost += graph[source][destination];
		k++;
}
	cout<<"\nTotal cost is: "<< cost << endl;
}

int main()
{
	Business mst;
	cout << "\nLet's do business with several offices\n";
	mst.createGraph();
	mst.findShortestPath();
	return 0;
}