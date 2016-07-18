#include<iostream>
#include<string>
#include<stack>//pop,top,push
#include<vector>
#include<cmath>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
class CountNodes {
public:
    int count(TreeNode* root) 
	{
		if(!root)
			return 0;
		int Lengthofleft=DepthofCom_Bitree((*root).left);
		int Lengthofright=DepthofCom_Bitree((*root).right);
		if(Lengthofleft==Lengthofright)
			return pow(2.0,Lengthofleft)+count((*root).right);
		else
			return pow(2.0,Lengthofright)+count((*root).left);
    }
	int DepthofCom_Bitree(TreeNode *root)
	{
		if(!root)
			return 0;
		TreeNode *p=root;
		int len=0;
		while(p)
		{
			len++;
			p=(*p).left;
		}
		return len;
	}
};
int main()
{
	return 0;
}