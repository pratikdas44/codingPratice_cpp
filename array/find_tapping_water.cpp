//find number of units that can be filled. 
//Only cell with both left and right cell higher than it can store water(u know)
#include <bits/stdc++.h>
using namespace std;

int findWater(int A[], int n){

int sum = 0;

int s1 = 0;

int i = 1;

while(i < n){

while(A[i] < A[s1]){

i++;

}

for(int k = s1; k < i; k++){

sum += (std::min(A[s1], A[i]) - A[k]);

A[k] += (std::min(A[s1], A[i]) - A[k]);

}

while(A[s1] <= A[i] && i < n){

A[s1] = A[i];

s1++;

i++;

}

}

return sum;

}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >>n ;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin >> arr[i];
	    }
	 // left[i] contains height of tallest bar to the 
    // left of i'th bar including itself  
	   int left[n]; 
  
    // Right [i] contains height of tallest bar to 
    // the right of ith bar including itself 
    int right[n]; 
  
    // Initialize result 
    int water = 0; 
  
    // Fill left array 
    left[0] = arr[0]; 
    for (int i = 1; i < n; i++) 
       left[i] = max(left[i-1], arr[i]); 
  
    // Fill right array 
    right[n-1] = arr[n-1]; 
    for (int i = n-2; i >= 0; i--) 
       right[i] = max(right[i+1], arr[i]); 
  
    // Calculate the accumulated water element by element 
    // consider the amount of water on i'th bar, the 
    // amount of water accumulated on this particular 
    // bar will be equal to min(left[i], right[i]) - arr[i] . 
    for (int i = 0; i < n; i++) 
       water += min(left[i],right[i]) - arr[i]; 
  
    cout <<  water << "\n"; 
	}
	return 0;
}