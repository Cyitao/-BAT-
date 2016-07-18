#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Translation {
public:
    string stringTranslation(string A, int n, int len) 
	{
		if(len>n)
			exit(-1);
        reverseWord(A,0,len-1);
		reverseWord(A,len,n-1);
		reverseWord(A,0,n-1);
		return A;
    }
	void reverseWord(string &A,int low,int high)
	//¾Ö²¿ÄæÐòº¯Êý
	{
		if(low>=high)
			return;
		char temp;
		while(low<high)
		{
			temp=A[low];
			A[low]=A[high];
			A[high]=temp;
			low++;
			high--;
		}
	}
};
int main()
{
	string a("ABCDE");
	Translation A;
	string res=A.stringTranslation(a,5,3);
	cout<<res;
	return 0;
}