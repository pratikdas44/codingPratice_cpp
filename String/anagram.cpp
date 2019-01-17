//Program to check for anagram. Anagrams are like : "acb" and "abc". //key is ascii code and value is count.
#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string X, string Y)
{
	// if X's length is not same as Y's, they can't be anagram
	if (X.length() != Y.length())
		return false;

	// create an empty map
	unordered_map<int, int> freq;

	// maintain count of each character of X in the map
	for (char x: X)
		freq[x]++;

	// do for each character of Y

	// create an second map
	unordered_map<int, int> freqY;

	// maintain count of each character of Y in the map
	for (char y: Y)
		freqY[y]++;

	// return true if both map has same content
	return freq == freqY;
}

int main() {
	int t;cin >> t;string a,b;
	while(t--)
	{
	    cin >> a >> b;
	    if(isAnagram(a,b))
	      cout << "YES\n";
	     else
	      cout << "NO\n";
	}
	return 0;
}
