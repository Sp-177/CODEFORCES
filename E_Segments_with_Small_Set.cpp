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

long long arr[n];
for(long long i=0; i<n; i++)cin>>arr[i];
if(k==0){cout<<0<<endl;return 0;}

auto solve=[&](long long window)->long long{
if(window==0){return 0;}
map<long long,long long>mp;
long long start=0,end=0,ans=0;
while(end<n){
     mp[arr[end]]++;
    while(mp.size()>window&&end>start){
        mp[arr[start]]--;
        if(mp[arr[start]]==0)mp.erase(arr[start]);
        start++;
    }
    if(mp.size()<=k)ans+=end-start+1;
    end++;

}
return ans;
};

long long num1=solve(k);
// long long num2=solve(k-1);

cout<<(num1)<<endl;

return 0;
}