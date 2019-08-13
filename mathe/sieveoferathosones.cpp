//program to find prime number less than or equal to a number and then represent number as minimum distinct sum to elements.
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 1000005
bool prime[mx]; 
vector<ll> v;
void SieveOfEratosthenes(ll n) 
{ 
   
    memset(prime, true, sizeof(prime)); 
  
    for (ll p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            
            for (ll i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    }
    prime[1]=false;
     for (ll p=2; p<=n; p++) 
       if (prime[p]) 
          v.push_back(p); 
}    
int main() {
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    SieveOfEratosthenes(mx);
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<=3) cout<<"-1\n";
        else if(n%2==0) cout<<"1\n";
        else
        {
         if(prime[n-2]) cout<<"1\n";
         else cout<<"2\n";
         
        }
    }
	// your code goes here
	return 0;
}
