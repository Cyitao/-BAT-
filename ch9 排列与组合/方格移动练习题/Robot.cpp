#include<iostream>
#include<vector>
using namespace std;
class Robot {
public:
	int countWays(int x, int y) 
	{
		return zuhe(x+y-2,x-1);

	}
	int zuhe(int m,int n)
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