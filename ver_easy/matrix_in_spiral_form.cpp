#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define m 1000003
int fact[1000005],a[1000005];
int main(){
int n = 3;
int A[n][n] = {{1,2,3},{4,5,6},{7,8,9}};
for(int i=0;i<3;i++)
  {for(int j=0;j<3;j++)
     {cout << A[i][j] << " ";}
cout << "\n";
}

int rs = 0,cs = 0,re = n-1,ce = n-1;
while(rs<=re && cs<=ce){
 int i= rs,j=cs;
 for(j=cs;j<=ce;j++)
   cout << A[i][j];
 for(i=rs+1,j--;i<=re;i++)
   cout << A[i][j];
 for(j = ce-1,i--;j>=cs;j--)
   cout << A[i][j];
 for(i = re-1,j++;i>=rs+1;i--)
   cout << A[i][j];
 rs++;cs++;re--;ce--;
}
}
