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
long long n,k;cin>>n>>k;

vector<vector<long long>>arr(n,vector<long long>(3));
for(int i=0; i<n; i++)cin>>arr[i][2]>>arr[i][1]>>arr[i][0];
sort(arr.begin(),arr.end());

auto predicate_function=[&](long long x)->bool{
    long long sum=0,from_batteries=0;
    for(int i=0; i<n; i++){
        if(arr[i][2]>x){
            sum+=arr[i][1]*(arr[i][2]-x);
            from_batteries+=(arr[i][2]-x);
        }
    }
    // cout<<x<<endl;
    // cout<<sum<<" "<<from_batteries<<endl;
    for(int i=0;i<n&&from_batteries>0;i++){
        if(arr[i][2]<x){
            long long can_move=min(x-arr[i][2],from_batteries);
            sum+=arr[i][0]*can_move;
            from_batteries-=can_move;
        }
    }
    if(from_batteries!=0)return false;
  return sum<=k;  
};
long long low=0,high=1e18;
while(low<=high){
    long long mid=(low+high)/2;
    if(predicate_function(mid)){
        high=mid-1;
    }
    else low=mid+1;
}
cout<<low<<endl;
return 0;
}