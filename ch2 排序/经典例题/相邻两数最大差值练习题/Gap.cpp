#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Gap {
public:
    int maxGap(vector<int> A, int n) 
	{
        vector<vector<int>> B(n+1);
		int max,min,i,j,maxGap;
		for(i=1,max=min=A[0];i<n;i++)
		{
			if(A[i]>max)
				max=A[i];
			if(A[i]<min)
				min=A[i];
		}
		float gap=1.0*(max-min)/n;
		for(i=0;i<n;i++)
		{
			j=(int)((A[i]-min)/gap);
			if(B[j].empty())
			{
				B[j].push_back(A[i]);
				B[j].push_back(A[i]);
			}
			else
			{
				if(B[j][0]>A[i])
					B[j][0]=A[i];
				if(B[j][1]<A[i])
					B[j][1]=A[i];
			}
		}
		for(i=j=0,maxGap=0;i<n;i=j)
		{
			while(B[i].empty())
				i++;
			max=B[i][1];
			j=i+1;
			if(j<n+1)
			{
				while(B[j].empty())
					j++;
				if(j>=n+1)
					break;
			    min=B[j][0];
			    if(min-max>maxGap)
					maxGap=min-max;
			}
		}
		return maxGap;
    }
};
int main()
{
	int a[5]={1,2,5,4,6};
	vector<int> arr(a,a+5);
	Gap b;
	int c=b.maxGap(arr,5);
	cout<<c<<endl;
	return 0;
}