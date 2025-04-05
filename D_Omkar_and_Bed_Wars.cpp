
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
    long long n;cin>>n;
    string str;cin>>str;
    int cntl=count(str.begin(), str.end(),'L');
    if(cntl==n||cntl==0){
        cout<<(n+2)/3<<endl;continue;
    }
    int index=n-1;
    while(str[0]==str[index]){index--;}
    int curr_cnt=n-index-1,ans=0;
    char c=str[n-1];
    for(int i=0;i<=index;i++){
        // cout<<curr_cnt<<" "<<c<<endl;
        if(str[i]==c){
            curr_cnt++;

        }else{
            ans+=(curr_cnt)/3;
            c=str[i];
            curr_cnt=1;
        }
        
    }
    ans+=(curr_cnt)/3;
    cout<<ans<<endl;
}

return 0;
}
