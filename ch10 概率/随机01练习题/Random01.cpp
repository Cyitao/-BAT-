#include<iostream>
#include<vector>
using namespace std;
class RandomP {
public:
	static int f();
};

class Random01 {
public:
	// 用RandomP::f()实现等概率的01返回
	int random01() 
	{
		int a,b;
		while(1)
		{
			a=RandomP::f();
			b=RandomP::f();
			if(a!=b)
				return (a>b)?0:1;
		}
	}
};