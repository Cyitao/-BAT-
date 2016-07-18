#include<iostream>
#include<string>
using namespace std;
class Rotation {
public:
	bool chkRotation(string A, int lena, string B, int lenb) 
	{
		string sum=A+A;
		string::size_type pos=sum.find(B);
		if(pos!=string::npos)
			return true;
		else
			return false;
	}
};