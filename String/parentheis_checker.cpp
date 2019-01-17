//Function to check for balanced parenthesis checker in between "(","[","{".
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--){
	    string str;
	    cin >> str;
	    stack <char > s;
	    for(int i=0;str[i]!='\0';i++){
	        if(str[i]==')' || str[i]=='}' || str[i]==']'){
	            if(!s.empty()){
	                if(str[i]==')' && s.top()=='(' || str[i]=='}' && s.top()=='{' || str[i]==']' && s.top()=='[')
	                    s.pop();
	                else
	                    s.push(str[i]);
	            }
	            else
	                s.push(str[i]);
	        }
	        else
	            s.push(str[i]);
	    }
	    s.empty()?cout<< "balanced":cout<<"not balanced";
	    cout <<endl;
	}
	return 0;
}

