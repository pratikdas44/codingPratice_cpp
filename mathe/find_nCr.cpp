//to find C(n,r) = C(n-1,r-1)+C(n-1,r)
#include <bits/stdc++.h>
using namespace std;

int fact(long long n,long long k)
{  
   long long int C[n+1][k+1];
    long long int i, j;
   
   while(n >= k)
   { for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;

            // Calculate value using previosly stored values
            else
                C[i][j] = (C[i-1][j-1] + C[i-1][j])%1000000007;
          }
     
     }
       return C[n][k];
   }

    return 0;
}

int main() {
	int t;
	cin >> t;long long int n,r;
	while(t--)
	{
	    cin >> n >> r;
	    cout << fact(n,r);
	    cout << "\n";
	}
	return 0;
}
