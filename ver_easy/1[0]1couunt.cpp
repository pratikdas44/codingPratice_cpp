//count1[0]+1 number of patterns.
//take a variable isseen and make it to 1, if 1 is encountered

#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    string s;
	    cin >> s;
	    bool isseen = 0;int count=0;
	    for(int i=0;i<s.length();i++){
	       if(s[i] == '1' && isseen == 1){
	           if(s[i-1] == '0')
	             count++;
	       }
	       
	       if(s[i] == '1' && isseen == 0)
	         {
	             isseen = 1;
	             continue;
	         }
	        if(s[i]!='1' && s[i]!='0')
	         {
	             isseen = 0;
	         }
	    }
	    cout << count << "\n";
	}
	return 0;
}