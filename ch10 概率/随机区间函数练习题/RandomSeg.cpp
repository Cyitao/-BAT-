#include<iostream>
using namespace std;
class RandomSeg {
public:
	// 等概率返回[0,1)
	double f() {
		return rand() * 1.0 / RAND_MAX;
	}
	// 通过调用f()来实现
	double random(int k, double x) 
	{
		double res=-1;
		for(int i=0;i<k;i++)
		{
			double b=f();
			res=(res>b)?res:b;
		}
		return res;
	}
};