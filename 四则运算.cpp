#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<cctype>
using namespace std;
bool Is_LeftOfBrackets(char c)
{
	bool res=false;
	if(c=='('||c=='['||c=='{')
		res=true;
	return res;
}

bool Is_RightOfBrackets(char c)
{
	bool res=false;
	if(c==')'||c==']'||c=='}')
		res=true;
	return res;
}
bool Is_PlusAndDivide(char c)
{
	bool res=false;
	if(c=='*'||c=='/')
		res=true;
	return res;
}
bool Is_AddAndMinus(char c)
{
	bool res=false;
	if(c=='+'||c=='-')
		res=true;
	return res;
}
char RightToLeft_Branket(char c)
{
	char res='(';
	if(c==']')
		res='[';
	if(c=='}')
		res='{';
	return res;
}
void InToPost(string str,vector<int> &data,vector<bool> &helper)
{
	int count=0;//两个数之间运算符的个数
	stack<char> sta;
	int len=str.length(),flag=1;
	for(int i=0;i<len;i++)
	{
		if((i==0&&str[i]=='-')||(count==1&&str[i]=='-'))
		{
			flag=-1;
			continue;
		}
		if(isdigit(str[i]))
		{
			int sum=0;
			while(isdigit(str[i]))
			{
				sum=sum*10+str[i]-'0';
				i++;
			}
			i--;
			count=0;
			data.push_back(sum*flag);
			flag=1;
			helper.push_back(true);//true为数，false为符号
		}
		else
		{
			if(sta.empty()||Is_LeftOfBrackets(str[i]))
				sta.push(str[i]);
			else if(Is_RightOfBrackets(str[i]))
			{
				char temp=RightToLeft_Branket(str[i]);
				while(sta.top()!=temp)
				{
					data.push_back(sta.top());
					helper.push_back(false);
					sta.pop();
				}
				sta.pop();
			}
			else if(Is_PlusAndDivide(str[i]))
			{
				count++;
				while(!sta.empty()&&Is_PlusAndDivide(sta.top()))
				{
					data.push_back(sta.top());
					helper.push_back(false);
					sta.pop();
				}
				sta.push(str[i]);
			}
			else
			{
				count++;
				while(!sta.empty()&&(Is_PlusAndDivide(sta.top())||Is_AddAndMinus(sta.top())))
				{
					data.push_back(sta.top());
					helper.push_back(false);
					sta.pop();
				}
				sta.push(str[i]);
			}
		}
	}
	while(!sta.empty())
	{
		data.push_back(sta.top());
		helper.push_back(false);
		sta.pop();
	}
}

int main()
{
	vector<int> data;
	vector<bool> helper;
	string str;
	while(cin>>str)
	{
		InToPost(str,data,helper);
		int len=data.size();
		stack<int> da;
		for(int i=0;i<len;i++)
		{
			if(helper[i]==true)
				da.push(data[i]);
			else
			{
				int t1=da.top();
				da.pop();
				int t2=da.top();
				da.pop();
				switch(data[i])
				{
				case 45:da.push(t2-t1);break;
				case 42:da.push(t2*t1);break;
				case 43:da.push(t2+t1);break;
				case 47:da.push(t2/t1);break;
				}
			}
		}
		cout<<da.top()<<endl;
		data.clear();
		helper.clear();
	}
	return 0;
}