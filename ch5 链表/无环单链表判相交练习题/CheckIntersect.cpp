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
class CheckIntersect {
public:
    bool chkIntersect(ListNode* headA, ListNode* headB) 
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
};
int main()
{
	
	return 0;
}