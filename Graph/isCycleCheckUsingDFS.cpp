// src http://www.geeksforgeeks.org/detect-cycle-in-a-graph/
#include<iostream>
#include<limits.h>
#include<list>
using namespace std;

class Graph{
	
	int V;
	list<int> *adj;
	public:
		Graph(int V){this->V=V;adj = new list<int>[V];}
		void addEdge(int v,int w)
		{
			adj[v].push_back(w);
		}
		bool isCycleUtil(int v,bool visited[],bool *recStack)
		{
			if(!visited[v])
			{
				visited[v] =true;
				recStack[v] = true;
				list<int>::iterator i;
				for(i = adj[v].begin();i!= adj[v].end();i++)
				{
					if(!visited[*i]&&isCycleUtil(*i,visited,recStack))
					{
						return true;
					}
					else if(recStack[*i])
						return true;
				}
			}
			recStack[v]=false; //remove vertex from recStack
			return false;
		}
		bool isCyclic()
		{
			bool *visited = new bool[V];
			bool *recStack = new bool[V];
			for(int i=0;i<V;i++)
			{
				visited[i] = false;
				recStack[i] = false;
			}
			
			for(int i=0;i<V;i++)
			{
				if(isCycleUtil(i,visited,recStack))
					return true;
			}
			
			return false;
		}
	
};

int main()
{
  
   Graph graph(4);
	
	graph.addEdge(0,1);
	graph.addEdge(0,2);
	graph.addEdge(1,2);
	graph.addEdge(2,0);
	graph.addEdge(2,3);
	graph.addEdge(3,3);
 
    if(graph.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}








