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
    long long n,k,mod=1e9+7;cin>>n>>k;
    auto binary_expo=[&](long long b,long long exp)->long long{
    long long result=1;
    while(exp>0){
      
      if(exp&1)result*=b;
      b*=b;
      exp>>=1;
      result%=mod;
      b%=mod;
    }
    return result;
  };

    map<long long,long long>mp;
    for(long long i=0;i<n;i++){
        long long x;cin>>x;
        mp[x]++;
    }
    long long m=long (mp.size());
    pair<long long,long long> arr[m];
    long long index=0;
    for(auto i:mp){
        arr[index++]={i.first,i.second};
    }
    long long start=0,end=0,pro=1,ans=0;
    while(end<m){
        pro*=arr[end].second;
        pro%=mod;
        while(start<end&&(arr[end].first-arr[start].first)>=k){
            pro*=(binary_expo(arr[start].second,mod-2));
            pro%=mod;   
            start++;
        }
        if((end-start+1)==k){
            ans+=pro;
            ans%=mod;
            
        }
        
        end++;
    }
    cout<<ans<<endl;

}

return 0;
}