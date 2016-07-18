#include<iostream>
using namespace std;
class QuickSort {
public:
    int* quickSort(int* A, int n)
	//快速排序
	{
		QSort(A,0,n-1);
		return A;
    }
	void QSort(int *A,int low,int high)
	//对数组A[low,...,high]
	{
		if(low<high)
		{
			int n;
			n=Partition(A,low,high);
			QSort(A,low,n-1);
			QSort(A,n+1,high);
		}
	}
	int Partition(int *A,int low,int high)
	//交换数组A[low,...,high]的记录，支点记录到位，并返回其所在位置，此时
	//在它之前（后）的记录均不大（小）于它
	{
		int key=A[low];
		while(low<high)
		{
			while(low<high&&A[high]>=key)
				high--;
			A[low]=A[high];
			while(low<high&&A[low]<=key)
				low++;
			A[high]=A[low];
		}
		A[low]=key;
		return low;
	}
};

int main()
{
	int arr[]={54,35,48,36,27,12,44,44,8,14,26,17,28};
	QuickSort a;
	a.quickSort(arr,13);
	for(int i=0;i<13;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}