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
int n;cin>>n;
string str;cin>>str;
set<char>st(str.begin(), str.end());
int low=1,high=n,ans=st.size();
auto predicate_funct=[&](int mid)->int{
    int cnt=0;
    map<char,int>mp;
    for(int i=0;i<mid;i++)mp[str[i]]++;
    cnt=mp.size();
    for(int i=mid;i<n;i++){
        mp[str[i-mid]]--;
        mp[str[i]]++;
        if(mp[str[i-mid]]==0)mp.erase(str[i-mid]);
        cnt=max(cnt,int(mp.size()));
    }
    return cnt;

};
while(low<=high){
    int mid=(low+high)>>1;
    int new_ans=predicate_funct(mid);
    if(new_ans>=ans){
        ans=new_ans;
        high=mid-1;
    }
    else low=mid+1;
}

cout<<low<<endl;

return 0;
}