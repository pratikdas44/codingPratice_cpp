//https://practice.geeksforgeeks.org/problems/black-and-white/0
#include <iostream>
using namespace std;
#define ll long long int
int main() {
	int t;
	 cin >> t;
	 while(t--){
	     int n,m;
	     cin >> n >> m;
	     ll res = n*m;
	     res *= n*m - 1;
	     if(n>1 && m>1)
	       {
	           res -= 4*(2*m*n-3*n-3*m+4);
	       }
	     
	     cout << res << "\n";
	 }
	return 0;
}