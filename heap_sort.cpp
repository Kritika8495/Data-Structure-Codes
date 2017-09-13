#include <iostream>
using namespace std;

void swap(int *e1,int *e2)
{
	int *temp;
	*temp=*e1;
	*e1=*e2;
	*e2=*temp;
}
void heapify(int arr[], int n, int i)
{
    int max = i;  
    int l = 2*i + 1;  
    int r = 2*i + 2;  
    if (l < n && arr[l] > arr[max])
        max = l;
    if (r < n && arr[r] > arr[max])
        max = r;
    if (max != i)
    {
        swap(arr[i], arr[max]);
        heapify(arr, n, max);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void show(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}
 
int main()
{
	int count;
	cout<<"Enter the number of elements: ";
	cin>>count;
    int arr[count];
    cout<<endl<<"Enter the array: ";
    for(int i=0;i<count;i++)
    	cin>>arr[i];
    heapSort(arr, count);
    cout << "Sorted array is: "<<endl;
    show(arr, count);
}
