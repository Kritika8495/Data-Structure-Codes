#include<iostream>
#include<malloc.h>
using namespace std;
struct llist
{
	int data;
	struct llist * link;
}*head=NULL;
int main()
{
	int val,num;
	char ans;
	struct llist *next,*temp;
	cout<<"Enter the number of elements in link list : ";
	cin>>num;
	for(int i=0;i<=num;i++)
	{
	
		cout<<"Enter data :";
		cin>>val;
		if(head==NULL)
		{
			next=(struct llist*)malloc(sizeof( llist));
			
			next->data=val;
			next->link=NULL;
			head=next;
			
		}
		else
		{
			temp=(struct llist*)malloc(sizeof(llist));
			temp->data=val;
			temp->link=NULL;
			next->link=temp;
			next=temp;	
		}
	
	}
	next=head;
	while(next!=NULL)
	{
		cout<<next->data<<"->";
		next=next->link;
	}
	free(next);
	free(temp);
	free(head);
	
}
