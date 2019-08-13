// C++ program to print minimum number that can be formed 
// from a given sequence of Is and Ds 
#include<bits/stdc++.h> 
using namespace std; 

void printLeast(string arr) 
{ 
	// min_avail represents the minimum number which is 
	// still available for inserting in the output vector. 
	// pos_of_I keeps track of the most recent index 
	// where 'I' was encountered w.r.t the output vector 
	int min_avail = 1, pos_of_I = 0; 

	//vector to store the output 
	vector<int>v; 

	// cover the base cases 
	if (arr[0]=='I') 
	{ 
		v.push_back(1); 
		v.push_back(2); 
		min_avail = 3; 
		pos_of_I = 1; 
	} 
	else
	{ 
		v.push_back(2); 
		v.push_back(1); 
		min_avail = 3; 
		pos_of_I = 0; 
	} 

	// Traverse rest of the input 
	for (int i=1; i<arr.length(); i++) 
	{ 
		if (arr[i]=='I') 
		{ 
			v.push_back(min_avail); 
			min_avail++; 
			pos_of_I = i+1; 
		} 
		else
		{ 
			v.push_back(v[i]); 
			for (int j=pos_of_I; j<=i; j++) 
				v[j]++; 

			min_avail++; 
		} 
	} 

	// print the number 
	for (int i=0; i<v.size(); i++) 
		cout << v[i] << " "; 
	cout << endl; 
} 

// Driver program to check the above function 
int main() 
{ 
	printLeast("IDID"); 
	printLeast("I"); 
	printLeast("DD"); 
	printLeast("II"); 
	printLeast("DIDI"); 
	printLeast("IIDDD"); 
	printLeast("DDIDDIID"); 
	return 0; 
} 
