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
class ChkLoop {
public:
    int chkLoop(ListNode* head, int adjust)
    {
        if(!head)
            return -1;
        ListNode *slow=head,*fast=head;
        while(((*fast).next&&(*(*fast).next).next))
        {
            slow=(*slow).next;
            fast=(*(*fast).next).next;
			if(slow==fast)
				break;
        }
        if(!(*fast).next||!(*(*fast).next).next)
            return -1;
        slow=head;
        while(slow!=fast)
        {
            slow=(*slow).next;
            fast=(*fast).next;
        }
        return (*fast).val;
    }
};
int main()
{
	
	return 0;
}