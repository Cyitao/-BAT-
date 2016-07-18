#include<iostream>
#include<vector>
using namespace std;
#define Mod 1000000007
class CombineByMistake {
public:
	int countWays(int n) 
	{
		if(n==0||n==1)
			return 0;
		if(n==2)
			return 1;
		int pre=0,last=1,i,temp;
		for(i=3,temp=0;i<=n;i++)
		{
			temp=(long long)(i-1)*(long long)(last+pre)%Mod;
			pre=last;
			last=temp;
		}
		return last;
	}
};