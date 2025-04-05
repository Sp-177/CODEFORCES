#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int t;cin>>t;
while(t--){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    int first=arr[0],second=arr[n-1];
    long long ans=0;
    for(int i=1;i<n;i++){
        ans+=second-first;
    }
    cout<<ans<<endl;
}

return 0;
}