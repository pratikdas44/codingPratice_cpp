//Here simple for loop is used. another approach is scan and compare element from right used using two for loop
//Leader is number which is greater than all numbers in its right side. Rightmost is always a leader


#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		scanf("%d",&t);
		int a[n];
		for(int i =0; i<n; i++)
		{
			scanf("%d",&a[i]);
		}
		for(int j=0; j<n; j++)
		{
			int flag=0;
			for(int k=j;k<n;k++)
			{
				//cout<<a[j]<<" "<<a[k]<<endl;
				if(a[j]<a[k])
				{
					flag = 1;
				}
			}
			if(flag ==0)
			{
			printf("%d",a[j]," ");
			}
		}
		cout<<endl;
	}
	return 0;
}
