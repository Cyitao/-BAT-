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
class Palindrome {
public:
	bool isPalindrome(ListNode* pHead)
	{
		if(!pHead||!(*pHead).next)
			return true;
        ListNode *slow=pHead,*fast=pHead;
		int odd=0;
		while(fast->next&&fast->next->next)
		{
			fast=(*(*fast).next).next;
			slow=(*slow).next;
		}
		if(!fast->next)
			odd=1;
		ListNode *pre=slow,*now=(*pre).next,*temp=NULL;
		(*slow).next=NULL;
		while(now)
		{
			temp=(*now).next;
			(*now).next=pre;
			pre=now;
			now=temp;
		}
		bool res=true;
		ListNode *fwd=pHead,*tai=pre;
		while(tai!=slow)
		{
			if((*fwd).val!=(*tai).val)
			{
				res=false;
				break;
			}
			fwd=(*fwd).next;
			tai=(*tai).next;
		}
		now=pre;
		pre=(*pre).next;
		(*now).next=NULL;
		while(pre)
		{
			temp=(*pre).next;
			(*pre).next=now;
			now=pre;
			pre=temp;
		}
		return res;

	}
/*·½°¸Ò»£º	bool isPalindrome(ListNode* pHead) 
	{
		stack<ListNode *> res;
        ListNode *slow=pHead,*fast=pHead;
		int odd=0,even=odd;
		while(fast)
		{
			fast=(*fast).next;
			if(!fast)
			{
				odd=1;
				break;
			}
			fast=(*fast).next;
			if(!fast)
			{
				even=1;
				break;
			}
			res.push(slow);
			slow=(*slow).next;
		}
		if(odd)
			slow=(*slow).next;
		if(even)
		{
			res.push(slow);
			slow=(*slow).next;
		}
		while(slow)
		{
			if((*res.top()).val!=(*slow).val)
				return false;
			res.pop();
			slow=(*slow).next;
		}
		return true;
	}*/
};
class CreatListNode
{
public:
	ListNode* Creat(vector<int> A)
	{
		if(A.empty())
			return NULL;
		ListNode *Head=new ListNode(A[0]),*p=Head;
		for(vector<int>::iterator iter=A.begin()+1;iter!=A.end();iter++)
		{
			(*p).next=new ListNode(*iter);
			p=(*p).next;
		}
		return Head;
	}
	void Print(ListNode* Head)
	{
		ListNode *p=Head;
		while(p)
		{
			cout<<(*p).val<<" ";
			p=(*p).next;
		}
	}
};
int main()
{
	int a[5]={1,2,3,2,1};
	vector<int> arr(a,a+5);
	CreatListNode C;
	ListNode *HeadA=C.Creat(arr);
	Palindrome D;
	bool res=D.isPalindrome(HeadA);
	cout<<res;
	C.Print(HeadA);
	return 0;
}