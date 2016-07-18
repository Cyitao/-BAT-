#include<iostream>
#include<vector>
#include<string>
#include<queue>
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
		arr.push_back((*root).val);
		PreOrderTraverse((*root).left,arr);
		PreOrderTraverse((*root).right,arr);
	}
	void InOrderTraverse(TreeNode* root,vector<int> &arr)
	{
		if(!root)
			return;
		InOrderTraverse((*root).left,arr);
		arr.push_back((*root).val);
		InOrderTraverse((*root).right,arr);
	}
	void PostOrderTraverse(TreeNode* root,vector<int> &arr)
	{
		if(!root)
			return;
		PostOrderTraverse((*root).left,arr);
		PostOrderTraverse((*root).right,arr);
		arr.push_back((*root).val);
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