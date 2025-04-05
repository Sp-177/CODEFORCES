#include<iostream>
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/pb_ds/priority_queue.hpp>
// using namespace __gnu_pbds;	

using namespace std;


int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
long long t;cin>>t;
while(t--){
    long long n,k;cin>>n>>k;
    long long arr[n];
    for(long long i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    long long prefix[n];
    prefix[0]=arr[0];
    for(long long i=1;i<n;i++)prefix[i]=arr[i]+prefix[i-1];

    auto predicate_func=[&](long long total)->bool{
        for(long long y=0;y<=n-1&&y<=total;y++){
            long long x=max(0LL,total-y);
            long long start=arr[0]-x;
            long long rem_sum=prefix[n-1LL-y]-arr[0];
            // cout<<total<<endl;
            // cout<<"  "<<x<<" "<<y<<" "<<start<<" "<<rem_sum<<" "<<rem_sum+start*(y+1)<<endl;
            if((rem_sum+start*(y+1))<=k)return true;
        }
        return false;
    };
    long long low=0,high=1e18;
    while(low<=high){
        long long mid=(low+high)/2;
        if(predicate_func(mid))high=mid-1;
        else low=mid+1;
    }
    cout<<low<<endl;
}

return 0;
}