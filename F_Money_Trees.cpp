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
int t;cin>>t;
while(t--){
    int n,k;cin>>n>>k;
    int fruits[n],heights[n],prefix_fruits[n];
    for(int i=0;i<n;i++)cin>>fruits[i];
    for(int i=0;i<n;i++)cin>>heights[i];
    prefix_fruits[0]=fruits[0];
    for(int i=1;i<n;i++)prefix_fruits[i]=prefix_fruits[i-1]+fruits[i];
    int low=0,high=n;
    auto predicate_funct=[&](int x)->bool{
        if(x==0)return true;
        if(x==1)return ((*min_element(fruits,fruits+n))<=k);
        int start=0,end=1;
        while(end<n){
            if(end-start+1>x)start++;
            if(heights[end-1]%heights[end]!=0)start=end;
            if((end-start+1)==x){
                int sum=prefix_fruits[end]-((start-1)>=0?prefix_fruits[start-1]:0);
                if(sum<=k)return true;
            }
            end++;
        }
        return false;


    };
    while(low<=high){
        int mid=(low+high)>>1;
        if(predicate_funct(mid)){
            low=mid+1;
        }
        else high=mid-1;
    }
    cout<<high<<endl;
}

return 0;
}