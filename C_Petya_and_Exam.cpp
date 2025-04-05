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
    long long n,T,a,b;cin>>n>>T>>a>>b;
    pair<long long,long long> arr[n];
    for(long long i=0;i<n;i++)cin>>arr[i].second;
    for(long long i=0;i<n;i++)cin>>arr[i].first;
    sort(arr,arr+n);
    long long cnt_easy=0,cnt_hard=0,ans=0;
    for(long long i=0;i<n;i++){
        if(arr[i].second==0)cnt_easy++;
        else cnt_hard++;
    }
    // for(long long i=0;i<n;i++)cout<<arr[i].first<<"  ";
    // cout<<endl;
    // for(long long i=0;i<n;i++)cout<<arr[i].second<<" ";
    // cout<<endl;
        
    long long index=0,pending_easy=0,pending_hard=0;
    while(index<n){
        long long last_time=arr[index].first;
        long long total_time=pending_easy*a+pending_hard*b;
        long long cnt_total=pending_easy+pending_hard;
        if(total_time<last_time){
            long long left_easy=cnt_easy-pending_easy;
            long long left_hard=cnt_hard-pending_hard;
            long long extra=last_time-1-total_time;
            if(left_easy>0 ){
                long long can_easy=min(extra/a,left_easy);
                total_time+=can_easy*a;
                cnt_total+=can_easy;
            }
            extra=last_time-1-total_time;
            if(left_hard>0){
                long long can_hard=min(extra/b,left_hard);
                total_time+=can_hard*b;
                cnt_total+=can_hard;
            }
            ans=max(ans,cnt_total);
        }
        if(arr[index].second==0)pending_easy++;
        else pending_hard++;
        index++;
    }
        pending_easy=cnt_easy;
        pending_hard=cnt_hard;
        long long last_time=T;
        long long total_time=pending_easy*a+pending_hard*b;
        long long cnt_total=pending_easy+pending_hard;
        if(total_time<=last_time){
           ans=max(ans,cnt_total);
        }
        
    cout<<ans<<endl;
    
}

return 0;
}