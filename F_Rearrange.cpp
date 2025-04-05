
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
        vector<ll>a(n),b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
       sort(a.begin(),a.end());
       sort(b.begin(),b.end());
       int cnt=0;
       int i=0,j=0;
       while(i<n&&j<n){
        while(j<n&&b[j]<a[i])j++;
        if(j<n&&b[j]>=a[i])cnt++;
        i++;
        j++;
       }
       ll ans=0;
       for(int i=0;i<cnt;i++){
        ans+=n;
        n--;
       }
       cout<<ans<<"\n";
    }

    return 0;
}