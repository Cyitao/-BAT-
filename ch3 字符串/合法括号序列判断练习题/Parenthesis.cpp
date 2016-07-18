#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Parenthesis {
public:
    bool chkParenthesis(string A, int n) 
	{
		int number=0,i;
		for(i=0;i<n;i++)
		{
			if(A[i]=='(')
				number++;
			if(A[i]==')')
				number--;
			if(number<0)
				return false;
		}
		if(number==0)
			return true;
		else
			return false;
    }
};
int main()
{
	string arr(")a()()");
	Parenthesis A;
	bool c=A.chkParenthesis(arr,7);
	cout<<c;
	return 0;
}