#include<iostream>
#include<vector>
using namespace std;
class OddAppearance {
public:
	vector<int> findOdds(vector<int> arr, int n) 
	{
		vector<int> res;
		int check1=0;
		for(int i=0;i<n;i++)
			check1=check1^arr[i];
		int k=0,temp=check1;
		while(!(temp&1))
		{
			k++;
			temp>>=1;
		}
		int help=pow(2.0,k),check2=0;
		for(int i=0;i<n;i++)
			if(arr[i]&help)
				check2=check2^arr[i];
		check1=check1^check2;
		res.push_back(check1<check2?check1:check2);
		res.push_back(check1>check2?check1:check2);
		return res;
	}
};