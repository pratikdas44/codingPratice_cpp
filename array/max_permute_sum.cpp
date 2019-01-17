#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll T;cin>>T;
	while(T--){
		ll N;cin>>N;
		ll A[N],B[N],C[N],sum=0;
		for(ll i=0;i<N;i++){
			cin>>A[i];
		}
		sort(A,A+N);
		for(ll i=0;i<N/2;i++){
             sum=sum+abs(A[i]-A[N-i-1]);
        }
		cout<<sum<<endl;

	}
}

