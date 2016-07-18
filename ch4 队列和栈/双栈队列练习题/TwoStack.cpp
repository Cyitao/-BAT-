#include<iostream>
#include<string>
#include<stack>//pop,top,push
#include<vector>
using namespace std;
class TwoStack {
public:
    stack<int> stack_push,stack_pop;
    vector<int> twoStack(vector<int> ope, int n) 
    {
		vector<int> res;
		int i;
		for(i=0;i<n;i++)
		{
			if(ope[i]>0)
				push(ope[i]);
			if(ope[i]==0)
				res.push_back(pop());
			if(ope[i]<0)
				exit(-1);
		}
		return res;
    }
    void push(int value)
    {
        stack_push.push(value);
    }
	int pop()
	{
		if(stack_pop.empty())
			while(!stack_push.empty())
			{
				stack_pop.push(stack_push.top());
				stack_push.pop();
			}
			int res=stack_pop.top();
			stack_pop.pop();
			return res;
	}
	
};
int main()
{
	int a[6]={1,2,3,0,4,0};
	vector<int> arr(a,a+6);
	TwoStack A;
	vector<int> res=A.twoStack(arr,6);
	for(vector<int>::iterator iter=res.begin();iter!=res.end();iter++)
		cout<<*iter<<" ";
	return 0;
}