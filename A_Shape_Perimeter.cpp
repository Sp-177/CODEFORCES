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
long long t;cin>>t;
while(t--){
    long long n,m;cin>>n>>m;
    long long ans=4*m;
    for(long long i=1;i<=n;i++){
        long long x,y;cin>>x>>y;
        // cout<<ans<<" "<<x<<" "<<y<<endl;
        if(i==1)continue;
        ans+=4*m;
        ans-=(2*(m-x+m-y));
        if((x)==0)ans-=2*(m-y);
        if((y)==0)ans-=2*(m-x);
    }
    cout<<ans<<endl;
}

return 0;
}