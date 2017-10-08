#include<iostream>
using namespace std;

int main()
{
	int size;
	cout<<"Enter size of array: ";
	cin>>size;
	int arr[size],i,j,val,k;
	cout<<endl<<"Enter elements in array: "<<endl;
	for(i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	cout<<"Steps: "<<endl;
	for(i=1;i<size;i++)
	{
		val=arr[i];
		j=i-1;
		while(j>=0&&arr[j]>val)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=val;
		
		for(k=0;k<size;k++)
		{
			cout<<arr[k]<<" ";
		}	
	}
	cout<<"Sorted array is: "<<endl;
	for(i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
}
