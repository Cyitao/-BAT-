#include<iostream>
#include<vector>
using namespace std;
class MinimumPath {
public:
	int getMin(vector<vector<int> > map, int n, int m) 
	{
		int **dp=new int *[n];
		for(int i=0;i<n;i++)
			dp[i]=new int[m];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				dp[i][j]=0;
		dp[0][0]=map[0][0];
		for(int i=1;i<n;i++)
			dp[i][0]=dp[i-1][0]+map[i][0];
		for(int i=1;i<m;i++)
			dp[0][i]=dp[0][i-1]+map[0][i];
		for(int i=1;i<n;i++)
			for(int j=1;j<m;j++)
				dp[i][j]=min(dp[i-1][j],dp[i][j-1])+map[i][j];
		return dp[n-1][m-1];
	}
};