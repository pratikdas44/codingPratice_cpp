//program to find container with maximum water
#include <bits/stdc++.h>
using namespace std;

  
int find_area(int A[], int len) 
{ 
    int l = 0; 
    int r = len -1; 
    int area = 0; 
      
    while (l < r) 
    { 
        // Calculating the max area 
        area = max(area, min(A[l], 
                        A[r]) * (r - l)); 
                          
            if (A[l] < A[r]) 
                l += 1; 
                  
            else
                r -= 1; 
    } 
    return area; 
} 

int main() {
	int t,n,p;cin >> t;
	while(t--)
	{
	    cin >> n;int a[n];
	   for(int i=0;i<n;i++)
	    cin >> a[i];
	    
	   cout << find_area(a,n) << "\n";
	}
	return 0;
}
