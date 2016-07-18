#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Transform {
public:
    bool chkTransform(string A, int lena, string B, int lenb)
    {
        if(lena!=lenb)
            return false;
        int HashTable1[256]={0},HashTable2[256]={0},i;
        for(i=0;i<lena;i++)
        {
            HashTable1[A[i]]++;
            HashTable2[B[i]]++;
        }
        i=0;
        while((i<256)&&HashTable1[i]==HashTable2[i])
            i++;
        if(i>=256)
            return true;
        else
            return false;
    }
};
int main()
{
	string a("abce"),b("rbca");
	Transform A;
	bool c=A.chkTransform(a,4,b,4);
	cout<<c;
	return 0;
}