#include <bits/stdc++.h>
using namespace std;


int main() {
	//code
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int sz = 2*n+2;
	    
	    int a[sz];
	    
	    for(int i = 0;i < sz;i++)
	        cin>>a[i];
	        
	    map<int,int>mp;
	    
	    vector<int>v(2);
	    for(int i = 0;i < sz;i++)
	        mp[a[i]]++;
	        
	    map<int,int>::iterator it;
	    int i = 0;
	    for(it = mp.begin();it != mp.end();it++)
	    {
	        if(it->second % 2 != 0)
	        {
	            v[i++] = it->first;
	        }
	    }
	    
	    sort(v.begin(),v.end());
	    
	    for(int i = 0;i < v.size();i++)
	        cout<<v[i]<<" ";
	        
	        cout<<endl;
	    
	}
	return 0;
}


