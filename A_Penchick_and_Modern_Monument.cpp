#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    long long t;cin>>t;
    while(t--){
        long long n;cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        long long cnt=0;
        map<long long,long long>m;
        long long maxi=0;
        for(auto  i:arr){m[i]++;maxi=max(maxi,m[i]);}
        cout<<n-maxi<<endl;
        
    }

}