/*We maintain two arrays left and right where left[i] stores
the last index on left side which is increasing i.e. greater
han its previous element and right[i] will store the first
 index on the right side which is decreasing i.e. greater 
 than its next element. Once we maintained these arrays we 
 can answer each subarray in constant time. Suppose range 
 [l, r] is given then only if right[l] >= left[r], the 
 subarray will be in form of a mountain otherwise not 
 because the first index in decreasing form (i.e. right[l]) 
 hould come later than last index in increasing form 
 (i.e. left[r]).*/
// C++ program to check whether a subarray is in 
// mountain form or not 
#include <bits/stdc++.h> 
using namespace std; 

// Utility method to construct left and right array 
int preprocess(int arr[], int N, int left[], int right[]) 
{ 
	// initialize first left index as that index only 
	left[0] = 0; 
	int lastIncr = 0; 

	for (int i = 1; i < N; i++) 
	{ 
		// if current value is greater than previous, 
		// update last increasing 
		if (arr[i] > arr[i - 1]) 
			lastIncr = i; 
		left[i] = lastIncr; 
	} 

	// initialize last right index as that index only 
	right[N - 1] = N - 1; 
	int firstDecr = N - 1; 

	for (int i = N - 2; i >= 0; i--) 
	{ 
		// if current value is greater than next, 
		// update first decreasing 
		if (arr[i] > arr[i + 1]) 
			firstDecr = i; 
		right[i] = firstDecr; 
	} 
} 

// method returns true if arr[L..R] is in mountain form 
bool isSubarrayMountainForm(int arr[], int left[], 
							int right[], int L, int R) 
{ 
	// return true only if right at starting range is 
	// greater than left at ending range 
	return (right[L] >= left[R]); 
} 

// Driver code to test above methods 
int main() 
{ 
	int arr[] = {2, 3, 2, 4, 4, 6, 3, 2}; 
	int N = sizeof(arr) / sizeof(int); 

	int left[N], right[N]; 
	preprocess(arr, N, left, right); 

	int L = 0; 
	int R = 2; 
	if (isSubarrayMountainForm(arr, left, right, L, R)) 
		cout << "Subarray is in mountain form\n"; 
	else
		cout << "Subarray is not in mountain form\n"; 

	L = 1; 
	R = 3; 
	if (isSubarrayMountainForm(arr, left, right, L, R)) 
		cout << "Subarray is in mountain form\n"; 
	else
		cout << "Subarray is not in mountain form\n"; 

	return 0; 
} 
