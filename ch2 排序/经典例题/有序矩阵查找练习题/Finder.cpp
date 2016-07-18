#include<iostream>
#include<vector>
using namespace std;
class Finder 
{
public:
    bool findX(vector<vector<int> > mat, int n, int m, int x) 
	{
        int hang=0,lie=m-1;
		while(hang<n&&lie>=0)
		{
			if(mat[hang][lie]==x)
				return true;
			if(mat[hang][lie]>x)
				lie--;
		    if(mat[hang][lie]<x)
				hang++;
		}
		return false;
    }
};
int main()
{
	int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	vector<vector<int>> b(3,vector<int>(3));//二维数组初始化
	for(int i=0;i<3;i++)
		copy(a[i][0],a[i][2],b[i]);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			cout<<b[i][j];
		cout<<endl;
	}
	Finder c;
	bool d=c.findX(b,3,3,10);
	cout<<d;
	return 0;
}

