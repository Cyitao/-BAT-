#include<iostream>
#include<string>
#include<stack>//pop,top,push
#include<vector>
using namespace std;
class MinValue {
public:
    int getMin(vector<int> arr, int n) 
	{
        if(arr.empty())
            exit(-1);
        if(n==1||arr[0]<arr[n-1])
			return arr[0];
		int low=0,high=n-1,mid;
		while(low<high)
		{
			mid=low+(high-low)/2;
			if(arr[low]>arr[mid])
				high=mid;
			else if(arr[mid]>arr[high])
				low=mid+1;
			else
				break;
		}
		if(low==high)
			return arr[low];
		int min=arr[low];
		while(low<=high)
		{
			if(arr[low]<min)
				min=arr[low];
			low++;
		}
		return min;
    }
};
int main()
{
	int a[5]={4,1,2,3,3};
	vector<int> arr(a,a+5);
	MinValue s;
	cout<<s.getMin(arr,5);
	return 0;
}