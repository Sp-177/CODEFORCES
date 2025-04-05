#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
long long t;cin >> t;
while(t--){
    long long n;
    cin>>n;
    long long arr[n];
    for(long long i=0;i<n;i++)cin>>arr[i];
    long long dp[n],maxi[n+1];
    memset(dp,0LL,sizeof(dp));
    
    for(long long i=n;i>=1;i--){
        long long ans=1LL;
        for(long long j=i;j<=n;j+=i){
            if(arr[i-1]<arr[j-1]){
                ans=max(ans,dp[j-1]+1LL);
            }
        }
        dp[i-1]=ans;
        
        
    }
    cout<<*max_element(dp,dp+n)<<endl;
}

return 0;
}