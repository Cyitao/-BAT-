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
class FindErrorNode {
public:
    vector<int> findError(TreeNode* root) 
	{
		vector<int> res(2,0);
		vector<vector<int> >t;
		int last=INT_MIN,now=0;
		stack<TreeNode *> sta;
		TreeNode *p=root,*temp=NULL;
		while(!sta.empty()||p)
		{
			while(p)
			{
				sta.push(p);
				p=(*p).left;
			}
			temp=sta.top();
			sta.pop();
			now=(*temp).val;
			if(last>now)
			{
				res[1]=last;
				res[0]=now;
				t.push_back(res);
			}
			last=now;
			p=(*temp).right;
		}
		if(t.size()!=1)
		{
			res[1]=t[0][1];
			res[0]=t[1][0];
		}
		return res;
    }
};


int main()
{
	return 0;
}