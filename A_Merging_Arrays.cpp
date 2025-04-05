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
int n,m;cin >> n >> m;
int a[n],b[m];
for(int i=0;i<n;i++)cin>>a[i];
for(int i=0;i<m;i++)cin>>b[i];
int index_a=0,index_b=0;
while(index_a<n&&index_b<m){
    while(index_a<n&&a[index_a]<=b[index_b]){cout<<a[index_a]<<" ";index_a++;}
    while(index_b<m&&index_a<n&&b[index_b]<=a[index_a]){cout<<b[index_b]<<" ";index_b++;}
}
while(index_a<n){cout<<a[index_a++]<<" ";}
while(index_b<m){cout<<b[index_b++]<<" ";}
return 0;
}