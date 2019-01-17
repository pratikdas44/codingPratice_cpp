//to find missing value in array from 1 to n
#include <iostream>
#include<stdio.h>
using namespace std;

int Missing(int arr[],int n)
{ int k = (n+1)*(n)/2;
  for(int j=0;j<n-1;j++)
    {  k -= arr[j];
    }

    return k;
}

int main() {
	int t,n;
	cin >> t;
	while(t--)
	{ cin >> n;
	  int a[n-1];
	  for(int i=0;i<n-1;i++)
	   {   cin >> a[i];
	   }
	   cout << Missing(a,n) << endl;

	}
	return 0;
}

