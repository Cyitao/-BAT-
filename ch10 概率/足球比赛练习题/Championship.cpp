#include<iostream>
#include<vector>
using namespace std;
#define Mod 1000000007
class Championship {
public:
	vector<int> calc(int k) 
	{
		vector<int> res;
		int up=1,down=1,i=2*k-1;
		while(i>0)
		{
			down*=i;
			i=i-2;
		}
		i=k+1;
		while(i>2)
		{
			up*=i;
			i--;
		}
		int Com=gcd(down-up,down);
		res.push_back((down-up)/Com);
		res.push_back(down/Com);
		return res;
	}
	int gcd(int x, int y)
	{
		return (!y)?x:gcd(y,x%y);
	}
};
