//using sliding window technique. As soon as same character repeated make new character false and increase low
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// define character range
#define CHAR_RANGE 128 

// Function to find longest substring containing all distinct
// characters in it using sliding window
string longestSubstr(string str, int n)
{
	// boolean array to mark characters present in current window
	vector<bool> window(CHAR_RANGE); 

	// stores longest substring boundaries
	int begin = 0, end = 0;

	// [low..high] maintain sliding window boundaries
	for (int low = 0, high = 0; high < n; high++)
	{
		// if current character is present in current window
		if (window[str[high]])
		{
			// remove characters from the left of the window till
			// we encounter current character
			while (str[low] != str[high])
				window[str[low++]] = false;

			low++;		// remove current character
		}
		else
		{
			// if current character is not present in the current
			// window, include it
			window[str[high]] = true;

			// update maximum window size if necessary
			if (end - begin < high - low)
			{
				begin = low;
				end = high;
			};
		}
	}

	// return longest substring found at str[begin..end]
	return str.substr(begin, end - begin + 1);
}

// main function
int main()
{
	string str;int t;
	cin >> t;
	while(t--)
	{
	 cin >> str;
    int n = str.length();

	cout << longestSubstr(str, n).length();


	}

	return 0;
}

