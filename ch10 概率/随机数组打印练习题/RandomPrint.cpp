#include<iostream>
#include<vector>
using namespace std;
class RandomPrint {
public:
	vector<int> print(vector<int> arr, int N, int M) 
	{
		vector<int> res;
		for(int i=0;i<M;i++)
		{
			int pos=rand()%(N-i);
			res.push_back(arr[pos]);
			swap(arr[pos],arr[N-i-1]);
		}
		return res;
	}
};