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
        if(entry1!=NULL&&entry2!=NULL)
            return chkInter(head1,head2);
        if(entry1==NULL&&entry2==NULL)
            return chkIntersect(head1,head2);
        return false;
    }
    bool chkIntersect(ListNode* headA, ListNode* headB)
    //无环单链表判相交
    {
        if(!headA||!headB)
            return false;
        int NumofA=0,NumofB=0,count=0;
        ListNode *p=headA;
        while(p)
        {
            NumofA++;
            p=(*p).next;
        }
        p=headB;
        while(p)
        {
            NumofB++;
            p=(*p).next;
        }
        ListNode *L=NULL,*S=NULL;
        if(NumofA>NumofB)
            L=headA,S=headB;
        else
            L=headB,S=headA;
        count=(NumofA>NumofB)?(NumofA-NumofB):(NumofB-NumofA);
        while(count--)
            L=(*L).next;
        while(L&&S)
        {
            if(L==S)
                return true;
            L=(*L).next;
            S=(*S).next;
        }
        return false;
    }
    bool chkInter(ListNode* head1, ListNode* head2)
     //有环判相交
    {
        ListNode *entry1=chkLoop(head1),*entry2=chkLoop(head2);
        if(entry1==NULL||entry2==NULL)
            return false;
        if(entry1==entry2)
            return true;
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
    //链表判环
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