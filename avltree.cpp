#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
int bal_node;
struct avltree
{
	struct avltree* left;
	struct avltree* right;
	int key;
	int height;
};
avltree* makenode(int val)
{
	avltree* temp=new avltree;
	temp->left=NULL;
	temp->right=NULL;
	temp->key=val;
	temp->height=1;
	cout<<"Element inserted: "<<val<<endl;
	return temp;
}
int height(avltree* curr)
{
	if(curr==NULL)
	return 0;
	else
	return curr->height;
}
int balance(avltree* curr)
{
	if(curr==NULL)
	return 0;
	else
	return (height(curr->left)-height(curr->right));
}
int max(avltree* rleft,avltree* rright)
{
	if(rleft->height>rright->height)
		return rleft->height;
	else
		return rright->height;
}
avltree* right_rotate(avltree* node)
{
	avltree* t1=new avltree;
	avltree* t2=new avltree;
	t1=node->left;
	t2=t1->right;
	t1->right=node;
	node->left=t2;
	node->height=max(height(node->left),height(node->right))+1;
	t1->height=max(height(t1->left),height(t1->right))+1;
	return t1;
}
avltree* left_rotate(avltree* node)
{
	avltree* t1=new avltree;
	avltree* t2=new avltree;
	t1=node->right;
	t2=t1->left;
	t1->left=node;
	node->right=t2;
	node->left=t2;
	node->height=max(height(node->left),height(node->right))+1;
	t1->height=max(height(t1->left),height(t1->right))+1;
	return t1;	
}
avltree* insert(avltree* node,int val)
{
	if(node==NULL)
	{
		return (makenode(val));
	}
	if(val>node->key)
	{
		node->right=insert(node->right,val);
	}
	else
	{
		node->left=insert(node->left,val);
	}
	node->height=max(height(node->left),height(node->right))+1;
	bal_node=balance(node);
	cout<<"Balance Factor: "<<bal_node<<endl;
	if((bal_node>1)&&(val<node->left->key) )
		return right_rotate(node);
	if((bal_node<-1)&&(val>node->right->key))
		return left_rotate(node);
	if((bal_node>1)&&(val>node->left->key))
	{
		node->left=left_rotate(node->left);
		return right_rotate(node);
	}
	if((bal_node<-1)&&(val<node->right->key))
	{
		node->right=right_rotate(node->right);
		return left_rotate(node);
	}
	return node;
}
void inorderTrav(avltree* rroot)
{
	if(rroot->left!=NULL)
		inorderTrav(rroot->left);
	cout<<rroot->key<<endl;
	if(rroot->right!=NULL)
		inorderTrav(rroot->right);
}
int main()
{
	int val,count,i,data;
	avltree* root=new avltree;
	root=NULL;
	cout<<"Enter the number of elements you want to insert: ";
	cin>>count;
	//val=rand()%100;
	for(i=0;i<count;i++)
	{
		cout<<"Enter data: "<<endl;
		cin>>data;
		if(root==NULL)
			root=makenode(data);
		else
			root=insert(root,data);	
	}
	
	/*for(i=0;i<count;i++)
	{
		val=rand()%100;
		root=insert(root,val);
	}*/
	cout<<endl<<"Inorder Traversal of tree: "<<endl;
	inorderTrav(root);
	
	
}
