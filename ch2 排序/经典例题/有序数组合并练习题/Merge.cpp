#include<iostream>
#include<vector>
using namespace std;
class Merge {
public:
    int* mergeAB(int* A, int* B, int n, int m) 
	{
        int i,j,NewLength=m+n;
		for(i=n-1,j=m-1;i>=0&&j>=0;NewLength--)
		{
			if(B[j]<=A[i])
				A[NewLength-1]=A[i--];
			else
				A[NewLength-1]=B[j--];
		}
		while(j>=0)
		{
			A[NewLength-1]=B[j--];
			NewLength--;
		}
		return A;
    }
};
int main()
{
	int a[10]={1,3,7,8};
	int b[]={0,2,5,9};
	Merge c;
	c.mergeAB(a,b,4,4);
	for(int i=0;i<8;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}