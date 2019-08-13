//use of macros should be there.
//question demands floyd warshawll algorithm use.

#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define is(X) cout<<#X<<" is "<<X<<endl
#define ff first
#define ll long long
#define ss second
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define openin freopen("input.txt","r",stdin)
#define openout freopen("output.txt","w",stdout)
int g[250][250];
int main()
{
    fast;
    //openin;
    int nodes,edges;
    cin>>nodes>>edges;
    rep(i,1,nodes){rep(j,1,nodes)g[i][j]=10000000;g[i][i]=0;}
    /*rep(i,1,nodes)
    {
        rep(j,1,nodes)
            cout<<g[i][j]<<" ";
        cout<<endl;
    }*/
    while(edges--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=c;
        g[b][a]=c;
    }
    rep(k,1,nodes)
    {
        rep(i,1,nodes)
        {
            rep(j,1,nodes)
            {
                if(g[i][j]>g[i][k]+g[k][j])
                    g[i][j]=g[i][k]+g[k][j];
            }
        }
    }
    int ans = -1;
    rep(i,1,nodes){rep(j,1,nodes)ans = max(ans,g[i][j]);}
    cout<<ans;
    /*rep(i,1,nodes)
    {
        rep(j,1,nodes)
            cout<<g[i][j]<<" ";
        cout<<endl;
    }*/
    return 0;
}
