//simple program but with good logic.
//find all sum of absolute difference b/w elements.
//logic is to sort array and then apply formula

#include <bits/stdc++.h>
#define ll long long int
#define rep(i,a,b) for(int i=a;i<b;++i)
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
int main()
{ fast;
  ll t;
  cin >> t;
  ll a[t];
  rep(i,0,t)  { cin >> a[i];}

  ll sum = 0,ans =0;
  sort(a,a+t);
 for(ll i=0;i<t-1;i++) {   //this is the formula.
  sum += a[i];

  ans += a[i+1]*(i+1) - sum;
 }
   cout << ans;
}
