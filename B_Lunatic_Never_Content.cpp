
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t=1;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int gcd=0;
        for(int i=0;i<=n/2;i++){
            gcd=__gcd(gcd,abs(arr[n-i-1]-arr[i]));
        }
        cout<<gcd<<'\n';
        
    }

    return 0;
}