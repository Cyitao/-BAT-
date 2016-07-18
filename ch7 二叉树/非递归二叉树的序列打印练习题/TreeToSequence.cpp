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
class TreeToSequence {
public:
    vector<vector<int> > convert(TreeNode* root) 
	{
		vector<vector<int>> res;
		vector<int> temp;
		PreOrderTraverse(root,temp);
		res.push_back(temp);
		temp.clear();
		InOrderTraverse(root,temp);
		res.push_back(temp);
		temp.clear();
		PostOrderTraverse(root,temp);
		res.push_back(temp);
		return res;

    }
	void PreOrderTraverse(TreeNode* root,vector<int> &arr)
	{
		if(!root)
			return;
		stack<TreeNode *> temp;
		TreeNode *p=NULL;
		temp.push(root);
		while(!temp.empty())
		{
			p=temp.top();
			arr.push_back((*p).val);
			temp.pop();
			if((*p).right)
				temp.push((*p).right);
			if((*p).left)
				temp.push((*p).left);
		}
	}
	void InOrderTraverse(TreeNode* root,vector<int> &arr)
	{
		if(!root)
			return;
		stack<TreeNode *> temp;
		TreeNode *p=root;
		while(!temp.empty()||p)
		{
			while(p)
			{
				temp.push(p);
				p=(*p).left;
			}
			p=temp.top();
			temp.pop();
			arr.push_back((*p).val);
			p=(*p).right;
		}
	}
	void PostOrderTraverse(TreeNode* root,vector<int> &arr)
	{
		if(!root)
			return;
		/*//方案一：使用两个栈，s1、s2.
		stack<TreeNode *>s1,s2;
		s1.push(root);
		TreeNode *p=NULL;
		while(!s1.empty())
		{
			p=s1.top();
			s1.pop();
			s2.push(p);
			if((*p).left)
				s1.push((*p).left);
			if((*p).right)
				s1.push((*p).right);
		}
		while(!s2.empty())
		{
			arr.push_back((*s2.top()).val);
			s2.pop();
		}*/
		//方案二：使用一个栈。
		stack<TreeNode *> s;
		TreeNode *h=root,*c=NULL,*p=NULL;
		s.push(root);
		while(!s.empty())
		{
			c=s.top();
			if((*c).left&&h!=(*c).left&&h!=(*c).right)
				s.push((*c).left);
			else if((*c).right&&h!=(*c).right)
				s.push((*c).right);
			else
			{
				p=s.top();
				arr.push_back((*p).val);
				h=p;
				s.pop();
			}
		}
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
	//!做为结束符
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
	TreeToSequence t;
	vector<vector<int> >res=t.convert(root);
	for(vector<vector<int> >::iterator iter1=res.begin();iter1!=res.end();iter1++)
	{
		for(vector<int>::iterator iter2=(*iter1).begin();iter2!=(*iter1).end();iter2++)
			cout<<*iter2<<"  ";
	    cout<<endl;
	}
	return 0;
}