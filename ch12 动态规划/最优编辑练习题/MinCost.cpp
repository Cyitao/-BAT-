#include<iostream>
#include<vector>
using namespace std;
class MinCost {
public:
	int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2) //c0²åÈë£¬c1É¾³ı£¬c2Ìæ»»
	{
		int **dp=new int*[n+1];
		for(int i=0;i<n+1;i++)
			dp[i]=new int[m+1];
		for(int i=0;i<n+1;i++)
			dp[i][0]=i*c1;
		for(int i=0;i<m+1;i++)
			dp[0][i]=i*c0;
		for(int i=1;i<n+1;i++)
			for(int j=1;j<m+1;j++)
			{
				int temp1=0,temp2=0,res;
				temp1=min(dp[i][j-1]+c0,dp[i-1][j]+c1);
				if(A[i-1]==B[j-1])
					temp2=dp[i-1][j-1];
				else
					temp2=dp[i-1][j-1]+c2;
				res=min(temp1,temp2);
				dp[i][j]=res;
			}
			return dp[n][m];
	}
};