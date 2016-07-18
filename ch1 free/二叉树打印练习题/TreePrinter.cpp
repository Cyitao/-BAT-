#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
using namespace std;
vector<char>::size_type n=0;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL) 
	{
    }
};
class Serialize
{
public:
	void serialize(TreeNode* head,vector<char> &B)
	//先序序列化：B存放序列化结果
	{
		if(!head)
		{
			B.push_back('#');
			B.push_back('!');
			return;
		}
		int value=head->val;
		if(!value)
		{
			B.push_back('0');
			B.push_back('!');
			serialize(head->left,B);
			serialize(head->right,B);
			return;
		}
		int a=0;
		vector<int> A;
		while(value)
		{
			a=value%10;
			A.push_back(a);
			value/=10;
		}
		while(!A.empty())
		{
			a=A.back();
			A.pop_back();
			B.push_back('0'+a);
		}
		B.push_back('!');
		serialize(head->left,B);
		serialize(head->right,B);
		return;
	}

};
class DeSerialize
{
public:
	void deserialize(vector<char> A,TreeNode* & head)
	//先序反序列化:#空结点，！当前结点结束,n表示当前读的字符位置,A为输入原序列
	{
		int i,j,value=0;
		if((n>A.size()-1)||A[n]=='#')
			return;
		i=j=n;
		while(A[j]!='!')
				j++;
		while(j>i)
		{
			value=(A[i]-'0')+value*10;
		    i++;
		}
		head=(TreeNode*)malloc(sizeof(TreeNode));
		(*head).val=value;
		(*head).right=(*head).left=NULL;
		n=i+1;
		deserialize(A,(*head).left);
		deserialize(A,(*head).right);
	}

};

class TreePrinter {
public:
    vector<vector<int> > printTree(TreeNode* root) 
	{
		vector<vector<int> > res;
		vector<int> temp;
		queue<TreeNode*> que;
		que.push(root);
		TreeNode *last=root,*nlast=NULL,*Now=NULL;
		while(!que.empty())
		{
			Now=que.front();
			cout<<Now->val;
			temp.push_back(Now->val);
			if(Now->left)
			{
				que.push(Now->left);
				nlast=Now->left;
			}
			if(Now->right)
			{
				que.push(Now->right);
				nlast=Now->right;
			}
			if(Now==last)
			{
				res.push_back(temp);
				temp.clear();
				cout<<endl;
				last=nlast;
			}
			que.pop();

		}
		return res;
    }
};
int main()
{
	char a[11]={'1','2','!','3','!','#','!','#','!','#','!'};
	vector<char> sor(a,a+11);
	DeSerialize b;
	TreeNode* T=NULL;
	b.deserialize(sor,T);
	Serialize c;
	vector<char> res;
	c.serialize(T,res);
	for(int i=0;i!=res.size();i++)
		cout<<res[i]<<" ";
	cout<<endl;
	vector<vector<int> > res1;
	TreePrinter d;
	res1=d.printTree(T);
	for(vector<vector<int> >::iterator iter1=res1.begin();iter1!=res1.end();iter1++)
	{
		for(vector<int>::iterator iter2=(*iter1).begin();iter2!=(*iter1).end();iter2++)
			cout<<*iter2<<" ";
		cout<<endl;
	}
	return 0;
}