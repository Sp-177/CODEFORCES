#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
int t;cin>>t;
while(t--){
    int n;cin>>n;
    long long arr[n];

    for(int i=0;i<n;i++){cin>>arr[i];}
    if(n==1){cout<<1<<endl;continue;}
    if(n&1){
        long long ans=LLONG_MAX;
        for(int i=0;i<n;i+=2){
            long long dif1=1,dif2=1;
            for(int j=1;j<i;j+=2){
                dif1=max(dif1,abs(arr[j]-arr[j-1]));
            }
            for(int j=i+2;j<n;j+=2){
                dif2=max(dif2,abs(arr[j]-arr[j-1]));
            }
            ans=min(ans,max(dif1,dif2));
        }
        cout<<ans<<endl;
    }
    else{
        long long ans=0;
        for(int i=1;i<n;i+=2){
            ans=max(ans,abs(arr[i]-arr[i-1]));
        }
        cout<<ans<<endl;
    }
}

return 0;
}