//minimize difference between maximum(a,b,c) and minimum
// of (a,b,c) where a,b,c are elements of A[],B[],C[] resp.
 
//find current difference between all maximum elements.
//then for the greatest element go to that array and find
//next largest element, again find mind.
//if mind < current, update current.
//for array with largest element index -= 1;
// here we want that if one vector is completed loop
//should not be stopped hence, while condition.
 int current,mind,maxs;
    int i=A.size()-1,j=B.size()-1,k=C.size()-1;
    current = abs(max(A[i], max(B[j], C[k]))  
                     - min(A[i], min(B[j], C[k]))); 
    
    while(i!= -1 && j!=-1 && k!=-1){
        mind = abs(max(A[i],max(B[j],C[k])) - min(A[i],min(B[j],C[k])));
        
        if(mind < current){
            current = mind;
        }
        maxs = max(A[i],max(B[j],C[k]));
        if(A[i] == maxs) i-=1;
        else if(B[j] == maxs) j-=1;
        else k -= 1;
        
    }
    return current;