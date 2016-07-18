#include<iostream>
#include<string>
#include<stack>//pop,top,push
#include<vector>
using namespace std;
class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> numbers) 
	{
		stack<int> sta;
		for(vector<int>::reverse_iterator riter=numbers.rbegin();riter!=numbers.rend();riter++)
			sta.push(*riter);
		StackSort(sta);
		vector<int> res;
		while(!sta.empty())
		{
			res.push_back(sta.top());
			sta.pop();
		}
		return res;
    }
	void StackSort(stack<int> &sta)
	{
		stack<int> help;
		while(!sta.empty())
		{
			int res=sta.top();
			sta.pop();
			if(help.empty()||res<=help.top())
				help.push(res);
			else
			{
				while(!help.empty()&&res>help.top())
				{
					sta.push(help.top());
				    help.pop();
				}
				help.push(res);
			}
		}
		while(!help.empty())
		{
			sta.push(help.top());
			help.pop();
		}
	}
};
int main()
{
	int a[5]={1,2,3,4,5};
	TwoStacks A;
	vector<int> arr(a,a+5),res;
	res=A.twoStacksSort(arr);
	for(vector<int>::iterator iter=res.begin();iter!=res.end();iter++)
		cout<<*iter<<" ";
	return 0;
}