#include<iostream>
#include<vector>
using namespace std;
class StandInLine {
public:
	vector<int> getWays(int n, int a, int b) 
	{
		vector<int> res;
		res.push_back(pailie(n)/2);
		res.push_back(pailie(n-1));
		return res;

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