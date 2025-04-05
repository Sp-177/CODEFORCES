#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int arr1[n+1];
    for(int i=0;i<n;i++){
        int x;cin>>x;
        arr1[x]=i;
    }
    int ans=0;
    for(int i=n-1;i>=0;i--){
        int x=arr[i];
        if(i+ans!=arr1[x]){
            ans++;
        }
    }
    cout<<ans<<endl;
}
 int main(){

    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
 }