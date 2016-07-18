#include<iostream>
#include<string>
#include<stack>//pop,top,push
#include<vector>
using namespace std;
class Find {
public:
    int findPos(vector<int> arr, int n) 
	{
        if(arr.empty()||arr[0]>n-1||arr[n-1]<0)
			return -1;
		int res=-1;
		int low=0,high=n-1,mid;
		while(low<=high)
		{
			mid=low+(high-low)/2;
			if(arr[mid]<mid)
				low=mid+1;
			else if(arr[mid]>mid)
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
	int a[5]={-1,0,2,3};
	vector<int> arr(a,a+4);
	Find s;
	cout<<s.findPos(arr,4);
	return 0;
}