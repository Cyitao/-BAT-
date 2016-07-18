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
class ChkIntersection {
public:
    bool chkInter(ListNode* head1, ListNode* head2, int adjust0, int adjust1) 
    {
        ListNode *entry1=chkLoop(head1),*entry2=chkLoop(head2);
        if(entry1==NULL||entry2==NULL)
            return false;
        if(entry1==entry2)
        {
            /*int Numof1=0,Numof2=0,count=0;//注释为返回第一个相交结点
            ListNode *p=head1;
            while(p!=entry1)
            {
                Numof1++;
                p=(*p).next;
            }
            p=head2;
            while(p!=entry1)
            {
                Numof2++;
                p=(*p).next;
            }
            ListNode *L=NULL,*S=NULL;
            if(Numof1>Numof2)
                L=head1,S=head2;
            else
                L=head2,S=head1;
            count=(Numof1>Numof2)?(Numof1-Numof2):(Numof2-Numof1);
            while(count--)
                L=(*L).next;
            while(L!=entry1&&S!=entry2)
            {
                if(L==S)
                    break;
                L=(*L).next;
                S=(*S).next;
            }
            return L;*/
            return true;
        }
        else
        {
            ListNode *p=(*entry1).next;
            while(p!=entry1)
            {
                if(p==entry2)
                    return true;
                p=(*p).next;
            }
            return false;
        }
    }
    ListNode* chkLoop(ListNode* head)
    {
        if(!head)
            return NULL;
        ListNode *slow=head,*fast=head;
        while(((*fast).next&&(*(*fast).next).next))
        {
            slow=(*slow).next;
            fast=(*(*fast).next).next;
			if(slow==fast)
				break;
        }
        if(!(*fast).next||!(*(*fast).next).next)
            return NULL;
        slow=head;
        while(slow!=fast)
        {
            slow=(*slow).next;
            fast=(*fast).next;
        }
        return fast;
    }
};
int main()
{
	
	return 0;
}