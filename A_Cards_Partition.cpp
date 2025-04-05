#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin >> t;
    while(t--){
        long long n,k;cin>>n>>k;
        long long arr[n];
        long long sum=0,maxi=0;
        for(long long i=0;i<n;i++){long long x;cin>>x;
        arr[i]=x;
        sum+=x;
        maxi=max(maxi,x);}
        long long ans=0;
        for(long long i=1;i<=n;i++){
            long long dist=max(maxi,((sum+i-1LL)/i));
            long long total=dist*i;
            if(total<=sum+k){
                ans=max(ans,i);
            }
        }
        cout<<ans<<endl;

    }


return 0;
}