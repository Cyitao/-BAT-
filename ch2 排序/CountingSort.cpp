#include<iostream>
#include<cstdlib>
using namespace std;
class CountingSort {
public:
    int* countingSort(int* A, int n)
	//¼ÆÊýÅÅÐò
	{
        int i,j,min,max;
		for(i=1,min=max=A[0];i<n;i++)
		{
			if(A[i]<=min)
				min=A[i];
			if(A[i]>max)
				max=A[i];
		}
		int *counts=(int *)calloc(max-min+1,sizeof(int));
		if(!counts)
			exit(-1);
		for(i=0;i<n;i++)
			counts[A[i]-min]++;
		for(i=0,j=0;i<max-min+1;i++)
			while(counts[i])
			{
				A[j]=i+min;
				counts[i]--;
				j++;
			}
		free(counts);
		counts=NULL;
		return A;
		
    }
};
int main()
{
	int arr[]={54,35,48,36,27,12,44,44,8,14,26,17,28};
	CountingSort a;
	a.countingSort(arr,13);
	for(int i=0;i<13;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}