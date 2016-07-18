#include<iostream>
using namespace std;
class SelectionSort {
public:
    int* selectionSort(int* A, int n) 
	//—°‘Ò≈≈–Ú
    {
		int i=0,j,min,temp;
		while(i<n-1)
		{
			min=i;
			for(j=i+1;j<n;j++)
				if(A[j]<A[min])
					min=j;
			if(min!=i)
			{
				temp=A[i];
				A[i]=A[min];
				A[min]=temp;
			}
			i++;
		}
		return A;
    }
};

int main()
{
	int arr[]={2,4,7,9,8,6};
	SelectionSort a;
	a.selectionSort(arr,6);
	for(int i=0;i<6;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
