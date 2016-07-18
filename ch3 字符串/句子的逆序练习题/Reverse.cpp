#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Reverse {
public:
    string reverseSentence(string A, int n) 
	{
        reverseWord(A,0,n-1);
		int i=0,j=0;
		while(i<n)
		{
			while(i<n&&A[i]==' ')
				i++;
			if(i>=n)
				return A;
			j=i;
			while(i<n&&A[i]!=' ')
				i++;
			if(i>=n)
			{
				reverseWord(A,j,n-1);
				return A;
			}
			reverseWord(A,j,i-1);
		}
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
	string arr("dog loves pig");
	Reverse a;
	a.reverseSentence(arr,13);
	cout<<arr;
	return 0;
}