#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	list<int> *adj;
	public:
		Graph(int V)
		{
			this->V = V;
			adj = new list<int>[V];
		}
		void addEdge(int v,int w)
		{
			adj[v].push_back(w);
		}
		int find(int parent[],int i)
		{
			if(parent[i] == -1)
				return i;
			find(parent,parent[i]);
		}
		void Union(int parent[],int x,int y)
		{
			int xset = find(parent,x);
			int yset = find(parent,y);
			parent[xset] = yset;
		}
		int isCycle()
		{
			int *parent = new int[V];
			memset(parent,-1,sizeof(parent));
			for(int i=0;i<V;i++)
			{
				list<int>::iterator j;
				for( j=adj[i].begin();j!=adj[i].end();i++)
				{
					int x = find(parent,i);
					int y = find(parent,*j);
					if(x==y)return true;
					Union(parent,x,y);
				}
			}
			return 0;
		}
};
int main()
{
	Graph graph(3);
	graph.addEdge(0,1);
	graph.addEdge(1,2);
//	graph.addEdge(0,2);
	
	if(graph.isCycle())
	{
		cout<<"Cycle Exist\n";
	}
	else
	{
		cout<<"Cycle Does Not Exist\n";
	}
}









