/*
    Find the largest x such that P[x]<P[x+1].
    (If there is no such x, P is the last permutation.)
    Find the largest y such that P[x]<P[y].
    Swap P[x] and P[y].
    Reverse P[x+1 .. n]. */

bool flag = 0;
for(int i = 1 ; i<A.size() ; ++i)
{
    if(A[i-1] < A[i])
        flag = 1;
}
if(!flag)
{
    reverse(A.begin() , A.end());
    return;
}

int i = A.size() - 1;
for(int j = i-1 ; j>=0 ; --j)
{
    if(A[j] > A[j+1])
        continue;
    
    i = j;
    break;
}
int mni = -1, mn = INT_MAX;
for(int j = i+1 ; j<A.size() ; ++j)
{
    if(A[j] > A[i] and A[j] < mn)
    {
        mn = A[j];
        mni = j;
    }
}
swap(A[i] , A[mni]);
sort(A.begin() + i+1 , A.end());
    