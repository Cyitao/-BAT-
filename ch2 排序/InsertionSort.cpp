#include<iostream>
using namespace std;
class InsertionSort {
public:
    int* insertionSort(int* A, int n)
	//≤Â»Î≈≈–Ú
	{
        int i=1,j,temp;
		while(i<n)
		{
			temp=A[i];
			j=i-1;
			while(j>=0&&A[j]>temp)
			{
				A[j+1]=A[j];
				j--;
			}
			A[j+1]=temp;
			i++;
		}
		return A;
	}
};

int main()
{
	int arr[]={54,35,48,36,27,12,44,44,8,14,26,17,28};
	InsertionSort a;
	a.insertionSort(arr,13);
	for(int i=0;i<13;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
