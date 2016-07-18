#include<iostream>
#include<vector>
using namespace std;
#define Mod 1000000007
class Ants {
public:
	vector<int> collision(int n) 
	{
		int down=pow(2.0,n),up=down-2;
		int temp=gcd(up,down);
		vector<int> res;
		res.push_back(up/temp);
		res.push_back(down/temp);
		return res;
	}
	int gcd(int x,int y)
	{
		return (!y)?x:gcd(y,x%y);
	}
};