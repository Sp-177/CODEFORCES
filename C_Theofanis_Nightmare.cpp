#include<iostream>
#include<bits/stdc++.h>
    // cout<<index<<" "<<fac<<endl;
using namespace std;


int main(){
int  t;cin>>t;
while(t--){
    int n;cin>>n;
    long long arr[n],suffix[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    long long sum=0,ans=0;
    suffix[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)suffix[i]=suffix[i+1]+arr[i];
    long long cnt=1;
    bool first=true;
    for(int i=0;i<n;i++){
        if(suffix[i]<0){
            ans+=cnt*arr[i];
        }else{
            if(i==0){ans+=cnt*arr[i];continue;}
            cnt++;
            ans+=cnt*arr[i];
        }
    }
    // reverse(arr,arr+n);
    // for(int i=0;i<n;i++){
    //     sum+=arr[i];
    //     if(i==n-1)ans+=sum;
    //     else if(sum>=0)ans+=sum;
    // }
    cout<<ans<<endl;
}

return 0;
}