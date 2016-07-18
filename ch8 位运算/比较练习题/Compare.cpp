#include<iostream>
#include<vector>
using namespace std;
class Compare {
public:
	int Flip(int c)
	{
		return c^1;

	}
	int GetSign(int c)
	//非负为1，负为0.
	{
		return Flip((c>>31)&1);
	}
	int getMax(int a, int b) 
	{
		int c=a-b;
		int as=GetSign(a);
		int bs=GetSign(b);
		int cs=GetSign(c);
		int sam=Flip(as^bs);
		if(sam)
			return cs?a:b;
		else
			return (as-bs)?a:b;
	}
};