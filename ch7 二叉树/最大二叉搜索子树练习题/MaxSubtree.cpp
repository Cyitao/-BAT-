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
class MaxSubtree 
{
public:
	TreeNode* getMax(TreeNode* root) 
	{
		int Num=0,Min,Max;
		TreeNode *temp=NULL;
		PostOrder_GetMax(root,Num,Min,Max,temp);
		return temp;
	}
	void PostOrder_GetMax(TreeNode* root,int &NumofNode,int &MinValue,int &MaxValue,TreeNode* &pRoot)
	{
		if(!root)
		{
			pRoot=NULL;
			return;
		}
		int lNumofNode,lMin,lMax,rNumofNode,rMin,rMax;
		TreeNode *lpRoot=NULL,*rpRoot=NULL;
		lMin=lMax=rMin=rMax=(*root).val;
		lNumofNode=rNumofNode=0;
		PostOrder_GetMax((*root).left,lNumofNode,lMin,lMax,lpRoot);
		PostOrder_GetMax((*root).right,rNumofNode,rMin,rMax,rpRoot);
		if(lpRoot==(*root).left&&rpRoot==(*root).right&&(*root).val>=lMax&&(*root).val<=rMin)
		{
			pRoot=root;
			NumofNode=lNumofNode+rNumofNode+1;
			MinValue=lMin;
			MaxValue=rMax;
			return;
		}
		else
		{
			if(lNumofNode>rNumofNode||((lNumofNode==rNumofNode)&&(*lpRoot).val>(*rpRoot).val))
			{
				pRoot=lpRoot;
				NumofNode=lNumofNode;
				MinValue=lMin;
				MaxValue=lMax;
				return;
			}
			pRoot=rpRoot;
			NumofNode=rNumofNode;
			MinValue=rMin;
			MaxValue=rMax;
		}
		return;
	}
};

int main()
{
	return 0;
}