//largest bitwaise or of smallest and next smallest
#include<bits/stdc++.h>
using namespace std;
int main()
{
int t,n;
cin>>t;
while(t--)
{
cin>>n;
long a[n+1];
for(int i=0;i<n;i++)
{
cin>>a[i];
}
stack< long > s; long ans=-100000000;
for(int i=0;i<n;i++)
{

while(!s.empty()&&a[i]<=s.top())
{
if(ans<(s.top()|a[i]))
{
ans=(s.top()|a[i]);
}
s.pop();
}
if(!s.empty()&&ans<(s.top()|a[i]))
ans=(a[i]|s.top());
s.push(a[i]);

}
while(!s.empty())
s.pop();


cout<<ans<<endl;
}
return 0;
}