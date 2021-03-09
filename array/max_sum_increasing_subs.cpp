/*Program to find maximum sum increasing subsquence. 
Like in 1,101,2,3,100: increasing subsquence are 
1,101 , 1,2,3,100, 2,3,100. Answer is maximum of 
all this. */

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int findequi(int arr[], int n) 
{ 
    int i, j, max = 0; 
    int ms[n];
    for ( i = 0; i < n; i++ ) 
        ms[i] = arr[i]; 
  
    /* Compute maximum sum values  
       in bottom up manner */
    for ( i = 1; i < n; i++ ) 
        for ( j = 0; j < i; j++ ) 
            if (arr[i] > arr[j] &&  
                ms[i] < ms[j] + arr[i]) 
                ms[i] = ms[j] + arr[i]; 
    
    /* Pick maximum of 
       all msis values */
    for ( i = 0; i < n; i++ ) 
        if ( max < ms[i] ) 
            max = ms[i]; 
  
    return max; 
 
}

int main() {
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d",&a[i]);;

	    }

   cout << findequi(a,n) << endl;
	}
	return 0;
}

