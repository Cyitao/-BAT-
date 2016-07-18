#include<iostream>
#include<string>
#include<map>
using namespace std;
class DistinctSubstring {
public:
	int longestSubstring(string A, int n) 
	{
		map<char,int> map_table;
		int pre=0;
		int *dp=new int[n]();
		for(int i=0;i<n;i++)
		{
			if(map_table.count(A[i]))
			{
				if(map_table[A[i]]>=(i-pre))
					dp[i]=i-map_table[A[i]];
				else
					dp[i]=pre+1;
			}
			else
				dp[i]=pre+1;
			pre=dp[i];
			map_table[A[i]]=i;
		}
		int res=0;
		for(int i=1;i<n;i++)
			if(dp[i]>res)
				res=dp[i];
		delete []dp;
		dp=NULL;
		return res;
	}
};
int main()
{
	string s("aabcb");
	DistinctSubstring d;
	cout<<d.longestSubstring(s,5);
	return 0;
}