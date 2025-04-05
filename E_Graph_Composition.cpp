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
int t;cin >> t;

while(t--){
    int n,m1,m2,ans=0;cin >> n >> m1 >> m2;
   map<int,set<int>>f,g;
   for(int i=0;i<m1;i++){
    int x,y;cin>>x>>y;f[x].insert(y);
    f[y].insert(x);
   }
   for(int i=0;i<m2;i++){
    int x,y;cin>>x>>y;g[x].insert(y);
    g[y].insert(x);
   }
   for(auto i:g){
    for(int j:i.second){
        if(f[i.first].find(j)==f[i.first].end()){
            ans++;
            f[i.first].insert(j);
            f[j].insert(i.first);
        }
    }
   }
    for(auto i:f){
        if(g.find(i.first) != g.end()){
            for(int j:i.second){
                if(g[i.first].find(j)==g[i.first].end()){
                    ans++;
                }
            }
        }
    }
    
    if(m2==0)ans+=m1;
    cout<<ans<<endl;
}                     


return 0;
}