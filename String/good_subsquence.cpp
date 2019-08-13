//program to find good subsequence of this string is a subsequence which contains distinct characters only. 
//Determine the number of good subsequences of the maximum possible length 



    #include <bits/stdc++.h>
    using namespace std;

    #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define endl "\n"
    #define int long long
    const int N=1e5+5;
    const int MOD=1e9+7;
    string s;
    int f[26];
    int32_t main()
    {
    	IOS;
    	int t;
    	cin>>t;
    	while(t--)
    	{
    		int ans=1;
    		cin>>s;
    		for(auto &ch:s)
    			f[ch-'a']++;
    		for(int i=0;i<26;i++)
    		{
    			if(!f[i])
    				continue;
    			ans*=f[i];
    			ans%=MOD;
    		}
    		cout<<ans<<endl;
    	}
    	return 0;
    }

//program to find is pattern can become substring of string 
    //after deletion of some characters.
    #include<bits/stdc++.h>

    typedef long long int lli;

    using namespace std;

    int main(int argc, const char *argv[]){
        int T;
        string text, pattern;
        cin >> T;
        while(T--){
            cin >> text >> pattern;
            lli n = text.length();
            lli m = pattern.length();
            lli min_d = n, d = 0, i = 0, j = 0, k = 0;
            for(i=0; i<n-m+1; i++){
                if(text[i] == pattern[0]){
                    k = 0;
                    d = 0;
                    for(j=i; j<n; j++){
                        if(text[j] == pattern[k]){
                            k++;
                            if(k == m){
                                if(d < min_d){
                                    min_d = d;
                                    break;
                                }
                            }
                        }
                        else{
                            d++;
                        }
                    }
                }
            }
            if(min_d == n)
                cout << "NO\n";
            else
                cout << "YES " << min_d  << endl;
        }
        return 0;
    }
