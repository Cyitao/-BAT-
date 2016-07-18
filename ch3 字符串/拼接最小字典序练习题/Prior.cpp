#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Prior {
public:
    string findSmallest(vector<string> strs, int n) 
	{
		QuickSort(strs,0,n-1);
		string res;
		for(int i=0;i<n;i++)
			res+=strs[i];
		return res;
    }
	void QuickSort(vector<string> &strs,int low,int high)
	{
		if(low<high)
		{
			int res=Partition(strs,low,high);
			QuickSort(strs,low,res-1);
			QuickSort(strs,res+1,high);
		}
	}
	int Partition(vector<string> &strs,int low,int high)
	{
		string key=strs[low];
		while(low<high)
		{
			while(low<high&&LT(key,strs[high]))
				high--;
			strs[low]=strs[high];
			while(low<high&&LT(strs[low],key))
				low++;
			strs[high]=strs[low];
		}
		strs[low]=key;
		return low;
	}
	bool LT(string s1,string s2)
	//s1Ð¡·µ»Øture
	{
		string temp1=s1+s2,temp2=s2+s1;
		if(temp1<=temp2)
			return true;
		else
			return false;
	}
};
int main()
{
	string a("abc"),b("de"),c("cab");
	vector<string> arr;
	arr.push_back(b);
	arr.push_back(a);
	arr.push_back(c);
	Prior A;
	string res=A.findSmallest(arr,3);
	cout<<res;
	return 0;
}