#include<iostream>
using namespace std;
class HeapSort {
public:
    int* heapSort(int* A, int n)
	//堆排序
    {
		int i,temp;
		for(i=n/2-1;i>=0;--i)
			HeapAdjust(A,i,n-1);
		for(i=n-1;i>0;i--)
		{
			temp=A[0];
			A[0]=A[i];
			A[i]=temp;
			HeapAdjust(A,0,i-1);
		}
		return A;

    }
	void HeapAdjust(int *A,int s,int m)
	//已知A[s,...,m]中记录的关键字除A[s]之外均满足堆的定义，本函数调整A[s]
    //的关键字，使A[s,...,m]成为一个大顶堆(对其中记录的关键字而言)
	{
		int j,rc=A[s];
		for(j=2*s+1;j<=m;j=2*j+1)
		{
			if(j<m&&A[j]<A[j+1])
				j++;
			if(rc>A[j])
				break;
			A[s]=A[j];
			s=j;
		}
		A[s]=rc;
	}
};
int main()
{
	int arr[]={54,35,48,36,27,12,44,44,8,14,26,17,28};
	HeapSort a;
	a.heapSort(arr,13);
	for(int i=0;i<13;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}