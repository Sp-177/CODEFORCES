#include<iostream>
#include <bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/pb_ds/priority_queue.hpp>
// using namespace __gnu_pbds;	
// // **1. Ordered Set**
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// // **2. Ordered Map**
// template <typename Key, typename Value>
// using ordered_map = tree<Key, Value, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;
// // **3. Hash Table (gp_hash_table)**
// template <typename Key, typename Value>
// using hash_table = gp_hash_table<Key, Value>;
// // **4. Priority Queue**
// template <typename T>
// using pbds_priority_queue = __gnu_pbds::priority_queue<T, greater<T>, pairing_heap_tag>; // Min-Heap

using namespace std;

int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
long long  n,k;cin >> n >> k;
long long  arr[2*n];
long long  sum=0;
for(long long  i=0;i<n;i++){cin >> arr[i];sum += arr[i];}
long long index=n;
for(long long  i=0;i<n;i++){arr[index++]=arr[i];}
long long  ans=0;
if(sum<=k)ans=k/sum;
k%=sum;
index=0;
// cout<<k<<endl;
long long  low=0,high=n;
auto predicate_func=[&](long long  x)->pair<bool,long long >{
    long long  cnt=0;
    for(int i=0;i<x;i++){
        cnt+=arr[i];
    }
    for(int i=x;i-x<n;i++){
        if(cnt>=k)return {true,i-x};
        cnt+=arr[i];
        cnt-=arr[i-x];
        
    }
    return {false,0};

};
while(low<=high){
    long long  mid=(low+high)/2;
    auto pr=predicate_func(mid);
    if(pr.first){
        high=mid-1;
        index=pr.second;
    }
    else low=mid+1;
}
// cout<<low<<endl;
ans=ans*n +low;
cout<<index+1<<" "<<ans<<endl;
return 0;
}