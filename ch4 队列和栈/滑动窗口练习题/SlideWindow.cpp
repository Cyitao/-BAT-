#include<iostream>
#include<string>
#include<deque>//pop,top,push
#include<vector>
using namespace std;
class SlideWindow 
{
public:
    vector<int> slide(vector<int> arr, int n, int w) 
	{
		if(w==1)
			return arr;
        deque<int> deq;
		vector<int> res;
		int i;
		for(i=0;i<n;i++)
		{
			if(deq.empty()||arr[deq.back()]>arr[i])
				deq.push_back(i);
			else
			{
				while(!deq.empty()&&arr[deq.back()]<=arr[i])
					deq.pop_back();
				deq.push_back(i);
			}
			while((i-deq.front())>=w)
				deq.pop_front();
			if(i<w-1)
				continue;
			res.push_back(arr[deq.front()]);
		}
		return res;
    }
};
int main()
{
	int a[8]={4,3,5,4,3,3,6,7};
	SlideWindow  A;
	vector<int> arr(a,a+8),res;
	res=A.slide(arr,8,3);
	for(vector<int>::iterator iter=res.begin();iter!=res.end();iter++)
		cout<<*iter<<" ";
	return 0;
}