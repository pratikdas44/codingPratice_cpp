//we do A[i] - '0' ; to get the number(int)
//and A[i] + '0' ;to convert number to string   
if (A=="0" || B=="0")
        return "0";
        
    int aL = A.length(), bL = B.length();
    vector<int> result(aL+bL, 0);
    string res = "";
    
    for (auto i=aL-1; i>=0; --i)
    {
        for (auto j=bL-1; j>=0; --j)
        {
            result[i+j+1] += (A[i] - '0')*(B[j] - '0');
        }
    }
    
    for (auto k=aL+bL-1; k>0; --k)
    {
        if (result[k] >= 10)
        {
            result[k-1] += result[k]/10; //this gives carry.
            result[k] %= 10;
        }
    }
    
    int cnt = 0;
    for (auto l=0; l<result.size(); ++l)
    {
        if (result[l]==0 && l==cnt) //To omit the leading zeroes E.g. 00456723 will be 456723.
            ++cnt;//if we do only result[l]==0; all zeros will be deleted.

        else
            res += result[l] + '0'; //I was doing "-0" it was throwing internal error!
    }
    return res;

//add binary strings
 string result = ""; // Initialize result 
    int s = 0;          // Initialize digit sum 
  
    // Travers both strings starting from last 
    // characters 
    int i = a.size() - 1, j = b.size() - 1; 
    while (i >= 0 || j >= 0 || s == 1) 
    { 
        // Comput sum of last digits and carry 
        s += ((i >= 0)? a[i] - '0': 0); 
        s += ((j >= 0)? b[j] - '0': 0); 
  
        // If current digit sum is 1 or 3, add 1 to result 
        result = char(s % 2 + '0') + result; 
  
        // Compute carry 
        s /= 2; 
  
        // Move to next digits 
        i--; j--; 
    } 
    return result; 