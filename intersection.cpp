#include<iostream>
using namespace std;

struct list
{
	int data;
	struct list* link;
}*head1=NULL,*head2=NULL,*node,*next=NULL,*head=NULL;
int count1=0,count2=0,count=0;
struct list* insert(struct list* start,int count)
{
	int i,key;
	struct list* ptr=NULL,*curr=NULL,*head=NULL;
	cout<<"Enter elements for list: "<<endl;
	for(i=0;i<count;i++)
	{
		cin>>key;
		ptr=new list;
		ptr->data=key;
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
	start=head;
	return start;
}
struct list* intersect_insert(struct list* head,int info)
{
	node=new list;
	node->data=info;
	node->link=NULL;
	if(head==NULL)
	{
		head=node;
		next=node;
	}
	else
	{
		next->link=node;
		next=node;
	}
	next->link=NULL;
	return head;
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
struct list* intersect(struct list* head1,struct list* head2,int diff)
{
	struct list* ptr1,*ptr2,*ptr,*curr=NULL,*head=NULL;
	ptr1=head1;
	ptr2=head2;
	for(int i=0;i<diff;i++)
		ptr1=ptr1->link;
	while(ptr1->data!=ptr2->data)
	{
		ptr1=ptr1->link;
		ptr2=ptr2->link;
	}
	cout<<"Intersection point is: "<<ptr1->data<<endl;
	while(ptr1!=NULL)
	{
		head=intersect_insert(head,ptr1->data);
		ptr1=ptr1->link;
	}
	printlist(head);
}

int main()
{
	int d;
	cout<<"Enter the number of elements you want to insert in list 1."<<endl;
	cin>>count1;
	head1=insert(head1,count1);
	printlist(head1);
	cout<<endl<<"Enter the number of elements you want to insert in list 2."<<endl;
	cin>>count2;
	head2=insert(head2,count2);
	printlist(head2);
	if(count1>count2)
	{
		d=count1-count2;
		intersect(head1,head2,d);
	}
	else if(count1<count2)
	{
		d=count2-count1;
		intersect(head2,head1,d);
	}
}

