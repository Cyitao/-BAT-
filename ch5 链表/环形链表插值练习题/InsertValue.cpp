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
class InsertValue {
public:
    ListNode* insert(vector<int> A, vector<int> nxt, int val) 
	{
		if(A.empty())
		{
			ListNode *Head=new ListNode(val);
			//(*Head).next=Head;//1
			return Head;
		}
		ListNode *Head=new ListNode(A[0]),*p=Head;
		for(vector<int>::iterator iter=nxt.begin();iter!=nxt.end();iter++)
		{
			if(*iter==0)
			{
				(*p).next=Head;
				break;
			}
			(*p).next=new ListNode(A[*iter]);
			p=(*p).next;
		}
		ListNode *pre=Head,*now=(*Head).next;
		while(now!=Head)
		{
			if((*pre).val<=val&&(*now).val>=val)
			{
				ListNode *p=new ListNode(val);
				(*p).next=now;
				(*pre).next=p;
				break;
			}
			else
			{
				pre=now;
				now=(*now).next;
			}
		}
		if(now==Head)
		{
			ListNode *p=new ListNode(val);
			(*p).next=now;
			(*pre).next=p;
			if(val<(*Head).val)
				Head=p;
		}
		pre=Head,p=(*Head).next;//2
		while(p!=Head)
		{
			pre=p;
			p=(*p).next;
		}
		(*pre).next=NULL;//2
		return Head;
    }
};

int main()
{
	int a[7]={3,3,7,7,8,12,13},nxt[7]={1,2,3,4,5,6,0};
	vector<int> arr(a,a+7),next(nxt,nxt+7);
	InsertValue s;
	ListNode* Head=s.insert(arr,next,11);
	ListNode *p=(*Head).next;
	cout<<(*Head).val<<" ";
	while(p!=NULL)
	{
		cout<<(*p).val<<" ";
		p=(*p).next;
	}
	return 0;
}