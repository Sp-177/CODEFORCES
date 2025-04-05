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
        
        long long last=arr[0];
        for(int i=1;i<n;i++){
            last=(last+arr[i]*1LL)/2;
        }
        cout<<last<<endl;
    }
}