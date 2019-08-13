#include <iostream>//to find array index such that maximum difference between buy and sell.
using namespace std;

int stock_buy(int arr[],int n)
{
     int i=0,a=0,b=0;
    while(i<n-1)
    {
        while(i<n-1 && arr[i+1]<=arr[i])
        i++;
        if(i==n-1)
        break;
        a=i++;
        while(i<n && arr[i]>=arr[i-1])
        i++;
        b=i-1;
        cout<<"("<<a<<" "<<b<<")"<<" ";
    }
    if(a==0 && b==0)
    cout<<"No Profit";
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int a[n];
	    for(int i=0;i<n;i++)
	     {cin >> a[i];
	         
	     }
	   stock_buy(a,n);
	   cout << "\n";
	   
	   
	}
	return 0;
}