#include<iostream>
#include<string>
#include<stack>//pop,top,push
#include<vector>
using namespace std;
class LeftMostAppearance 
{
public:
    int findPos(vector<int> arr, int n, int num) 
	{
		if(!n)
			return -1;
		int low=0,high=n-1,mid;
		int res=-1;
		while(low<=high)
		{
			mid=low+(high-low)/2;
			if(arr[mid]<num)
				low=mid+1;
			else if(arr[mid]>num)
				high=mid-1;
			else
			{
				res=mid;
				high=mid-1;
			}
		}
		return res;
    }
};
int main()
{
	int a[5]={1,2,3,3,4};
	vector<int> arr(a,a+5);
	LeftMostAppearance s;
	cout<<s.findPos(arr,5,3);
	return 0;
}