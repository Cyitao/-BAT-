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
class LongestDistance {
public:
    int findLongest(TreeNode* root)
	{
		vector<int> temp;
		temp=PostOrder_findLonges(root);
		return temp[0];
	}
	vector<int> PostOrder_findLonges(TreeNode *root)
	//res[0]:树最大距离，res[1]:树最远结点离树根距离。
	{
		vector<int> res(2,0);
		if(!root)
			return res;
		vector<int> ltemp,rtemp;
		int temp;
		ltemp=PostOrder_findLonges((*root).left);
		rtemp=PostOrder_findLonges((*root).right);
		res[1]=((ltemp[1]>rtemp[1])?ltemp[1]:rtemp[1])+1;
		temp=(ltemp[0]>rtemp[0])?ltemp[0]:rtemp[0];
		res[0]=((ltemp[1]+rtemp[1]+1)>temp)?(ltemp[1]+rtemp[1]+1):temp;
		return res;
	}
};

int main()
{
	return 0;
}