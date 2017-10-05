#include<iostream>
using namespace std;

int main()
{
	int size,i,j,temp,n=1;
	cout<<"Enter the ize of array: ";
	cin>>size;
	int a[size];
	cout<<"Enter elements in array: ";
	for(i=0;i<size;i++)
	{
		cout<<n<<". ";
		cin>>a[i];	
		n++;
	}
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
	cout<<endl<<"Sorted array is: ";
	for(i=0;i<size;i++)
		cout<<a[i]<<" ";
}
