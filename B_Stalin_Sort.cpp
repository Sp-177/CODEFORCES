#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int t;cin >> t;
while(t--){
    long long  n;cin>>n;
    long long  arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    long long ans=INT_MAX;
   for(int i=0;i<n;i++){
    long long cnt=i;
    for(int j=i+1;j<n;j++){
        if(arr[i]<arr[j]){cnt++;}
    }
    ans=min(ans,cnt);
   }
    cout<<ans<<endl;
}

return 0;
}