#include<iostream>
#include<vector>
using namespace std;
class OddAppearance {
public:
	int findOdd(vector<int> A, int n) 
	{
		int temp=0;
		for(int i=0;i<n;i++)
			temp=temp^A[i];
		return temp;
	}
};