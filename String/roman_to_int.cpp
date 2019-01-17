//converts roman numerals to integers
// Program to convert Roman Numerals to Numbers 
#include<bits/stdc++.h> 
using namespace std; 

// This function returns value of a Roman symbol 
int value(char r) 
{ 
	if (r == 'I') 
		return 1; 
	if (r == 'V') 
		return 5; 
	if (r == 'X') 
		return 10; 
	if (r == 'L') 
		return 50; 
	if (r == 'C') 
		return 100; 
	if (r == 'D') 
		return 500; 
	if (r == 'M') 
		return 1000; 

	return -1; 
} 

// Returns decimal value of roman numaral 
int romanToDecimal(string &str) 
{ 
	// Initialize result 
	int res = 0; 

	// Traverse given input 
	for (int i=0; i<str.length(); i++) 
	{ 
		// Getting value of symbol s[i] 
		int s1 = value(str[i]); 

		if (i+1 < str.length()) 
		{ 
			// Getting value of symbol s[i+1] 
			int s2 = value(str[i+1]); 

			// Comparing both values 
			if (s1 >= s2) 
			{ 
				// Value of current symbol is greater 
				// or equal to the next symbol 
				res = res + s1; 
			} 
			else
			{ 
				res = res + s2 - s1; 
				i++; // Value of current symbol is 
					// less than the next symbol 
			} 
		} 
		else
		{ 
			res = res + s1; 
			i++; 
		} 
	} 
	return res; 
} 

// Driver Program 
int main() 
{ 
	// Considering inputs given are valid 
	int t;
	cin >>t;string str;
    while(t--)
    {
     cin >> str;
	cout << romanToDecimal(str) << endl; 
    }

	return 0; 
} 


//number to roman. 
// C++ Program for above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to calculate roman equivalent 
string intToRoman(int num) 
{ 
	// storing roman values of digits from 0-9 
	// when placed at different places 
	string m[] = {"", "M", "MM", "MMM"}; 
	string c[] = {"", "C", "CC", "CCC", "CD", "D", 
						"DC", "DCC", "DCCC", "CM"}; 
	string x[] = {"", "X", "XX", "XXX", "XL", "L", 
						"LX", "LXX", "LXXX", "XC"}; 
	string i[] = {"", "I", "II", "III", "IV", "V", 
						"VI", "VII", "VIII", "IX"}; 
		
	// Converting to roman 
	string thousands = m[num/1000]; 
	string hundereds = c[(num%1000)/100]; 
	string tens = x[(num%100)/10]; 
	string ones = i[num%10]; 
		
	string ans = thousands + hundereds + tens + ones; 
		
	return ans; 
} 

// Driver program to test above function 
int main() 
{ 
	int number = 3549; 
	cout << intToRoman(number); 
	return 0; 
} 

