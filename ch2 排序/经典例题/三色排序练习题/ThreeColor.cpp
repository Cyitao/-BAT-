#include<iostream>
#include<vector>
using namespace std;
class ThreeColor {
public:
    vector<int> sortThreeColor(vector<int> &A, int n)
    {
		int f,r,i,temp;
        for(i=f=0,r=n-1;i<=r;i++)
		{
			if(A[i]==0)
			{
				temp=A[f];
				A[f]=A[i];
				A[i]=temp;
				f++;
			}
			if(A[i]==2)
			{
				temp=A[r];
				A[r]=A[i];
				A[i]=temp;
				r--;
                i--;
			}
		}
		return A;
    }
};
int main()
{
	int a[6]={1,2,0,2};
	vector<int> b(a,a+4);
	ThreeColor c;
	c.sortThreeColor(b,4);
	for(int i=0;i<4;i++)
		cout<<b[i]<<" ";
	cout<<endl;
	return 0;
}