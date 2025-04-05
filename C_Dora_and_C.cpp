#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int t;cin>>t;
while(t--){
    int n,a,b;cin>>n>>a>>b;
    int con=__gcd(a,b);
    int arr[n];
    for(int i=0;i<n;i++){cin>>arr[i];arr[i]%=con;}
    sort(arr,arr+n);
    int ans=arr[n-1]-arr[0];
    int small=1;
    for(int i=0;i<n-1&&small<n;i++){
        int big=arr[i]+con;
        ans=min(ans,big-arr[small]);
        small++;
    }
    cout<<ans<<endl;
    
}

return 0;
}