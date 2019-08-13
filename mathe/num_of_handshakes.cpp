//Program to find number of ways such that no cross handshakes occur
#include <bits/stdc++.h>
using namespace std;
long c[17] ;
void sieve(){
    c[0] = 1;
    c[1] = 1;
    for(int i =2;i<=15;i++){
        for(int j =0;j<i;j++){
            c[i] += c[j]*c[i-j-1];
        }
    }
}

int main(void){
    sieve();
    int t;
    scanf("%d",&t);
    while(t--){
        int n ;
        scanf("%d",&n);
        if(n%2!=0){
            cout<<"0"<<endl;
        }
        else{
            n = n>>1;
            cout<<c[n]<<endl;
        }
    }

    return 0;
}