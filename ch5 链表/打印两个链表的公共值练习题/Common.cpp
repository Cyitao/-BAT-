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
class Common {
public:
    vector<int> findCommonParts(ListNode* headA, ListNode* headB) 
	{
        vector<int> res;
		ListNode *p=headA,*q=headB;
		while(p&&q)
		{
			if((*p).val==(*q).val)
			{
				res.push_back((*p).val);
				p=(*p).next;
				q=(*q).next;
			}
			else if((*p).val<(*q).val)
				p=(*p).next;
			else
				q=(*q).next;
		}
		return res;
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
	int a[7]={1,2,3,4,5,6,7},b[5]={2,4,6,8,10};
	vector<int> arr(a,a+7),brr(b,b+5);
	CreatListNode C;
	ListNode *HeadA=C.Creat(arr);
	ListNode *HeadB=C.Creat(brr);
	Common D;
	vector<int> res=D.findCommonParts(HeadA,HeadB);
	for(vector<int>::iterator iter=res.begin();iter!=res.end();iter++)
		cout<<*iter<<" ";
	return 0;
}