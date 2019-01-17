// program to find min height between longest and smallest tower, after they are operated by k only once.
#include <bits/stdc++.h>
using namespace std;
int minimize(int a[],int n,int k){
    if(n==1)return 0;
    sort(a,a+n);
    int ans=a[n-1]-a[0];
    int s=a[0]+k,b=a[n-1]-k;if(s>b)swap(s,b);
    for(int i=1;i<n-1;i++){
        int sub=a[i]-k,add=a[i]+k;
        if(sub>=s||add<=b)continue;
        if (b-sub<= add-s)
            s=sub;
      else b=add;
    }
    return min(ans,b-s);
}
int main() {
  int t;cin>>t;
  while(t--){
     int k,n;cin>>k>>n;int a[n];
      for(int i=0;i<n;i++)cin>>a[i];
     cout<<minimize(a,n,k)<<"\n";
  }
	return 0;
}
