#include<iostream>
using namespace std;

struct tree
{
	int data;
	tree* left;
	tree* right;
};
tree* makenode(int val)
{
	tree* temp=new tree;
	temp->data=val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void insertRight(tree* node,int val)
{
	node->right=makenode(val);
}
void insertLeft(tree* node,int val)
{
	node->left=makenode(val);
}
void insert(tree* node,int val)
{
	while(1)
	{
		if(val>node->data)
		{
			if(node->right!=NULL)
				node=node->right;
			else
			{
				insertRight(node,val);
				break;
			}
		}
		else if(node->data>val)
		{
			if(node->left!=NULL)
				node=node->left;
			else
			{
				insertLeft(node,val);
				break;
			}
		}
	}
}
void inorderTrav(tree* rtree)
{

	if(rtree->left!=NULL)
		inorderTrav(rtree->left);
	cout<<rtree->data<<endl;
	if(rtree->right!=NULL)
		inorderTrav(rtree->right);
}

int main()
{
	tree* root=makenode(90);
	int i=0;
	int arr[5]={70,100,80,110,60};
	for(i=0;i<=4;i++)
	{
		insert(root,arr[i]);
	}
	cout<<"Your tree is: "<<endl;
	inorderTrav(root);
}
