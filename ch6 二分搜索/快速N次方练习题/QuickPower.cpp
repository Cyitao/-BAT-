#include<iostream>
#include<string>
#include<bitset>//pop,top,push
#include<vector>
#include<cmath>
using namespace std;
class QuickPower 
{
public:
    int getPower(int k, int N)
	//(http://www.cnblogs.com/Knuth/archive/2009/09/04/1559949.html)
	{
		if(k==0)
			return 0;
		if(N==0)
			return 1;
		if(k>1000000007)
			k=k%1000000007;
		vector<long> arr;
		vector<int>  bit;
		long long  m=N,temp=k,res;
		while(m)
		{
			arr.push_back(temp);
			temp*=temp;
			if(temp>1000000007)
				temp=temp%1000000007;
			if(m%2)
				bit.push_back(1);
			else
				bit.push_back(0);
			m=m/2;
		}
		for(int i=0,res=1;i<bit.size();i++)
			if(bit[i])
			{
				res*=arr[i];
				if(res>1000000007)
					res=res%1000000007;
			}
		return res%(1000000007);
	}
};
int main()
{
	QuickPower s;
	cout<<s.getPower(2,14876069);
	return 0;
}