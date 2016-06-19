#include<iostream>
#include<queue>
#define V 4
using namespace std;

bool checkBipartite(int G[][V],int src)
{
	int color[V];
	for(int i=0;i<V;i++)
		color[i] = -1;
	
	color[src]= 1;
	queue<int> q;
	q.push(src);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int i=0;i<V;i++)
		{
			if(G[u][i]&&color[i]==-1)
			{
				color[i] = 1 - color[u];
				q.push(i);
			}
			else if(G[u][i]&&color[u]==color[i])
				return false;
		}
		
	}
	return true;

}

int main()
{
	 int G[][V] = {{0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
    
    checkBipartite(G,0)?cout<<"Bipartite":cout<<"Not Bipartite";
    return 0;
}















