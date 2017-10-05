#include<iostream>
using namespace std;

int selection_sort(int arr[],int size)
{
	int min,temp,i,j;
	for(i=0;i<size;i++)
	{
		min=i;
		for(j=i+1;j<size;j++)
		{
			if(arr[min]>arr[j])
				min=j;
		}
		temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
}
int main()
{
	int size,i,num=1;
	cout<<endl<<"Enter the size of array: ";
	cin>>size;
	int a[size];
	cout<<"Enter elements in array: "<<endl;
	for(i=0;i<size;i++)
	{
		cout<<num<<". ";
		cin>>a[i];
		num++;
	}
	selection_sort(a,size);
	cout<<"Sorted array: ";
	for(i=0;i<size;i++)
	{
		cout<<a[i]<<" ";
	}
}
