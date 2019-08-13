/*The idea is to count differences at individual bit 
positions. We traverse from 0 to 31 and count numbers 
with i’th bit set. Let this count be ‘count’. There 
would be “n-count” numbers with i’th bit not set. So 
count of differences at i’th bit would be 
“count * (n-count) * 2”.*/ 

int ans = 0;  // Initialize result 
  
    // traverse over all bits 
    for (int i = 0; i < 32; i++) 
    { 
        // count number of elements with i'th bit set 
        int count = 0; 
        for (int j = 0; j < n; j++) 
            if ( (arr[j] & (1 << i)) ) 
                count++; 
  
        // Add "count * (n - count) * 2" to the answer 
        ans += (count * (n - count) * 2); 
    } 
  
    return ans; 