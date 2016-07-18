#include<iostream>
#include<vector>
using namespace std;
class Distribution {
public:
	int getWays(int n, int m) 
	{
		return zuhe(n-1,m-1);
	}
	int zuhe(int m,int n)
	//n<=m
	{
		int A=1,B=1,i=0;
		while(i<n)
		{
			A*=(m-i);
			i++;
		}
		while(n)
		{
			B*=n--;
		}
		return (A/B);
	}
};