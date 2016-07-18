#include<iostream>
#include<string>
#include<stack>//pop,top,push
#include<vector>
using namespace std;
class MaxTree {
public:
    vector<int> buildMaxTree(vector<int> A, int n)
    {
        stack<int> sta;
        vector<int> left,res;
        int i;
        for(i=0;i<n;i++)
        {
			while(!sta.empty()&&A[sta.top()]<=A[i])
                    sta.pop();
            if(sta.empty())
				left.push_back(-1);
            else
				left.push_back(sta.top());
            sta.push(i);
        }
        stack<int> st;
        vector<int> right(n,0);
        for(i=n-1;i>=0;i--)
		{
			while(!st.empty()&&A[st.top()]<=A[i])
				st.pop();
            if(st.empty())
				right[i]=-1;
            else
				right[i]=st.top();
            st.push(i);
        }
        for(i=0;i<n;i++)
        {
            if(right[i]==-1&&left[i]==-1)
                res.push_back(-1);
            else if(right[i]==-1||left[i]==-1)
                res.push_back(right[i]>left[i]?right[i]:left[i]);
            else
            {
                if(A[right[i]]>A[left[i]])
                    res.push_back(left[i]);
                else
                    res.push_back(right[i]);
            }
        }
        return res;
    }
};
int main()
{
	int a[4]={3,1,4,2};
	MaxTree  A;
	vector<int> arr(a,a+4),res;
	res=A.buildMaxTree(arr,4);
	for(vector<int>::iterator iter=res.begin();iter!=res.end();iter++)
		cout<<*iter<<" ";
	return 0;
}