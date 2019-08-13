// CPP program to find count of smaller
// elements on right side using set in C++
// STL.
#include <bits/stdc++.h>
using namespace std;
void countSmallerRight(int A[], int len)
{
	set<int> s;
	int countSmaller[len];
	for (int i = len - 1; i >= 0; i--) {
		s.insert(A[i]);
		auto it = s.lower_bound(A[i]);cout << *it << " " << "\n"; //lower_bound give next higher element otherwise return the last element.Here we insert elements and find next distance between element and next higher element.
		countSmaller[i] = distance(s.begin(), it);
	}

	for (int i = 0; i < len; i++)
		cout << countSmaller[i] << " ";
}

// Driver code
int main()
{
	int A[] = {12, 1, 2, 3, 0, 11, 4};
	int len = sizeof(A) / sizeof(int);
	countSmallerRight(A, len);
	return 0;
}
