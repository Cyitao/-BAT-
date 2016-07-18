#include<iostream>
#include<string>
#include<stack>//pop,top,push
using namespace std;
class Solution {
public:
	stack<int> soruce_data,min_data;
    void push(int value) 
	{
		soruce_data.push(value);
		if(min_data.empty()||min_data.top()>=value)
			min_data.push(value);
		else
			min_data.push(min_data.top());
    }
    void pop() 
	{
        soruce_data.pop();
		min_data.pop();
    }
    int top() 
	{
		return soruce_data.top();
    }
    int min() 
	{
		return min_data.top();
    }
};
int main()
{
	Solution A;
	A.push(3);
	A.push(4);
	A.push(5);
	int c=A.min();
	cout<<c;
	return 0;
}