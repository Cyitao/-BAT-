#include<iostream>
#include<string>
#include<stack>//pop,top,push
#include<vector>
using namespace std;
class StackReverse {
public:
    vector<int> reverseStack(vector<int> A, int n) 
    {
        stack<int> sta;
        int i;
        for(i=n-1;i>=0;i--)
            sta.push(A[i]);
        revStack(sta);
        vector<int> res;
        while(!sta.empty())
        {
            res.push_back(sta.top());
            sta.pop();
        }
        return res;
        
    }
    void revStack(stack<int> &A)
    {
        if(A.empty())
            return;
        int res1=Get(A);
        revStack(A);
        A.push(res1);
    }
    int Get(stack<int> &A)
     //ÒÆ³ýÕ»µ×ÔªËØ£¬²¢·µ»Ø
    {
        if(A.empty())
            exit(-1);
        int res1=A.top();
        A.pop();
        if(A.empty())
            return res1;
        else
        {
            int res2=Get(A);
            A.push(res1);
            return res2;
        }
    }
};
int main()
{
	int a[4]={4,3,2,1};
	vector<int> arr(a,a+4),res;
	StackReverse A;
	res=A.reverseStack(arr,4);
	for(vector<int>::iterator iter=res.begin();iter!=res.end();iter++)
		cout<<*iter<<" ";
	return 0;
}