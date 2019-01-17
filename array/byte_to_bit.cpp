/*In the magical land of Byteland, there are three kinds of citizens:

    a Bit - 2ms

after a Bit appears, it grows up and becomes a Nibble (i.e. it disappears and a Nibble appears)
a Nibble - 8ms
after a Nibble appears, it grows up and becomes a Byte
a Byte - 16ms
after a Byte appears, it grows up, splits into two Bits and disappears*/ 
//atlast we have to find the population in given time.
//In this type of question always find remainder and modulus.j

#include<iostream>
#include<cmath>
using namespace std;

main()
{
    long int bit, nibble ,byte;
    long long int cycle=0,rem=0,population=0;
    long int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        n--;
        cycle = n/26;
        rem = n%26;
        population = pow(2,cycle);

        if(rem < 2)
        {
            cout<<population<<" 0 0"<<endl;
        }
        else if(rem <10)
        {
            cout<<"0 "<<population<<" 0"<<endl;
        }
        else
        {
            cout<<"0 0 "<<population<<endl;
        }
    }

}

