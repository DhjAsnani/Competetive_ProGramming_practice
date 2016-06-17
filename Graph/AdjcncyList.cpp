#include<iostream>
#include<cstdlib>
using namespace std;
struct AdjListNode
{
	int dest;
	struct AdjListNode* next;
};
struct AdjList
{
	struct AdjListNode* head;
};
class Graph
{
	private:
		int V;
		struct AdjList* array;
	public:
		Graph(int V)
		{
			this->V = V;
			array = new AdjList[V];
			for(int i=0;i<V;i++)
				array[i].head = NULL;
		}
		
		AdjListNode *newAdjListNode(int dest)
		{
			AdjListNode *newnode = new AdjListNode;
			newnode->dest = dest;
			newnode->next = NULL;
			return newnode;
		}
		
		void addEdge(int src,int dest)
		{
			AdjListNode *newnode = newAdjListNode(dest);
			newnode->next = array[src].head;
			array[src].head = newnode;
			newnode = newAdjListNode(src);
			newnode->next = array[dest].head;
			array[dest].head= newnode;
		}
		void printGRP()
		{
			for(int i=0;i<V;i++)
			{
				AdjListNode* crawl = array[i].head;
				cout<<i<<"----->";
				while(crawl)
				{
					cout<<"->"<<crawl->dest<<"";
					crawl = crawl->next;
				}
				cout<<"\n";
			}
		}
};
int main()
{
    Graph gh(5);
   
    gh.addEdge(0, 1);
    gh.addEdge(0, 4);
    gh.addEdge(1, 2);
    gh.addEdge(1, 3);
    gh.addEdge(1, 4);
    gh.addEdge(2, 3);
    gh.addEdge(3, 4);
 
    
    gh.printGRP();
    return 0;
}




















