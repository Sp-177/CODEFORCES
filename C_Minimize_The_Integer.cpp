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
    string str;cin >> str;
    string even="",odd="";
    for(int i=0; i<str.length();i++){
        int num=str[i]-'0';
        if(num%2==0)even+=to_string(num);
        else odd+=to_string(num);
    }
    string ans="";
    int n=even.length(),m=odd.length(),index_eve=0,index_odd=0;
    while(index_eve<n&&index_odd<m){
        int num1=even[index_eve]-'0';
        int num2=odd[index_odd]-'0';
        if(num1<num2){
            ans+=to_string(num1);
            index_eve++;
        }
        else{
            ans+=to_string(num2);
            index_odd++;
        }
    }
    while(index_eve<n){ans+=even[index_eve++];}
    while(index_odd<m){ans+=odd[index_odd++];}
    cout<<ans<<endl;

}

return 0;
}