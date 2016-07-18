#include<iostream>
#include<string>
#include<stack>//pop,top,push
#include<vector>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Remove {
public:
    bool removeNode(ListNode* pNode) 
	{
		if((*pNode).next==NULL)
			return false;
		ListNode *p=(*pNode).next,*pre=pNode;
		while((*p).next!=NULL)
		{
			(*pre).val=(*p).val;
			pre=p;
			p=(*p).next;
		}
		(*pre).val=(*p).val;
		(*pre).next=NULL;
		delete p;
		p=NULL;
		return true;
    }
};
int main()
{
	
	return 0;
}