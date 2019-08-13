//unlimited number of coins present.
//find number of ways different coins chosen such that
//sum equals to m.

#include <bits/stdc++.h>

using namespace std;
#define ll long long int
ll dp(int a[],int n,int m){
    ll table[m+1];
    memset(table,0,sizeof(table));
    table[0] = 1;
    for(int i=0;i<n;i++)
       for(int j=a[i];j<=m;j++)
          table[j] += table[j-a[i]];

  return table[m];
}

int main(){

    int m,n;
    cin >> m >> n; //m is cost and n is size.
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cout << dp(a,n,m);

}

//here permutation are also taken.
//hence {1,2} different from {2,1}.
int res[n+1];
	res[0] = 1; res[1] = 1;
	for (int i=2; i<=n; i++)
	{
	res[i] = 0;
	for (int j=1; j<=m && j<=i; j++)
		res[i] += res[i-j]; //all this means fibonacci series.
    //res = [1,1,2,3,5]
	}
	for(int i=0;i<=n;i++)
	  cout << res[i] << " ";
	return res[n];

//for string given "12" - o/p is AB and L
int countDecodingDP(char *digits, int n) 
{ 
    int count[n+1]; // A table to store results of subproblems 
    count[0] = 1; 
    count[1] = 1; 
  
    for (int i = 2; i <= n; i++) 
    { 
        count[i] = 0; 
  
        // If the last digit is not 0, then last digit must add to 
        // the number of words 
        if (digits[i-1] > '0') 
            count[i] = count[i-1]; 
  
        // If second last digit is smaller than 2 and last digit is 
        // smaller than 7, then last two digits form a valid character 
        if (digits[i-2] == '1' || (digits[i-2] == '2' && digits[i-1] < '7') ) 
            count[i] += count[i-2]; 
    } 
    return count[n]; 
} 