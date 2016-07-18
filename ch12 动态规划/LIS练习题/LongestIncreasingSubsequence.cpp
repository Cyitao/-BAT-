#include<iostream>
#include<vector>
using namespace std;
class LongestIncreasingSubsequence {
public:
	int getLIS(vector<int> A, int n) 
	{
		int *dp=new int[n],res=0;
		dp[0]=1;
		for(int i=1;i<A.size();i++)
		{
			int max=0,j=0;
			while(j<i)
			{
				if(A[j]<A[i]&&dp[j]>max)
					max=dp[j];
				j++;
			}
			dp[i]=max+1;
		}
		for(int i=0;i<A.size();i++)
			if(res<dp[i])
				res=dp[i];
		return res;
	}
};