#include<iostream>
#include<list>
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
		 void DFSUtil(int v,bool visited[])
		 {
		 	visited[v] = true;
		 	cout<<v<<" ";
		 	list<int>::iterator i;
		 	for( i = adj[v].begin();i!=adj[v].end();i++)
		 	{
		 		if(!visited[*i])
		 		{
		 			DFSUtil(*i,visited);
				 }
			 }
		 }
		 void DFS(int v)
		 {
		 	bool *visited = new bool[V];
		 	for(int i=0;i<V;i++)
		 	{
		 		visited[i] = false;
			 }
			 DFSUtil(v,visited);
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
	
	cout<<"DFS\n";
	graph.DFS(2);
}





















