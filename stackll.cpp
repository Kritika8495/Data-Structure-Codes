#include<iostream>
#include<malloc.h>
using namespace std;
struct stacklist
{
	int data;
	struct stacklist * link;
}*top=NULL;

int main()
{
	struct stacklist* ptr,*next;
	int opt,choice,val,ans;
	do
	{
		cout<<"Press \n1.Push\n2.Pop\n3.Display Stack";
		cin>>opt;
		switch(opt)
		{
			case 1:
				choice=0;
				do
				{
					cout<<"\nEnter data: ";
					cin>>val;
					next=(struct stacklist*)malloc(sizeof(stacklist));
					next->data=val;
					if(top==NULL)
					{
						next->data=val;
						next->link=NULL;
						top=next;
					}
					else
					{
						
						next->link=top;
						top=next;
					}
					cout<<"\nTo continue adding press 1: ";
					cin>>choice;
				}while(choice==1);
				break;
			case 2:
				choice=0;
				do
				{
					if(top!=NULL)
					{
						ptr=top;
						ptr=ptr->link;
						top=ptr;
						//next=next->link;
						//top=next;
						cout<<"To continue deleting press 2. ";
					}
					else
					{
						cout<<"Stack is empty.";
						break;
					}
					cin>>choice;
				}while(choice==2);
				break;
			case 3:
				cout<<"\nStack is: \n";
				next=top;
				while(next!=NULL)
				{
					cout<<next->data<<"->";
					next=next->link;
				}
				break;
		}
		cout<<"\nDo you want to see the menu again? \nPress 1 for yes. ";
		cin>>ans;
	}while(ans==1);
	free(top);
	free(ptr);
	free(next);
}
