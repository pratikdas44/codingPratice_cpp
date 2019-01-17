#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int a[n][n],m=1;                                                     
    for(int i=0; i<2*n-1; i++)
    {
     int x=0,y;
     while(x<=i)
     {
       y=i-x;
       //cout << x << " " << y << "\n";
       if(x>=n || y>=n)
       {
         x++;
         continue;
       }
       a[x][y]=m++;
       x++;
     }
    }
   for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
    cout<<a[i][j]<<" ";
    cout<<"\n";
   }
   }
   return 0;
}

output will be: 1  2  4  7
                3  5  8 11
                6  9 12 14
               10 13 15 16
