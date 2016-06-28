#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* next;
};

void inbeginning( node** head_ref,int data)
{
	node *new_node = new node;
	new_node->data = data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void after_some(node** head_ref,int pos,int data)
{
	node *new_node = new node;
	new_node->data = data;
	node *toPt = *head_ref;
	//node *toPt1 = *head_ref;
	for(int i=0;i<pos-1;i++)
	{
		toPt = toPt->next;
	}
	new_node->next = toPt->next;
	toPt->next = new_node;
	
}

void inEnd(node** head_ref,int data)
{
//	cout<<"yo "<<*head_ref<<" "<<head_ref<<"yo";
	node *new_node = new node;
	new_node->data = data;
	new_node->next = NULL;
	node *last = *head_ref;
	
	if(*head_ref == NULL)
	{
		*head_ref = new_node;
		return ;
	}
	while(last->next!=NULL)
	{
		//cout<<last->data<<" ";
		last= last->next;
	}
	last->next = new_node;
	return;
}

void printList( node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}
void delete_ll(node **head_ref,int key)
{
	node *tmp = *head_ref,*prev;
	if(tmp != NULL && tmp->data == key)
	{
		*head_ref = tmp->next;
		delete(tmp);
		return ;
	}	
	while(tmp!=NULL&&tmp->data!=key)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if(tmp==NULL) return;
	prev->next=tmp->next;
	delete(tmp);
}
int main()
{
	node *head = NULL;
	inbeginning(&head,5);
	inbeginning(&head,4);
	inEnd(&head,3);
	inbeginning(&head,2);
	inbeginning(&head,1);
	after_some(&head,3,8);
	delete_ll(&head,3);
	printList(head);
	
}
