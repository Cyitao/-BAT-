#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class IdenticalTree {
public:
    bool chkIdentical(TreeNode* A, TreeNode* B)
	{
		string s1=toString(A),s2=toString(B);
		if(s1.find(s2)!=string::npos)
			return true;
		else
			return false;
    }
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
