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

//to find length of valid parenthesis
#include <bits/stdc++.h>
using namespace std;
int checkparent(string str)
{ 
    // Create a stack and push -1 as initial index to it. 
    stack<int> stk; 
    stk.push(-1); 
  
    // Initialize result 
    int result = 0; 
  
    // Traverse all characters of given string 
    for (int i=0; i<str.length(); i++) 
    { 
        // If opening bracket, push index of it 
        if (str[i] == '(') 
          stk.push(i); 
  
        else // If closing bracket, i.e.,str[i] = ')' 
        { 
            // Pop the previous opening bracket's index 
            stk.pop(); 
  
            // Check if this length formed with base of 
            // current valid substring is more than max  
            // so far 
            if (!stk.empty()) 
                result = max(result, i - stk.top()); 
  
            // If stack is empty. push current index as  
            // base for next valid substring (if any) 
            else stk.push(i); 
        } 
    } 
  
    return result; 
}

int main() {
	int t;
	string s;
	cin >> t;
	while(t--)
	{
	    cin >> s;
	    cout << checkparent(s) << "\n";
	}
	return 0;
}
