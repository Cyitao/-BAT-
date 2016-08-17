#include<iostream>
#include<vector>
using namespace std;
class Backpack  
{  
public:          
	int maxValue(vector<int> w, vector<int> v, int n, int cap)           
	{                  
		int **dp=new int*[n];                  
		for(int i=0;i<n;i++)                          
			dp[i]=new int[cap+1]();                  
		for(int i=0;i<n;i++)                          
			dp[i][0]=0;                  
		for(int i=0;i<cap+1;i++)                  
		{                          
			if(i>=w[0])                                 
				dp[0][i]=v[0];                          
			else                               
				dp[0][i]=0;                  
		}                  
		for(int i=1;i<n;i++)                          
			for(int j=1;j<cap+1;j++)                      
			{                               
				if((j-w[i])>=0)                                       
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);                               
				else                                     
					dp[i][j]=dp[i-1][j];                      
			}                  
	    int res=dp[n-1][cap];                  
	    for(int i=0;i<n;i++)                          
			delete []dp[i];                  
		delete []dp;                  
		return res;          
	}  
}; 


int main()
{
	int a[8]={42,25,30,35,42,21,26,28};
	int b[8]={261,247,419,133,391,456,374,591};
	vector<int> arr(a,a+8);
	vector<int> brr(b,b+8);
	Backpack B;
	cout<<B.maxValue(arr,brr,8,297);
	return 0;
}