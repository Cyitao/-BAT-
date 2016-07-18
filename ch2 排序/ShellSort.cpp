#include<iostream>
using namespace std;
class ShellSort 
{
public:
    int* shellSort(int* A, int n) 
	//Ï£¶ûÅÅÐò
	{
		int gap,i,j,temp;
		if(n==1)
			return A;
		for(gap=n/2;gap>0;gap/=2)
		{
			i=gap;
			while(i<n)
			{
				temp=A[i];
			    j=i-gap;
			    while(j>=0&&A[j]>temp)
				{
					A[j+gap]=A[j];
				    j=j-gap;
				}
			    A[j+gap]=temp;
			    i++;
			}
		}
		return A;
    }
};

int main()
{
	int arr[]={54,35,48,36,27,12,44,44,8,14,26,17,28};
	ShellSort a;
	a.shellSort(arr,13);
	for(int i=0;i<13;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}

