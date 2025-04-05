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
    int n,k;cin>>n>>k;
    int arr[n];
    map<int,int>mp1,mp2;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        mp1[x]++;
        mp2[x]++;
        arr[i]=x;
    }
    int cnt_unp=n,cnt_p=0;
    for(int i=0;i<n;i++){
        int pr=k-arr[i];
        if(mp2[pr]>0){
            cnt_p++;
            cnt_unp-=2;
            mp2[pr]--;
        }
    }
    cout<<cnt_p/2<<endl;

}

return 0;
}