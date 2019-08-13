//to find gcd without any inbuilt function.
 if(A == 0) return B;
    while(B!=0){
        if(A>B)
          A = A-B;
        else
          B = B-A;
    }
    return A;