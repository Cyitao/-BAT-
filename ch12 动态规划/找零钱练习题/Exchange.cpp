#include<iostream>
#include<vector>
using namespace std;
//动态规划
class Exchange {
public:
	int countWays(vector<int> penny, int n, int aim) 
	{
		if(n==0||aim<0)
			return 0;
		int **map=new int*[n];
		for(int i=0;i<n;i++)
			map[i]=new int[aim+1];
		for(int i=0;i<n;i++)
			for(int j=0;j<aim+1;j++)
				map[i][j]=-1;
		for(int i=0;i<n;i++)
			map[i][0]=1;
		for(int i=0;i<aim+1;i++)
			if(i%penny[0]==0)
				map[0][i]=1;
			else 
				map[0][i]=0;
		for(int i=1;i<n;i++)
			for(int j=1;j<aim+1;j++)
				if((j-penny[i])>=0)
					map[i][j]=map[i][j-penny[i]]+map[i-1][j];
				else
					map[i][j]=map[i-1][j];
		return map[n-1][aim];
	}

};


/*记忆搜索
class Exchange {
public:
	int countWays(vector<int> penny, int n, int aim) 
	{
		if(n==0||aim<0)
			return 0;
		int **map=new int*[n];
		for(int i=0;i<n;i++)
			map[i]=new int[aim+1];
		for(int i=0;i<n;i++)
			for(int j=0;j<aim+1;j++)
				map[i][j]=-1;
		return process(penny,0,aim,map);

	}
	int process(vector<int> arr,int index,int aim,int **map)
	{
		int res;
		if(arr.size()-1==index)
		{
			if(map[index][aim]==-1)
				map[index][aim]=(aim%arr[index])?0:1;
			return map[index][aim];
		}
		else
		{
			res=0;
			int k=aim/arr[index];
			for(int i=0;i<=k;i++)
			{
				if(map[index+1][aim-i*arr[index]]==-1)
					map[index+1][aim-i*arr[index]]=process(arr,index+1,aim-i*arr[index],map);
				res+=map[index+1][aim-i*arr[index]];
			}
		}
		return res;
	}
};*/

/*暴力搜索
class Exchange {
public:
	int countWays(vector<int> penny, int n, int aim) 
	{
		if(n==0||aim<0)
			return 0;
		return process(penny,0,aim);

	}
	int process(vector<int> arr,int index,int aim)
	{
		int res;
		if(arr.size()-1==index)
		{
			res=(aim%arr[index])?0:1;
			return res;
		}
		else
		{
			res=0;
			int k=aim/arr[index];
			for(int i=0;i<=k;i++)
				res+=process(arr,index+1,aim-i*arr[index]);
		}
		return res;
	}
};*/

int main()
{
	int a[3]={1,2,3};
	vector<int> arr(a,a+3);
	Exchange e;
	cout<<e.countWays(arr,3,3);
	
	return 0;
}