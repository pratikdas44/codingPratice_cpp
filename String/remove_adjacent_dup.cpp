// for geeksforgeeks o/p is gksforgks
#include<bits/stdc++.h>
using namespace std;
string recursive_duplicate(string str)
{
    int n = str.length();
    string temp;
    
    if(str[0]!=str[1])
    {
        temp += str[0];
    }
    int i=1;
    while(i<n)
    {
        if(str[i]!=str[i-1] && str[i]!=str[i+1])
        {
           temp += str[i];
            //cout<<"current temp string: "<<temp<<endl;
        }
        i++;
    }
    
    if(temp.length()==0)
    {
        return temp;
    }
    if(temp.length()!=str.length())
    {
        return recursive_duplicate(temp);
    }
    return temp;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t!=0)
	{
	    string str,res;
	    cin>>str;
	    res = recursive_duplicate(str);
	   // bool x;
	   // x = 'e'^'f';
	    cout<<res<<endl;
	    t--;
	}
	return 0;
}


//for o/p geksforgeks
#include <iostream>
#include <string>
#include <string>
using namespace std;

// Function to remove adjacent duplicates characters from a string
void removeDuplicates(string &S) {
	char prev = '\0';
	for (auto it = S.begin(); it != S.end(); it++)
	{
		if (prev == *it) {
			S.erase(it);
			it--;
		}
		else {
			prev = *it;
		}
	}
}

// main function
int main()
{
	string S = "AAABBCDDD";
	removeDuplicates(S);
	cout << S << endl;

	return 0;
}

