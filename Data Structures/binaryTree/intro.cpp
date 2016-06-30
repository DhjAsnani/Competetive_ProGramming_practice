#include<iostream>
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
int main()
{
	node *root = newNode(1);
	root->l = newNode(2);
	root->r = newNode(3);
	root->l->l = newNode(4);
	root->l->r = newNode(5);
	root->r->l = newNode(6);
	root->r->r = newNode(7);
	inorder(root);
	cout<<"\n";
	preorder(root);
	cout<<"\n";
	postorder(root);

}
