#include<iostream>
#include<vector>
using namespace std;
class LonelyA {
public:
	int getWays(int n, int A, int b, int c)
	{
		int s1=pailie(n),s2=pailie(n-1),s3=pailie(n-2);
		return (s1-4*s2+2*s3);

	}
	int pailie(int m)
	{
		int res=1;
		while(m)
		{
			res*=m;
			m--;
		}
		return res;
	}
};