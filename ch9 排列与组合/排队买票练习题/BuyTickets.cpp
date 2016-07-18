#include<iostream>
#include<vector>
using namespace std;
class BuyTickets {
public:
	int countWays(int n) 
	{
		return zuhe(2*n,n)/(n+1);
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