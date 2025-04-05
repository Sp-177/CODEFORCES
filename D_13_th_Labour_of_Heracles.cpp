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
ll t;cin>>t;
while(t--){
    ll n;cin>>n;
    vector<pair<ll,ll>>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second=i+1;
    }
    sort(arr.rbegin(),arr.rend());
    map<ll,vector<ll>>mp;
    for(ll i=1;i<n;i++){
        ll u,v;cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    ll sum=0;
    for(ll i=0;i<n;i++)sum+=arr[i].first;
    ll ans[n-1];
    ans[0]=sum;
    ll index=1,maxi_ind=0;
    while(index<n-1){
        ll cnt=mp[arr[maxi_ind].second].size()-1;
        // cout<<cnt<<" "<<arr[maxi_ind].first<<" "<<index<<endl;
        while(cnt>0){
            ans[index]=ans[index-1]+arr[maxi_ind].first;
            cnt--;
            index++;
        }
        maxi_ind++;
    }
    for(ll i=0;i<n-1;i++)cout<<ans[i]<<" ";
    cout<<endl;
}

return 0;
}