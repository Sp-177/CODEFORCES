
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t=1;
    // cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        bool isPrime=(n&1 || n==2)?true:false,isGcdOne=__gcd(n,k)==1?true:false,isNotSame=((n==1||n!=k))?true:false;

        for(ll i=3;i*i<=n&&i<=k;i+=2){
            if(n%i==0){
                isPrime=false;
                break;
            }
        }
        if(isPrime && isGcdOne &&isNotSame) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}