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
long long n,c;cin>>n>>c;
string  str;cin>>str;
auto predicate_func=[&](long long window)->bool{
    long long cnt_a=0,cnt_b=0,sum=0;
    for(long long i=0;i<window;i++){
        if(str[i]=='a')cnt_a++;
        else if(str[i]=='b'){
            sum+=cnt_a;
            cnt_b++;
        }
    }
    if(sum<=c)return true;
    for(long long i=window;i<n;i++){
        if(str[i-window]=='a'){cnt_a--;sum-=cnt_b;}
        else if(str[i-window]=='b')cnt_b--;
        if(str[i]=='a')cnt_a++;
        else if(str[i]=='b'){
            sum+=cnt_a;
            cnt_b++;
        }
        if(sum<=c)return true;
            }
    return false;
};
long long low=1,high=n;
while(low<=high){
    long long mid=(low+high)/2;
    if(predicate_func(mid))low=mid+1;
    else high=mid-1;
}
cout<<high<<endl;


return 0;
}