//program to reprsent number as sum of primes
#include <iostream>
using namespace std;

bool checkPrime(int n)
{
    bool flag = true;
    for(int i=2;i<=n/2;i++)
     {
         if(n%i == 0)
          {
              flag = false;
              break;
          }
     }
    return flag;
}

int main() {
	int t,n;
	cin >> t;bool flag = false;
	while(t--)
	{
	    cin >> n;
	    for(int i=2;i<=n/2;i++)
	     {
	         if(checkPrime(i))
	          {
	              if(checkPrime(n-i))
	               {
	                   cout << i << " " << n-i << "\n";
	                   flag = true;
	                   break;
	               }
	          }
	     }
	     if(!flag)
	      cout << "-1\n";
	         
	}
	return 0;
}

//optimized solution
for (int x=2; x<=sqrt(n); x++) { 
        float f = log(n) / log(x); 
        if ((f - (int)f) == 0.0)  
            return true;         
    } 
    return false; 