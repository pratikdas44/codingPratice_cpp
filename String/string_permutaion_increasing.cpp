#include <iostream>
#include <algorithm>
using namespace std;

// Function to find lexicographically next permutations of a
// string. It returns true if the string could be rearranged as
// a lexicographically greater permutation else it returns false
bool next_permutation(string &str, int n) 
{
	// Find largest index i such that str[i - 1] is less than str[i]
	int i = n - 1;
	while (str[i - 1] >= str[i])
	{
		// if i is first index of the string, that means we are already at
		// highest possible permutation i.e. string is sorted in desc order
		if (--i == 0)
			return false;
	}
 
	// if we reach here, substring str[i..n) is sorted in descending order
	// i.e. str[i-1] < str[i] >= str[i+1] >= str[i+2] >= ... >= str[n-1]
 
	// Find highest index j to the right of index i such that 
	// str[j] > str[i–1]
	int j = n - 1;
	while (j > i && str[j] <= str[i - 1])
		j--;
 
	// Swap characters at index i-1 with index j
	swap(str[i - 1], str[j]);
 
	// Reverse the substring str[i..n) and return true
	reverse (str.begin() + i, str.end());
 
	return true;
}


// Function to find all lexicographically next permutations of a
// string sorted in ascending order using std::prev_permutation
void permutations(string str)
{
	// sort the string in ascending order
	sort(str.begin(), str.end());

	while(1)
	{
		// print current permutation
		cout << str << " ";

		// find next lexicographically ordered permutation
		 if (!next_permutation(str.begin(), str.end()))
			 break;
	}
}

// main funtion
int main()
{
	string str = "BADC";
	
	permutations(str);
	
	return 0;
}
