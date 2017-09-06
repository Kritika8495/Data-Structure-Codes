#include<iostream>
#include<stdlib.h>
#include<malloc.h>
#include<stdint.h>
using namespace std;
struct llist
{
	int data;
	struct llist* link;
}*head=NULL;
struct llist* back=NULL;

void insert(struct llist** start, int val)
{
	cout<<"working.."<<endl;
	struct llist* newnode=(struct llist*)malloc(sizeof(llist));
	newnode->data=val;
	newnode->link=(struct llist*)((uintptr_t)(*start)^(uintptr_t)NULL);
	if(*start!=NULL)
	{
		struct llist* next=(struct llist*)((uintptr_t)(*start)->link^(uintptr_t)NULL);
		(*start)->link=(struct llist*)((uintptr_t)newnode^(uintptr_t)next);
	}
	*start=newnode;
}
void fwdtrav(struct llist* head)
{
	struct llist* curr=NULL,*prev=NULL,*next=NULL;
	curr=head;
		cout<<"Forward Traversal.  ";
	while(curr!=NULL)
	{
		cout<<curr->data<<"->";
		next=(struct llist*)((uintptr_t)curr->link^(uintptr_t)prev);
		prev=curr;
		back=curr;
		curr=next;
	}
	cout<<endl;
}
void backtrav(struct llist* bckptr)
{
	struct llist* curr=NULL,*bcknode=NULL,*next=NULL;
	curr=bckptr;
	cout<<"Backward Traversal.  ";
	while(curr!=NULL)
	{
		cout<<curr->data<<"->";
		bcknode=(struct llist*)((uintptr_t)curr->link^(uintptr_t)next);
		next=curr;
		curr=bcknode;
	}
}
int main()
{
	insert(&head,10);
	insert(&head,20);	
	insert(&head,30);
	insert(&head,40);
	fwdtrav(head);
	backtrav(back);
}
