#include<bits/stdc++.h>
using namespace std;

int main(){
    	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >>n ;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin >> a[i];
	    }
}


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll f(ll i){
 string s = to_string(i);

 int a[10] = {0};

 for(ll i=0;i<s.length();i++){
   if(a[s[i] - '0'])
      {
         s[i] = '0';
      }
  else {
   a[s[i] - '0']++;
  }

 }

 return stoi(s);
}

int main(){
int t;
cin >> t;
while(t--){
ll d1,d2,n,m;
cin >> d1 >> n;
cin >> d2 >> m;
ll sum = 0;
for(ll i=n;i<=m;i++){
 sum += f(i) % mod;
}
cout << sum << "\n";
}
}
