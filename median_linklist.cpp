/*code to find median in a link list as numbers are added to it and sorting it simulatneously.*/
#include<iostream>
#include<stdio.h>
using namespace std;

struct list 
{
	int data;
	struct list *link;
}*head=NULL,*ptr,*curr=NULL;

struct list* insert(struct list* start,int data)
{
	ptr=new list;
	ptr->data=data;
	ptr->link=NULL;
	if(head==NULL)
	{
		head=ptr;
		curr=ptr;
	}
	else
	{
		curr->link=ptr;
		curr=ptr;
	}
}
struct list* sort(struct list* start)
{
	int temp;
	struct list* ptr,*min,*next;
	ptr=start;
	next=start;
	while(next!=NULL)
	{
		min=next;
		ptr=next;
		while(ptr->link!=NULL)
		{
			if(min->data>ptr->link->data)
				min=ptr->link;
			ptr=ptr->link;	
		}
		temp=min->data;
		min->data=next->data;
		next->data=temp;
		next=next->link;
	}
}
int median(struct list* head,int num)
{
	int count_node;
	double med;
	struct list *curr,*next,*oddnode;
	oddnode=head;
	curr=head;
	next=head->link;
	if(num%2==0)
	{
		for(count_node=1;count_node<=(num/2)-1;count_node++)
		{
			curr=curr->link;
			next=next->link;
		}
		med=(curr->data+next->data)/2.0f;
		cout<<med;
	}
	else 
	{
		for(count_node=1;count_node<=(num-1)/2;count_node++)
			oddnode=oddnode->link;
		med=oddnode->data;
	}
	return med;
}
void printlist(struct list* start)
{
	cout<<"Your list is: ";
	struct list* ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"->";
		ptr=ptr->link;
	}
	cout<<endl;
}
int main()
{
	int count,key;
	double mid=0;
	cout<<"Enter the the number of elements you want to insert: ";
	cin>>count;
	for(int i=1;i<=count;i++)
	{
		cout<<endl<<"Enter data: ";
		cin>>key;
		insert(head,key);
		sort(head);
		mid=median(head,i);
		cout<<endl<<"Median is: "<<mid <<endl;
	} 
	printlist(head);
}
