#include<iostream>
#include<vector>
using namespace std;
class LCS {
public:
	int findLCS(string A, int n, string B, int m) 
	{
		int **dp=new int*[n];
		for(int i=0;i<n;i++)
			dp[i]=new int[m];
		for(int i=0,temp=0;i<n;i++)
		{
			if(B[0]==A[i])
				temp=1;
			dp[i][0]=temp;
		}
		for(int i=0,temp=0;i<m;i++)
		{
			if(A[0]==B[i])
				temp=1;
			dp[0][i]=temp;
		}
		for(int i=1;i<n;i++)
			for(int j=1;j<m;j++)
			{
				int m=max(dp[i-1][j],dp[i][j-1]);
				if(A[i]==B[j])
					m=max(dp[i-1][j-1]+1,m);
				dp[i][j]=m;
			}
			return dp[n-1][m-1];
	}
};

int main()
{
	string A="1A2C3D4B56",B="B1D23CA45B6A";
	LCS f;
	cout<<f.findLCS(A,10,B,12);
	return 0;
}