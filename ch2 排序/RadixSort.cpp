#include<iostream>
using namespace std;
#define N 10
class RadixSort 
{
public:
    int* radixSort(int* A, int n,int radix)
	//基数排序:radix为关键字最高位数
	{
		int temp[10][N]={0},order[10]={0};
		int m=(int)pow((double)10,radix-1),base=1;
		while(base<=m)
		{
			int i,k;
			for(i=0;i<n;i++)
			{
				int lsd=(A[i]/base)%10;
				temp[lsd][order[lsd]]=A[i];
				order[lsd]++;
			}
			for(i=0,k=0;i<10;i++)
			{
				if(order[i])
				{
					int j;
					for(j=0;j<order[i];j++,k++)
						A[k]=temp[i][j];
				}
				order[i]=0;
			}
			base*=10;
		}
		return A;
    }
};
int main()
{
	int arr[]={5412,351,4821,362,127,12,441,414,8,1499,2226,5717,268};
	RadixSort a;
	a.radixSort(arr,13,4);
	for(int i=0;i<13;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}