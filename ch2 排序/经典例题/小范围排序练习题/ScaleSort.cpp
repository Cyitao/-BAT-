#include<iostream>
#include<vector>
using namespace std;
class ScaleSort {
public:
    vector<int> sortElement(vector<int> &A, int n, int k) 
	{
		vector<int> B(n,0);
		int i,j;
		for(i=k/2-1;i>=0;--i)
			HeapAdjust(A,i,k-1);
		B[0]=A[0];
		for(i=1,j=k;j<n;j++)
		{
			A[0]=A[j];
			HeapAdjust(A,0,k-1);
			B[i++]=A[0];
		}
		heapSort(A,k);
		for(i=0,j=n-1;i<k;j--,i++)
			A[j]=A[i];
		for(i=0;i<n-k;i++)
			A[i]=B[i];
		return A;
	}
	void heapSort(vector<int> &A, int n)
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

    }
	void HeapAdjust(vector<int> &A,int s,int m)
	//已知A[s,...,m]中记录的关键字除A[s]之外均满足堆的定义，本函数调整A[s]
    //的关键字，使A[s,...,m]成为一个小顶堆(对其中记录的关键字而言)
	{
		int j,rc=A[s];
		for(j=2*s+1;j<=m;j=2*j+1)
		{
			if(j<m&&A[j]>A[j+1])
				j++;
			if(rc<A[j])
				break;
			A[s]=A[j];
			s=j;
		}
		A[s]=rc;
	}
};

int main()
{
	int b[]={2,1,4,3,6,5,8,7,10,9};
	vector<int> arr(b,b+10);
	ScaleSort a;
	a.sortElement(arr,10,2);
	for(int i=0;i<10;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}