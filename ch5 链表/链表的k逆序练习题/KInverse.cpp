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
class KInverse {
public:
    ListNode* inverse(ListNode* head, int k) 
	{
	    if(!head||k<2)
			return head;
		ListNode *p=head,*q=head,*LastTail=NULL;
		int i=1,count=0;
		while(q)
		{
			if(i==k)
			{
				if(!count)
					head=q;
				else
					(*LastTail).next=q;
				ListNode *temp1=(*q).next,*temp2=NULL;
				while(q!=p)
				{
					temp2=(*p).next;
					if((*q).next==temp1)
						LastTail=p;
					(*p).next=(*q).next;
					(*q).next=p;
					p=temp2;
				}
				p=q=temp1;
				i=1;
				count++;
			}
			if(q)
				q=(*q).next;
			i++;
		}
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
	int a[8]={1,2,3,4,5,6,7,8};
	vector<int> arr(a,a+8);
	CreatListNode C;
	ListNode *HeadA=C.Creat(arr);
	KInverse D;
	ListNode *head=D.inverse(HeadA,3);
	C.Print(head);
	return 0;
}