
// C++ program for space optimized Dynamic Programming 
// Solution of Binomial Coefficient 
#include<bits/stdc++.h> 
using namespace std; 

int binomialCoeff(int n, int k) 
{ 
	int C[k+1]; 
	memset(C, 0, sizeof(C)); 

	C[0] = 1; // nC0 is 1 

	for (int i = 1; i <= n; i++) 
	{ 
		// Compute next row of pascal triangle using 
		// the previous row 
		for (int j = min(i, k); j > 0; j--) 
			C[j] = C[j] + C[j-1]; 
	} 
	return C[k]; 
} 

/* Drier program to test above function*/
int main() 
{ 
	int n = 5, k = 2; 
	printf ("Value of C(%d, %d) is %d ", 
			n, k, binomialCoeff(n, k) ); 
	return 0; 
} 


//permutation coefficient.
// A O(n) solution that uses 
// table fact[] to calculate 
// the Permutation Coefficient 
#include<bits/stdc++.h> 

// Returns value of Permutation 
// Coefficient P(n, k) 
int permutationCoeff(int n, int k) 
{ 
	int fact[n + 1]; 

	// base case 
	fact[0] = 1; 

	// Caculate value 
	// factorials up to n 
	for (int i = 1; i <= n; i++) 
		fact[i] = i * fact[i - 1]; 

	// P(n,k) = n! / (n - k)! 
	return fact[n] / fact[n - k]; 
} 

// Driver Code 
int main() 
{ 
	int n = 10, k = 2; 
	printf ("Value of P(%d, %d) is %d ", 
			n, k, permutationCoeff(n, k) ); 
	return 0; 
} 


//another for permuation

    int P = 1; 
  
    // Compute n*(n-1)*(n-2)....(n-k+1) 
    for (int i = 0; i < k; i++) 
        P *= (n-i) ; 
  
    return P; 