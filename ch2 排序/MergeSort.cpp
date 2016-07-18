#include<iostream>
using namespace std;
class MergeSort {
public:
    int* mergeSort(int* A, int n)
	//归并排序
	{
        Msort(A,A,0,n-1);
		return A;
    }
	void Msort(int *A,int *B,int s,int t)
	//将A[s,...,t]归并排序为B[s,...,t]
	{
		if(s==t)
			B[s]=A[s];
		else
		{
			int m=(s+t)/2;
			int C[100]={0};
			Msort(A,C,s,m);
			Msort(A,C,m+1,t);
			Merge(C,B,s,m,t);
		}
	}
	void Merge(int *A,int *B,int i,int m,int n)
	//将有序的A[i,...,m]和A[m+1，...,n]归并为有序的B[i,...,n]
	{
		int j,k;
		for(j=m+1,k=i;i<=m&&j<=n;k++)
		{
			if(A[i]<A[j])
				B[k]=A[i++];
			else
				B[k]=A[j++];
		}
		if(i<=m)
			while(i<=m)
				B[k++]=A[i++];
		if(j<=n)
			while(j<=n)
				B[k++]=A[j++];
	}
};

int main()
{
	int arr[]={54,35,48,36,27,12,44,44,8,14,26,17,28};
	MergeSort a;
	a.mergeSort(arr,13);
	for(int i=0;i<13;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
