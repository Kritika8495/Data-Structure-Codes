#include<iostream>
#include<malloc.h>
using namespace std;
struct queuelist
{
	int data;
	struct queuelist * link;
}*head=NULL;
int main()
{
		struct queuelist *front,*rear,*next;
		int opt,choice,val,ans;
	do
	{
		cout<<"\nPress \n1.Enter data in Queue\n2.Delete data from Queue\n3.Display Queue";
		cin>>opt;
		switch(opt)
		{
			case 1:
				choice=0;
				do
				{
					cout<<"\nEnter data: ";
					cin>>val;
					next=(struct queuelist*)malloc(sizeof(queuelist));
					next->data=val;
					if(head==NULL)
					{
						next->link=NULL;
						front=next;
						rear=next;
						head=next;
					}
					else
					{
						rear=head;
						while(rear->link!=NULL)
						{
							rear=rear->link;
						}
						rear->link=next;
						next->link=NULL;
						rear=next;
					}
					cout<<"\nTo continue adding press 1: ";
					cin>>choice;
				}while(choice==1);
				break;
			case 2:
				choice=0;
				do
				{
					if(head!=NULL)
					{
						front=front->link;
						head=front;
						cout<<"\nTo continue deleting press 2: ";
					}
					else
					{
						cout<<"\nQueue is empty.";
						break;	
					}
					//cout<<"To continue deleting press 2: ";
					cin>>choice;
				}while(choice==2);
				break;
			case 3:
				cout<<"\nQueue is: \n";
				next=head;
				while(next!=NULL)
				{
					cout<<next->data<<"->";
					next=next->link;
				}
				break;
		}
		cout<<"\n Do you want to see the menu again? \nPress 1 for yes: ";
		cin>>ans;
	}while(ans==1);
	free(front);
	free(rear);
	free(next);
	free(head);
}

