#include <iostream>
#include <string>
using namespace std;

// expand in both directions of low and high to find
// maximum length palindrome
string expand(string str, int low, int high)
{
	int len = str.length();

	// run till str[low.high] is a palindrome
	while (low >= 0 && high < len && (str[low] == str[high]))
		low--, high++;		// expand in both directions

	// return palindromic substring
	return str.substr(low + 1, high - low - 1);
}

// Function to find Longest Palindromic Substring in O(n^2) time
// and O(1) space
string LongestPalindromicSubstring(string str, int len)
{
	// max_str stores the maximum length palindromic substring
	// found so far

	string max_str = "", curr_str;

	// max_length stores the length of maximum length palindromic
	// substring found so far

	int max_length = 0, curr_length;

	// consider every character of given string as mid points and expand
	// in its both directions to find maximum length palindrome

	for (int i = 0; i < len; i++)
	{
		// find a longest odd length palindrome with str[i] as mid point

		curr_str = expand(str, i, i);
		curr_length = curr_str.length();

		// update maximum length palindromic substring if odd length
		// palindrome has greater length

		if (curr_length > max_length)
		{
			max_length = curr_length;
			max_str = curr_str;
		}

		// find a longest even length palindrome with str[i] and str[i+1]
		// as mid points. Note that an even length palindrome has two
		// mid points

		curr_str = expand(str, i, i + 1);
		curr_length = curr_str.length();
	
		// update maximum length palindromic substring if even length
		// palindrome has greater length

		if (curr_length > max_length)
		{
			max_length = curr_length;
			max_str = curr_str;
		}
	}

	return max_str;
}

// main function
int main()
{
	int t;
	cin >> t;string str = "aaaabbaa";
	while(t--)
	{ 
	cout << LongestPalindromicSubstring(str, str.length() - 1);
	}
	return 0;
}

//another method for above using dp

// A Dynamic Programming based C++ program for LPS problem 
// Returns the length of the longest palindromic subsequence in seq 
#include<stdio.h> 
#include<string.h> 

// A utility function to get max of two integers 
int max (int x, int y) { return (x > y)? x : y; } 

// Returns the length of the longest palindromic subsequence in seq 
int lps(char *str) 
{ 
int n = strlen(str); 
int i, j, cl; 
int L[n][n]; // Create a table to store results of subproblems 


// Strings of length 1 are palindrome of lentgh 1 
for (i = 0; i < n; i++) 
	L[i][i] = 1; 

	// Build the table. Note that the lower diagonal values of table are 
	// useless and not filled in the process. The values are filled in a 
	// manner similar to Matrix Chain Multiplication DP solution (See 
	// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/). cl is length of 
	// substring 
	for (cl=2; cl<=n; cl++) 
	{ 
		for (i=0; i<n-cl+1; i++) //n-cl+1 for finding number of groups
			                     //of length i
		{ 
			j = i+cl-1; //j is ending point.
			if (str[i] == str[j] && cl == 2) 
			L[i][j] = 2; 
			else if (str[i] == str[j]) 
			L[i][j] = L[i+1][j-1] + 2; //2 is added for counting first and last index.

			else
			L[i][j] = max(L[i][j-1], L[i+1][j]); 
		     //above is done as either palindrome is in
		  //i to j-1 or i+1 to j.
		} 
	} 

	return L[0][n-1]; 
} 

/* Driver program to test above functions */
int main() 
{ 
	char seq[] = "GEEKS FOR GEEKS"; 
	int n = strlen(seq); 
	printf ("The lnegth of the LPS is %d", lps(seq)); 
	getchar(); 
	return 0; 
} 


//checking Palindromic String
void isPalindrome(char str[])
{
	// Start from leftmost and rightmost corners of str
	int l = 0;
	int h = strlen(str) - 1;

	// Keep comparing characters while they are same
	while (h > l)
	{
		if (str[l++] != str[h--])
		{
			printf("%s is Not Palindrome", str);
			return;
		}
	}
	printf("%s is palindrome", str);
}

//maximum palindromic substring
// A C++ dynamic programming 
// solution for longest palindrome 

#include <bits/stdc++.h> 
using namespace std; 


// Function to print a substring str[low..high] 
void printSubStr( string str, int low, int high ) 
{ 
	for( int i = low; i <= high; ++i ) 
		cout << str[i]; 
} 

// This function prints the longest palindrome substring 
// It also returns the length of the longest palindrome 
int longestPalSubstr(string str) 
{ 
	// get length of input string 
	int n = str.size(); 

	// table[i][j] will be false if substring str[i..j] 
	// is not palindrome. 
	// Else table[i][j] will be true 
	bool table[n][n]; 
	
	memset(table, 0, sizeof(table)); 

	// All substrings of length 1 are palindromes 
	int maxLength = 1; 
	
	for (int i = 0; i < n; ++i) 
		table[i][i] = true; 

	// check for sub-string of length 2. 
	int start = 0; 
	for (int i = 0; i < n-1; ++i) 
	{ 
		if (str[i] == str[i+1]) 
		{ 
			table[i][i+1] = true; 
			start = i; 
			maxLength = 2; 
		} 
	} 

	// Check for lengths greater than 2. k is length 
	// of substring 
	for (int k = 3; k <= n; ++k) 
	{ 
		// Fix the starting index 
		for (int i = 0; i < n-k+1 ; ++i) 
		{ 
			// Get the ending index of substring from 
			// starting index i and length k 
			int j = i + k - 1; 

			// checking for sub-string from ith index to 
			// jth index iff str[i+1] to str[j-1] is a 
			// palindrome 
			if (table[i+1][j-1] && str[i] == str[j]) 
			{ 
				table[i][j] = true; 

				if (k > maxLength) 
				{ 
					start = i; 
					maxLength = k; 
				} 
			} 
		} 
	} 

cout << "Longest palindrome substring is: "; 
printSubStr( str, start, start + maxLength - 1 ); 
	
	// return length of LPS 
	return maxLength; 
} 

// Driver Code 
int main() 
{ 
	string str = "forgeeksskeegfor"; 
	cout << "\nLength is: " << longestPalSubstr( str ); 
	return 0; 
} 
