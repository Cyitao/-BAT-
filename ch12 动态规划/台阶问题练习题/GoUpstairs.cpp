#include<iostream>
#include<vector>
using namespace std;
#define Mod 1000000007
class GoUpstairs {
public:
	int countWays(int n) 
	{
		int *dp=new int[n];
		dp[0]=1;
		dp[1]=2;
		for(int i=2;i<n;i++)
			dp[i]=(dp[i-1]+dp[i-2])%Mod;
		return dp[n-1];
	}
};