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
int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
ll t;cin >> t;
while(t--){
     ll n,k;cin>>n>>k;
     map<ll,vector<ll>>adj;
     for(ll i=0;i<n-1;i++){
        ll u,v;cin >> u>>v;
     adj[u].push_back(v);
     adj[v].push_back(u);
     }
     ll low=0,high=n;
     function<ll(ll,ll,ll,ll&)>dfs=[&](ll u,ll p,ll x,ll &total){
        ll cnt_child=1;
        for(ll node:adj[u]){
            if(node!=p){
                ll c=dfs(node,u,x,total);
                if(total<k&&c>=x)total++;
                else cnt_child+=c;
            }
        }
        
        return cnt_child;
     };
     auto predicate_func=[&](ll x){
        ll total=0;
        ll child=dfs(1,-1,x,total);
        // cout<<total<<" "<<child<<endl;
        return ((total>=k)&&(child>=x));
     };
     while(low<=high){
        ll mid=(low+high)/2;
        if(predicate_func(mid)){
            low=mid+1;
        }
        else high=mid-1;
     }
     cout<<high<<endl;

}

return 0;
}