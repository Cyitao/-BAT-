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
class FoldPaper {
public:
    vector<string> foldPaper(int n) 
	{
		vector<string> res;
		if(!n)
			return res;
		ReInOrder(n-1,1,res);
		res.push_back("down");
		ReInOrder(n-1,0,res);
		return res;
    }
	void ReInOrder(int n,int flag,vector<string> &res)//flag=0×ó
	{
		if(!n)
			return;
		ReInOrder(n-1,1,res);
		if(flag)
			res.push_back("down");
		else
			res.push_back("up");
		ReInOrder(n-1,0,res);
	}
};


int main()
{
	FoldPaper f;
	vector<string> res=f.foldPaper(5);
	for(vector<string>::iterator iter=res.begin();iter!=res.end();iter++)
		cout<<*iter<<endl;
	return 0;
}