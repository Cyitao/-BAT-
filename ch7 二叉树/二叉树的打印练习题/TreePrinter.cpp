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
class TreePrinter {
public:
    vector<vector<int> > printTree(TreeNode* root) 
	{
		vector<vector<int> >res;
		if(!root)
			return res;
		TreeNode *last=root,*nlast=NULL,*now=NULL;
		vector<int> temp;
		queue<TreeNode*> que;
		que.push(root);
		while(!que.empty())
		{
			now=que.front();
			que.pop();
			if((*now).left)
			{
				que.push((*now).left);
				nlast=(*now).left;
			}
			if((*now).right)
			{
				que.push((*now).right);
				nlast=(*now).right;
			}
			temp.push_back((*now).val);
			if(now==last)
			{
				res.push_back(temp);
				temp.clear();
				last=nlast;
			}
		}
		return res;
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
	string str="1!2!4!#!#!5!#!#!3!6!#!#!7!#!#!";
	StringToTree s;
	TreeNode* root=s.toTree(str);
	TreePrinter t;
	vector<vector<int> >res=t.printTree(root);
	for(vector<vector<int> >::iterator iter1=res.begin();iter1!=res.end();iter1++)
	{
		for(vector<int>::iterator iter2=(*iter1).begin();iter2!=(*iter1).end();iter2++)
			cout<<*iter2<<"  ";
	    cout<<endl;
	}
	return 0;
}