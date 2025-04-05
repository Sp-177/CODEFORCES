#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n],arr1[n-1];
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n-1;i++){
        arr1[i]=__gcd(arr[i],arr[i+1]);
    }
    int last=arr1[n-2]; int cnt=0;
    // for(int i=0;i<n-1;i++)cout<<arr1[i]<<' ';
    // cout<<endl;
    for(int i=n-2;i>=0;i--){
        if(arr1[i]>last){cnt++;continue;}
        last=arr1[i];
        
    }
//    cout<<cnt<<endl;
    if(cnt>2){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}