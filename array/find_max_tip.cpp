//Program to find maximum tip among two waiters, both take 
//tips according to orders and result is max tip.
//Here DP is used.
//fabs return |x| value.
#include <iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

bool comp(pair<int,int> x, pair<int,int> y)
{
    return (fabs(x.first-x.second)>fabs(y.first-y.second));
}
int main() {
	int t;
	cin>>t;
	 int n,x,y;
	while(t--)
	{
	  cin>>n>>x>>y;
	  vector<pair<int,int> >a(n);
	  for(int i=0;i<n;++i) {cin>>a[i].first;}
	   for(int i=0;i<n;++i) {cin>>a[i].second;}
	  sort(a.begin(),a.end(),comp);
	  int ans=0;
	  for(int i=0;i < n;++i)
	  {
	      if(x > 0 && ((a[i].first>=a[i].second)||y==0))
	          {
	          ans+=a[i].first;
	          x--;
	          
	      }
	      else if(y>0 &&((a[i].first<a[i].second)||x==0))

	          {
	          ans+=a[i].second;
	          y--;
	          
	      }
	  }
	  cout<<ans<<endl;
	    
	}
	return 0;
}
