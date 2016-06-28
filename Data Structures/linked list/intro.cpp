// src linked list by geeksforgeeks.org
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
void delFromPosition(node **head_ref,int pos)
{
	node *tmp = *head_ref,*prev;
	if(pos==1)
	{
		*head_ref = tmp->next;
		delete(tmp);
		return ;
	}
	for(int i=0;i<pos-1;i++)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if(tmp==NULL) return;
	prev->next = tmp->next;
	delete(tmp);
}
int len(node **head_ref)
{
	node* tmp = *head_ref;
	int len = 0;
	while(tmp!=NULL)
	{
		len++;
		tmp=tmp->next;
	}
	return len;
}
int lenRec(node* head)
{
		
	if(head==NULL)
		return 0;
	else return 1+lenRec(head->next);
}
void swapp(node **head_ref,int a,int b)
{
	node *s1=*head_ref,*s1prev=NULL,*s2=*head_ref,*s2prev=NULL,*tmp;
	while(s1->data!=a&&s1!=NULL)
	{
		s1prev = s1;
		s1=s1->next;
	}
	while(s2->data!=b&&s2!=NULL)
	{
		s2prev = s2;
		s2=s2->next;
	}
	tmp = s2->next;
	s1prev->next = s2;
	s2->next = s1->next;
	s2prev->next = s1;
	s1->next=tmp;
}
void reverse(node **head)
{
	node *next,*prev=NULL,*curr = *head;
	while(curr!=NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev=curr;
		curr = next;
	}
	*head = prev;
}
int main()
{
	node *head = NULL;
	inbeginning(&head,5);
	inbeginning(&head,4);
	inEnd(&head,3);
	inbeginning(&head,2);
	inbeginning(&head,21);
	inbeginning(&head,22);
	inbeginning(&head,1);
	after_some(&head,3,8);
	delete_ll(&head,3);
	delFromPosition(&head,4);
	swapp(&head,21,4);
	printList(head);
	cout<<"\n"<<len(&head)<<" "<<lenRec(head);
	//printhead(&head);
	cout<<"\n";
	reverse(&head);
	printList(head);
	
}
