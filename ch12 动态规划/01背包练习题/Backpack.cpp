#include<iostream>
#include<vector>
using namespace std;
class Backpack {
public:
	int maxValue(vector<int> w, vector<int> v, int n, int cap) 
	{
		int **dp=new int*[n+1];
		for(int i=0;i<n+1;i++)
			dp[i]=new int[cap+1];
		for(int i=0;i<n+1;i++)
			dp[i][0]=0;
		for(int i=0;i<cap+1;i++)
			dp[0][i]=0;
		for(int i=1;i<n+1;i++)
			for(int j=1;j<cap+1;j++)
			{
				int temp=dp[i-1][j];
				if(j-w[i-1]>=0)
					temp=max(temp,dp[i-1][j-w[i-1]]+v[i-1]);
				dp[i][j]=temp;
			}
			return dp[n][cap];
	}
};

int main()
{
	int a[8]={42,25,30,35,42,21,26,28};
	int b[8]={261,247,419,133,391,456,374,591};
	vector<int> arr(a,a+8);
	vector<int> brr(b,b+8);
	Backpack B;
	cout<<B.maxValue(arr,brr,8,297);
	return 0;
}