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
    long long n;cin>>n;
    long long arr[n];
    for(long long i=0;i<n;i++)cin>>arr[i];
    auto predicate_func=[&](long long x)->bool{
        long long new_arr[n],carry[n];
        fill(carry,carry+n,0LL);
        copy(arr,arr+n,new_arr);
        for(int i=n-1;i>=2;i--){
            long long left=max(0LL,x-carry[i]);
            long long can_give=max(0LL,new_arr[i]-left);
            long long d=can_give/3;
            // cout<<x<<endl;
            // cout<<carry[i]<<" "<<left<<" "<<can_give<<" "<<d<<endl;
            new_arr[i]-=3*d;
            carry[i-1]+=d;
            carry[i-2]+=2*d;
        }
        for(int i=0;i<n;i++)new_arr[i]+=carry[i];


        return ((*min_element(new_arr,new_arr+n))>=x);
    };
    long long low=0,high=1e18;
    while(low<=high){
        long long mid=(low+high)/2;
        if(predicate_func(mid)){
            low=mid+1;
        }
        else high=mid-1;
    }
    cout<<high<<endl;
}

return 0;
}