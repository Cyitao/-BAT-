#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Replacement {
public:
    string replaceSpace(string iniString, int length) 
	{
        int NumofBlank=0,i,j;
		for(i=0;i<length;i++)
			if(iniString[i]==' ')
				NumofBlank++;
		int NewLength=length+2*NumofBlank;
		string res(NewLength,0);
		for(i=length-1,j=NewLength-1;j>=0;)
			if(iniString[i]==' ')
			{
				res[j--]='0';
				res[j--]='2';
				res[j--]='%';
				i--;
			}
			else
				res[j--]=iniString[i--];
		return res;
	}
};
int main()
{
	string arr("a b c");
	Replacement A;
	string res=A.replaceSpace(arr,5);
	cout<<res;
	return 0;
}