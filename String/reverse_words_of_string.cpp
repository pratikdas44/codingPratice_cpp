//program to print output for i/p like ab.cde to cde.ab. Here strtok is used to find delimiter '.' First need to convert string to char as strtok can be used for char type only.
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    string ip;
	    cin >> ip;
	    char s[ip.length()];
	    int i;
	    for(i=0;i<ip.length();i++)
	        s[i] = ip[i];
	    s[i]='\0';
	    char *c;
	    vector<string> a;
	    c = strtok(s,".");
	    while(c!=NULL){
	        a.push_back(c);
	        c = strtok(NULL,".");
	    }
	    for(int i=a.size()-1;i>=0;i--){
            cout << a[i];
            if(i!=0)
                cout << ".";
	    }
	    cout << endl;
	}
	return 0;
}

