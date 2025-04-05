#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,k;cin>>n>>m>>k;
    int a[n],b[m];
    int start=0,end=n-1;
    int cnt=1;
    
    while(start<n){
        a[start]=min(cnt,k);
        a[end]=min(cnt,k);
        if(start+k-1>=end)break;
        start++;
        end--;
        cnt++;
    }
    cnt--;
    while(start<=end){
        if(start+k-1<n)cnt++;
        a[start++]=min(cnt,k);
        a[end--]=min(cnt,k);
        
    }
    start=0,end=m-1;
    cnt=1;
     while(start<m){
        b[start]=min(cnt,k);
        b[end]=min(cnt,k);
        if(start+k-1>=end)break;
        start++;
        end--;
        cnt++;
    }
    cnt--;
    while(start<=end){
         if(start+k-1<m)cnt++;
        b[start++]=min(cnt,k);
        b[end--]=min(cnt,k);
       
    }
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<m;i++){
    //     cout<<b[i]<<" ";
    // }
    // cout<<endl;
    int l;cin>>l;
    long long arr[l];
    for(int i=0;i<l;i++){
        cin>>arr[i];
    }
    sort(arr,arr+l);
    long long arr2[n*m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr2[i*m+j]=1LL*a[i]*b[j];
        }
    }
    
    sort(arr2,arr2+n*m);
    // for(int i=0;i<n*m;i++){
    //     cout<<arr2[i]<<" ";
    // }cout<<endl;
    // for(int i=0;i<l;i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;
    long long sum=0;
    int ind=n*m -1;
    for(int i=l-1;i>=0;i--){
        long long cal=1LL*arr2[ind--]*arr[i];
        sum+=cal;
    }
    cout<<sum<<endl;
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}