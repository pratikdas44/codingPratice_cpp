//program to find count of string in one string with respect to other
/*ex: 
i/p:3 def de gh 3 de lmn fgh a  o/p:1 0 1*/


#include <iostream>
#include <iterator>
#include <unordered_set>
using namespace std;

int main() {
    int n, q, i;
    string str;
    unordered_multiset<string> s;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> str;
        s.insert(str);
    }
    cin >> q;
    for (i = 0; i < q; ++i) {
        cin >> str;
        cout << s.count(str) << '\n';
    }
}
