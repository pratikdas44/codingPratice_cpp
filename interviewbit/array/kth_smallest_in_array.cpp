//here array can't be modified
//find min and max and mid element.
int lo = *min_element(A.begin(), A.end());
int hi = *max_element(A.begin(), A.end());

while (lo <= hi)
{
    int mid = lo + (hi - lo)/2;
    int countLess = 0, countEqual = 0;
    
    for (auto i = 0; i<A.size(); ++i)
    {
        if (A[i]<mid)
            ++countLess;
        else if (A[i] == mid)
            ++countEqual;
        if (countLess >= B)
            break;
    }
    
    if (countLess < B && countLess + countEqual >= B)
        return mid;
    else if (countLess >= B)
        hi = mid - 1;
    else
        lo = mid + 1;
}
return -1;