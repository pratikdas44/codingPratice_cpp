#include <bits/stdc++.h>
using namespace std;
#define MAX_CHARS 256

int lengthOfLongestSubstring(string str) {
        
        int size = str.size(), current_len,max_len, visited[MAX_CHARS],prev_index;
        memset(visited,-1,sizeof(visited));
        current_len = max_len = 0; // stores length of current and maximum substring
        
        for (int i = 0; i < size; i++) {
            prev_index = visited[str[i]];
            
            
            if(prev_index ==-1 || i - current_len > prev_index)
            current_len++; // if current character is unique OR it has been encountered before our substring 
            
            else
            {
                if(current_len > max_len)
                max_len = current_len; // update max length
                
                current_len = i - prev_index; // new substring will start one letter from where the previous one has ended
            }
            
            visited[str[i]] = i; // mark last sighted character
        }
        
        
        if(current_len > max_len)
        max_len = current_len; // if all characters are unique
        
        
        return max_len;
        
}



int main() {

    int t;
    cin >> t;
    
    while(t--)
    {
        string s;
        cin >> s;
        cout << lengthOfLongestSubstring(s) << endl;
    }
    
	return 0;
}
