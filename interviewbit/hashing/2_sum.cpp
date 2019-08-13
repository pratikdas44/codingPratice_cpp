//return two indexes whose content sum is target.
 unordered_map<int, int> hmap;  
    int size = arr.size();
    for(int i=0 ; i<size ; ++i) {
        unordered_map<int, int>::iterator get = hmap.find(target - arr[i]);
        // return the vector if we found 2 numbers
        if(get != hmap.end())   return vector<int>{get->second, i+1};
        
        // add the element if its not a duplicate
        if(hmap.find(arr[i]) == hmap.end())     hmap[arr[i]] = i+1;   
    }
return vector<int>{};


//4 sum.
//here return all possible 4 values whose sum is equal to target.
 sort(A.begin(),A.end());
    vector<vector <int>> res;
    vector<int>p;
    p.resize(4);
    for(int i=0;i<A.size()-3;i++){
        if(i>0 && A[i]==A[i-1]) continue;
        for(int j=i+1;j<A.size()-2;j++){
            if(j>i+1 && A[j]==A[j-1]) continue;
           // if(A[j]==A[j+1]) continue;
            int target=B-A[i]-A[j];
            p[0]=A[i];
            p[1]=A[j];
            
            int k=j+1;
            int q=A.size()-1;
            while(k<q){
                
                int sum=A[k]+A[q];
                if(sum==target){
                    p[2]=A[k];
                    p[3]=A[q];
                    res.push_back(p);
                    while(p[2]==A[k] && k<q) k++;
                   // while(p[3]==A[q] && q>k) q--;
                }
                else if(sum<target) k++;
                else     q--;
                
            }
            return res;