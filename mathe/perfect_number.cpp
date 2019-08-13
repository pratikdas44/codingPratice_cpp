//perfect number is whose divisors sum(excluding the number) is equal to number.
//here we go upto sqrt(n)
#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    long long n,s=1;
	    cin >> n;
	    for(long long i=2;i*i<=n;i++)
	    {
	        if(n%i == 0)
	         {
	             if(i*i!=n) 
                   s = s + i + n/i; 
            else
                s=s+i; 
	         }
	    }
	    if(s == n)
	     cout << "1" << "\n";
	     else
	      cout << "0" << "\n";
	}
	return 0;
}