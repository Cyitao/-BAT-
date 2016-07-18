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
class ClearValue {
public:
    ListNode* clear(ListNode* head, int val) 
	{
		if(!head)
			return head;
		ListNode *Head=NULL,*Tail=NULL,*p=head,*temp=NULL;
		while(p)
		{
			temp=(*p).next;
			if((*p).val==val)
				delete p;
			else
			{
				if(!Head)
					Head=p;
				else
					(*Tail).next=p;
				Tail=p;
				(*Tail).next=NULL;
			}
			p=temp;
		}
		return Head;
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
	int a[7]={1,2,3,4,3,2,1};
	vector<int> arr(a,a+7);
	CreatListNode C;
	ListNode *HeadA=C.Creat(arr);
	ClearValue D;
	ListNode *head=D.clear(HeadA,2);
	C.Print(head);
	return 0;
}