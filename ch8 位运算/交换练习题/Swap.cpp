#include<iostream>
#include<vector>
using namespace std;
class Swap {
public:
	vector<int> getSwap(vector<int> num) 
	{
		num[0]=num[0]^num[1];
		num[1]=num[0]^num[1];
		num[0]=num[0]^num[1];
		return num;
	}
};