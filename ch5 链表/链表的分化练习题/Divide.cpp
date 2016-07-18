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
class Divide {
public:
    ListNode* listDivide(ListNode* head, int val) 
	{
		ListNode *smallh=NULL,*smallt=NULL,*bigh=NULL,*bigt=NULL,*p=head,*q=head;
		while(p)
		{
			q=p;
			if((*p).val<=val)
			{
				if(!smallh)
					smallh=smallt=p;
				else
				{
					(*smallt).next=p;
					smallt=p;
				}
			}
			else 
			{
				if(!bigh)
					bigh=bigt=p;
				else
				{
					(*bigt).next=p;
					bigt=p;
				}
			}
			p=(*p).next;
			(*q).next=NULL;
		}
		if(smallh)
		{
			head=smallh;
			if(bigh)
				(*smallt).next=bigh;
		}
		else
			if(bigh)
				head=bigh;
		return head;
    }
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
	int a[5]={1620,1134,861,563,1};
	vector<int> arr(a,a+5);
	CreatListNode C;
	ListNode *Head=C.Creat(arr);
	Divide D;
	Head=D.listDivide(Head,1134);
	C.Print(Head);
	return 0;
}