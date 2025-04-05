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
long long n,m;cin>>n>>m;
string s,t;cin>>s>>t;
long long hash_map[26];
memset(hash_map, 0, sizeof(hash_map));
for(long long i=0;i<m;i++){
    hash_map[t[i]-'a']++;
}
long long ans=0;
long long start=0,end=0;
while(end<n){
    long long index=s[end]-'a';
    hash_map[index]--;
    while(hash_map[index]<0&&start<=end){
        hash_map[s[start]-'a']++;
        start++;
    }
    if(hash_map[index]>=0){
        ans+=end-start+1;
    }
    
    end++;
}

cout<<ans<<endl;
return 0;
}