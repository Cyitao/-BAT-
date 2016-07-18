#include<iostream>
#include<vector>
using namespace std;
class Subsequence {
public:
    int shortestSubsequence(vector<int> A, int n) 
	{
		int max=A[0],min=A[n-1],i,rd1,rd2;
		for(i=1,rd1=0;i<n;i++)
		{
			if(A[i]>=max)
				max=A[i];
			else
				rd1=i;
		}
		for(i=n-2,rd2=n-1;i>=0;i--)
		{
			if(A[i]<=min)
				min=A[i];
			else
				rd2=i;
		}
		if(!rd1)
			return 0;
		else
			return rd1-rd2+1;
    }
};
int main()
{
	int a[6]={1,4,6,5,9,10};
	vector<int> b(a,a+6);
	Subsequence c;
	int d=c.shortestSubsequence(b,6);
	cout<<d<<endl;
	return 0;
}