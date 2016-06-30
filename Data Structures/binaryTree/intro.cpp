#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node* l;
	node* r;
};
node *newNode(int data)
{
	
	node *newnode = new node;
	newnode->data = data;
	newnode->l = NULL;
	newnode->r = NULL; 
	return newnode;
}
void inorder(node *root)
{
	if(root == NULL)
		return;
	inorder(root->l);
	cout<<root->data;
	inorder(root->r);
}
void preorder(node *root)
{
	if(root == NULL)
		return;
	cout<<root->data;
	preorder(root->l);
	
	preorder(root->r);
}
void postorder(node *root)
{
	if(root == NULL)
		return;
	//cout<<root->data;
	postorder(root->l);
	
	postorder(root->r);
	cout<<root->data;
}
void bfs(node *root)
{
	
	queue<node*> s;
	s.push(root);
	while(!s.empty())
	{
		
		node *tmp = s.front();
		cout<<tmp->data;
		s.pop();
		
		if(tmp->l)
		{
			s.push(tmp->l);
		}
			if(tmp->r)
		{
			s.push(tmp->r);
		}
	
		
	}
}
void dfs(node *root)
{
	
	stack<node*> s;
	s.push(root);
	while(!s.empty())
	{
		
		node *tmp = s.top();
		cout<<tmp->data;
		s.pop();
		
			if(tmp->r)
		{
			s.push(tmp->r);
			
		}
	
		if(tmp->l)
		{
			s.push(tmp->l);
		}
		
		
	}
}
int height(node *root)
{
	if(root==NULL)return 0;
	else return 1 + max(height(root->l),height(root->r));
}
int diameter(node *root)
{
	if(root==NULL) return 0;
	int hl = height(root->l);
	int hr = height(root->r);
	int dl = diameter(root->l);
	int dr = diameter(root->r);
	return max(hl+hr+1,max(dl,dr));
	
	
}
int width(node *tree,int level)
{
	if(tree==NULL)return 0;
	if(level == 1)return 1;
	else return width(tree->l,level-1) + width(tree->r,level-1);
}
int main()
{
	node *root = newNode(1);
	root->l = newNode(2);
	root->r = newNode(3);
	root->l->l = newNode(4);
	root->l->r = newNode(5);
	root->r->l = newNode(6);
	root->r->r = newNode(7);
	root->r->r->r =newNode(8);
	inorder(root);
	cout<<"\n";
	preorder(root);
	cout<<"\n";
	postorder(root);
	cout<<"\n";
	bfs(root);
	cout<<"\n";
	dfs(root);
	cout<<"\n"<<height(root)<<"\n";
	cout<<diameter(root)<<"\n";
	cout<<width(root,3);

}
