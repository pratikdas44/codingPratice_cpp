//C++ implementation of above algorithm 
#include<bits/stdc++.h> 
using namespace std; 

// Function to find page faults using indexes 
int pageFaults(int pages[], int n, int capacity) 
{ 
	// To represent set of current pages. We use 
	// an unordered_set so that we quickly check 
	// if a page is present in set or not 
	unordered_set<int> s; 

	// To store least recently used indexes 
	// of pages. 
	unordered_map<int, int> indexes; 

	// Start from initial page 
	int page_faults = 0; 
	for (int i=0; i<n; i++) 
	{ 
		// Check if the set can hold more pages 
		if (s.size() < capacity) 
		{ 
			// Insert it into set if not present 
			// already which represents page fault 
			if (s.find(pages[i])==s.end()) 
			{ 
				s.insert(pages[i]); 

				// increment page fault 
				page_faults++; 
			} 

			// Store the recently used index of 
			// each page 
			indexes[pages[i]] = i; 
		} 

		// If the set is full then need to perform lru 
		// i.e. remove the least recently used page 
		// and insert the current page 
		else
		{ 
			// Check if current page is not already 
			// present in the set 
			if (s.find(pages[i]) == s.end()) 
			{ 
				// Find the least recently used pages 
				// that is present in the set 
				int lru = INT_MAX, val; 
				for (auto it=s.begin(); it!=s.end(); it++) 
				{ 
					if (indexes[*it] < lru) 
					{ 
						lru = indexes[*it]; 
						val = *it; 
					} 
				} 

				// Remove the indexes page 
				s.erase(val); 

				// insert the current page 
				s.insert(pages[i]); 

				// Increment page faults 
				page_faults++; 
			} 

			// Update the current page index 
			indexes[pages[i]] = i; 
		} 
	} 

	return page_faults; 
} 

// Driver code 
int main() 
{ 
	int t,n,c;cin >> t;
	while(t--)
	{
      cin >> n;
      int pages[n];
      for(int i=0;i<n;i++)
       {cin >> pages[i];}
     cin >> c;
	 cout << pageFaults(pages, n, c) << "\n"; }
	return 0; 
} 


//another
// We can use stl container list as a double 
// ended queue to store the cache keys, with 
// the descending time of reference from front 
// to back and a set container to check presence 
// of a key. But to fetch the address of the key 
// in the list using find(), it takes O(N) time. 
// This can be optimized by storing a reference 
//	 (iterator) to each key in a hash map. 
#include <bits/stdc++.h> 
using namespace std; 

class LRUCache { 
	// store keys of cache 
	list<int> dq; 

	// store references of key in cache 
	unordered_map<int, list<int>::iterator> ma; 
	int csize; // maximum capacity of cache 

public: 
	LRUCache(int); 
	void refer(int); 
	void display(); 
}; 

// Declare the size 
LRUCache::LRUCache(int n) 
{ 
	csize = n; 
} 

// Refers key x with in the LRU cache 
void LRUCache::refer(int x) 
{ 
	// not present in cache 
	if (ma.find(x) == ma.end()) { 
		// cache is full 
		if (dq.size() == csize) { 
			// delete least recently used element 
			int last = dq.back(); 

			// Pops the last elmeent 
			dq.pop_back(); 

			// Erase the last 
			ma.erase(last); 
		} 
	} 

	// present in cache 
	else
		dq.erase(ma[x]); 

	// update reference 
	dq.push_front(x); 
	ma[x] = dq.begin(); 
} 

// Function to display contents of cache 
void LRUCache::display() 
{ 

	// Iterate in the deque and print 
	// all the elements in it 
	for (auto it = dq.begin(); it != dq.end(); 
		it++) 
		cout << (*it) << " "; 

	cout << endl; 
} 

// Driver Code 
int main() 
{ 
	LRUCache ca(4); 

	ca.refer(1); 
	ca.refer(2); 
	ca.refer(3); 
	ca.refer(1); 
	ca.refer(4); 
	ca.refer(5); 
	ca.display(); 

	return 0; 
} 
// This code is contributed by Satish Srinivas 

