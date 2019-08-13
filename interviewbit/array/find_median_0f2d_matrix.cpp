//to find median of 2d matrix.
//a.size() gives number of rows.
//median will be at (n*m +1)/2;
//if x is median than number of elments less than or
//equal to x will be (n*m+1)/2;
//using binary search will give median.
//range is min to max;
//upper_bound gives first number index greater than element.
//or upper bound gives number of smaller elements less than number

int median(vector<vector<int> > &A) {
    int min = A[0][0], max = A[0][0];
    int n = A.size(), m = A[0].size();
    for (int i = 0; i < n; ++i) {
        if (A[i][0] < min) min = A[i][0];
        if (A[i][m-1] > max) max = A[i][m-1];
    }

    int element = (n * m + 1) / 2;
    while (min < max) {
        int mid = min + (max - min) / 2;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            cnt += upper_bound(&A[i][0], &A[i][m], mid) - &A[i][0];
        if (cnt < element)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}

//another code
int l = 0, r = INT_MAX;
    int mid, req = (int)A.size() * (int)A[0].size();
    assert(req % 2);
    while(r - l > 1){
        mid = l + (r - l) / 2;
        int cnt = 0;
        for(auto &i: A){ 
            //using upper bound in a sorted array to count number of elements smaller than mid
            int p = upper_bound(i.begin(), i.end(), mid) - i.begin();
            cnt += p;
        }
        if(cnt >= (req/2 +1)) r = mid;
        else l = mid;
    }   
    return r;

//using extra memory
 int n = A.size();
    int m = A[0].size();
    int k = n * m / 2;
    
    vector<int> A_copy;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            A_copy.push_back(A[i][j]);
    A.clear();
    
    std::nth_element(A_copy.begin(), A_copy.begin() + k, A_copy.end());
    return A_copy[k];


//nth_element returns nth element in sorted array, without
//actually sorting array.
//here actually no extra space is taken as A is cleared.
