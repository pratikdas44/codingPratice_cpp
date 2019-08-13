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

//minimum number of swaps to make anagram
// C++ program to find minimum number of characters 
// to be removed to make two strings anagram. 
#include<bits/stdc++.h> 
using namespace std; 
const int CHARS = 26; 

// function to calculate minimum numbers of characters 
// to be removed to make two strings anagram 
int remAnagram(string str1, string str2) 
{ 
	// make hash array for both string and calculate 
	// frequency of each character 
	int count1[CHARS] = {0}, count2[CHARS] = {0}; 

	// count frequency of each character in first string 
	for (int i=0; str1[i]!='\0'; i++) 
		count1[str1[i]-'a']++; 

	// count frequency of each character in second string 
	for (int i=0; str2[i]!='\0'; i++) 
		count2[str2[i]-'a']++; 

	// traverse count arrays to find number of characters 
	// to be removed 
	int result = 0; 
	for (int i=0; i<26; i++) 
		result += abs(count1[i] - count2[i]); 
	return result; 
} 

// Driver program to run the case 
int main() 
{ 
	string str1 = "bcadeh", str2 = "hea"; 
	cout << remAnagram(str1, str2); 
	return 0; 
} 

//K-Anagrams
#define CHARS 26
bool areKAnagrams(string str1, string str2, int k)
  {
    int count1[CHARS] = {0}, count2[CHARS] = {0}; 
     if (str1.length() != str2.length())
		return false;
	// count frequency of each character in first string 
	for (int i=0; str1[i]!='\0'; i++) 
		count1[str1[i]-'a']++; 

	// count frequency of each character in second string 
	for (int i=0; str2[i]!='\0'; i++) 
		count2[str2[i]-'a']++; 

	// traverse count arrays to find number of characters 
	// to be removed 
	int result = 0; 
	for (int i=0; i<26; i++) 
	   if(count1[i] > count2[i])        
		result += abs(count1[i] - count2[i]); //here only character in one string are replaced.
		//find character in str1 but not in str2 and sum them.
	return (result<=k);
     
   }