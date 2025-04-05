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
string s,t;cin>>s>>t;
int first[t.size()],last[t.size()];
int t_index=0;
for(int i=0;i<s.size()&&t_index<t.size();i++){
    if(t[t_index]==s[i]){first[t_index]=i;t_index++;}
}
t_index=t.size()-1;
for(int i=s.size()-1;i>=0&&t_index>=0;i--){
    if(t[t_index]==s[i]){last[t_index]=i;t_index--;}
}
int n=s.size(),m=t.size();
int ans=max(n-first[m-1]-1,last[0]);
for(int i=0;i<m-1;i++){
    ans=max(ans,last[i+1]-first[i]-1);
}
cout<<ans<<endl;

return 0;
}