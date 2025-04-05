
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t=1;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        int mini=*min_element(arr,arr+n);
        int ans=0;
        for(int i=0;i<n;i++){
            if(arr[i]==mini){
                break;
            }
            ans++;
        }
        bool check=false;
        for(int i=ans+1;i<n;i++){
            if(arr[i-1]>arr[i]){
                check=true;
                break;
            }
        }
        if(check)cout<<-1;
        else cout<<ans;
        cout<<"\n";
    }

    return 0;
}