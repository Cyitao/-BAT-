#include<iostream>
using namespace std;
class BubbleSort {
public:
    void bubbleSort(int *A, int n)
	//ц╟ещеепР
	{
        int i=n,temp,j,flag;
		while(i)
		{
			for(j=0,flag=0;j<i-1;j++)
				if(A[j]>A[j+1])
				{
					temp=A[j];
					A[j]=A[j+1];
					A[j+1]=temp;
					flag=1;
				}
			if(!flag)
				break;
			i--;
		}
	}
};

int main()
{
	int arr[]={2,4,7,9,8,6};
	BubbleSort a;
	a.bubbleSort(arr,6);
	for(int i=0;i<6;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
