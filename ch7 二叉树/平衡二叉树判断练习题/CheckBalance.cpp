#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
class CheckBalance {
public:
    bool check(TreeNode* root) 
    {
		int Depth=0;
		return IsBalance(root,Depth);
    }
	bool IsBalance(TreeNode *root,int &Depth)
	{
		if(root==NULL)
		{
			Depth=0;
			return true;
		}
		int left=0,right=0,differ=0;
		if(IsBalance((*root).left,left)&&IsBalance((*root).right,right))
		{
			differ=left-right;
            Depth=(left>right?left:right)+1;
			if(differ<=1&&differ>=-1)
				return true;
		}
		return false;
	}
};

class TreeToString {
public:
    string toString(TreeNode* root) 
	{
		string res;
		Serialize(root,res);
		return res;
	}
	void Serialize(TreeNode* root,string &res)
	{
		if(!root)
		{
			res+="#!";
			return;
		}
		res+=IntegertoStr((*root).val);
		Serialize((*root).left,res);
		Serialize((*root).right,res);
	}
	string IntegertoStr(int m)
	//!×öÎª½áÊø·û
	{
		if(!m)
			return "0!";
		string res;
		vector<int> temp;
		while(m)
		{
			temp.push_back(m%10);
			m=m/10;
		}
		for(vector<int>::reverse_iterator riter=temp.rbegin();riter!=temp.rend();riter++)
			res.push_back(*riter+48);
		res.push_back('!');
		return res;
	}
};

class StringToTree
{
public:
	TreeNode* toTree(string str)
	{
		queue<int> res;
		TreeNode* root=NULL;
		res=StrtoInteger(str);
		Deserialize(root,res);
		return root;
	}
	void Deserialize(TreeNode* &root,queue<int> &res)
	{
		if(res.front()==INT_MIN)
		{
			res.pop();
			return;
		}
		root=new TreeNode(res.front());
		res.pop();
		Deserialize((*root).left,res);
		Deserialize((*root).right,res);
	}
	queue<int> StrtoInteger(string str)
	{
		int i=0,j=0,temp=0;
		queue<int> res;
		while(i<str.length())
		{
			if(str[i]=='#')
			{
				res.push(INT_MIN);
				i=i+2;
				continue;
			}
			j=i;
			while(str[i]!='!')
				i++;
			while(j!=i)
			{
				temp=(str[j]-'0')+temp*10;
				j++;
			}
			res.push(temp);
			temp=0;
			i++;
		}
		return res;
	}
};

int main()
{
	string str="1!#!3!4!#!#!#!";
	StringToTree s;
	TreeNode* root=s.toTree(str);
	CheckBalance t;
	cout<<t.check(root);
	return 0;
}