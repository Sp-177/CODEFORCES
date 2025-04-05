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
#define ll long long

int  main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
ll  t;cin>>t;
while(t--){
    ll  n;cin>>n;
    vector<ll >eve,odd;
    for(ll  i=0;i<n;i++){
        ll  x;cin>>x;
        if(x%2==0)eve.push_back(x);
        else odd.push_back(x);
    }
    ll  ans=0;
    ll  ind=0,eve_ind=0,odd_ind=0,sum=0;
    while(ind<n){
        if(sum&1){
            if(odd_ind<odd.size()){
                ans++;
                odd_ind++;
                sum=1;
            }
            else{
                eve_ind++;
                ind++;
            }
        }
        else{
            if(eve_ind<eve.size()){
                ans++;
                eve_ind++;
                sum=1;
            }
            else{
                odd_ind++;
                sum=1;
                ind++;
            }

        }
    }
    cout<<ans<<endl;
}

return 0;
}