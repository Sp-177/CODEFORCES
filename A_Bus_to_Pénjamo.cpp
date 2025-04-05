#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int t;cin>>t;
while(t--){
    int n,r;cin>>n>>r;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int left=0;
    int ans=0;
    for(int i=0;i<n;i++){
        int rows=arr[i]/2;
        int extra=arr[i]%2;
        r-=rows;
        left+=extra;
        ans+=rows*2;
    }
    if(left<=r)ans+=left;
    else{
        ans+=r;
        int extra=left-r;
        ans-=extra;
    }
    cout<<ans<<endl;
}

return 0;
}