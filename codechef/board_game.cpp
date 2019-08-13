//here we have to tell in how many rolls specified i/p can come as 
//sum of numbers obtained in dice.
//given in question every type of answer atleast exist.
//hence humne sabko 2 ke terms me likh diya.
#include <bits/stdc++.h>
#define ll long long int
#define rep(i,a,b) for(int i=a;i<b;++i)
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    ll t,x;
    cin>>t;
   	while (t-- > 0)
	{
		int want;
		cin >> want;
		cout << want/2;
	}

    return 0;
}
