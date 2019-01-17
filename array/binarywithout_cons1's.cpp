//to print number of binary numbers of size n without consecutive 1.Like for n = 3 , o/p = 5{000 , 001 , 010 , 100 , 101}

#include<iostream>
using namespace std;
int countString(int n)
{
    int A[n], B[n];
    A[0] = B[0] = 1;
    for(int i =1; i<n; i++)
    {
        A[i] =( A[i-1] + B[i-1])%1000000007;
        B[i] = A[i-1];
    }
    return ((A[n-1]+B[n-1])%1000000007);
}
int main()
{
    int t;
    //cout<<"Enter the no. of test cases :"<<endl;
    cin>>t;
    while(t--)
    {
        int n;
        //cout<<"Enter the number :"<<endl;
        cin>>n;
        cout<<countString(n);
        cout<<endl;
    }
}
 //print the strings
#include <iostream>
#include <string>
using namespace std;

// print all n-digit binary strings without any consecutive 1's
void countStrings(int n, string out, int last_digit)
{
    // if number becomes N-digit, print it
    if (n == 0)
    {
        cout << out << endl;
        return;
    }

    // append 0 to the result and recurse with one less digit
    countStrings(n - 1, out + "0", 0);

    // append 1 to the result and recurse with one less digit
    // only if last digit is 0
    if (last_digit == 0)
        countStrings(n - 1, out + "1", 1);
}

// main function
int main()
{
    // given number of digits
    int n = 5;
    string out = "";

    countStrings(n, out, 0);

    return 0;
}