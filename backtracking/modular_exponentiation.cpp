//to find (a^b)mod c;
/* 1. (a*b)mod c = ((amodc)*(b mod c) mod c)
 2.if b is even: y = ((a^b/2)*(a^b/2)) mod c;
 3.if b is odd : y = (a*(a^b-1)mod c)mod c;*/

 int modularExponentiation(int x,int n,int M)
{
    int result=1;
    while(n>0)
    {
        if(power % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}

//gcd
int GCD(int A, int B) {
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}

//extended euclidean
//ax1+by1 = gcd(a,b) and x1,y1 are used to find modular multiplicative
//inverse.

/*Proof: since gcd(a,b) = gcd(b,a%b), hence
 bx + (a%b)y = gcd(a,b);
 and a%b = a - b*(a/b);
 so, b(x-(a/b)y)+ay= gcd(a,b);
 hence on comparing, y = x1 and y1 = x-(a/b)y */

 #include < iostream >

int d, x, y;
void extendedEuclid(int A, int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

int main( ) {
extendedEuclid(16, 10);
cout << ”The GCD of 16 and 10 is ” << d << endl;
cout << ”Coefficients x and y are ”<< x <<  “and  “ << y << endl;
return 0;   
}

//modular multipl	icative inverse
//given a,m find b such that (a*b)%m = 1

//1. a & m are coprime i.e. ax+my= 1, then x is inverse
int d,x,y;
int modInverse(int A, int M)
{
    extendedEuclid(A,M);
    return (x%M+M)%M;    //x may be negative
}

//2.fermat(when m is prime)
//a^(m-1) = 1(modm) then, 1/a = a^(m-2) modm
int modInverse(int A,int M)
{
    return modularExponentiation(A,M-2,M);

