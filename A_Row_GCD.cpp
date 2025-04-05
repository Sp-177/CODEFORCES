
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
        ll n,m;cin>>n>>m;
        ll a[n], b[m];
        ll mini=LLONG_MAX,index=-1;
        for(int i=0; i<n; i++){cin>>a[i];if(a[i]<mini){mini=a[i];index=i;}}
        for(int i=0; i<m; i++)cin>>b[i];
        // sort(a,a+n);
        // sort(b,b+m);
        ll GCD=0;
        for(int i=0;i<n;i++){
            if(i!=index)GCD=__gcd(GCD,a[i]-mini);
        }
        for(int i=0;i<m;i++){
            cout<<__gcd(mini+b[i],GCD)<<" ";
        }   
        cout<<endl;    
    }

    return 0;
}