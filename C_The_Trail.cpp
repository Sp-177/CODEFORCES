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
int t;cin>>t;
while(t--){
    ll n,m;cin>>n>>m;
    string str;cin>>str;
    ll mat[n][m];
    for(ll i=0;i<n;i++)for(ll j=0;j<m;j++)cin>>mat[i][j];
    ll row[n],col[m];
    memset(row,0LL,sizeof(row));
    memset(col,0LL,sizeof(col));
    for(ll i=0;i<n;i++){

        for(ll j=0;j<m;j++){
            row[i]+=mat[i][j];
            col[j]+=mat[i][j];
        }
    }
    int r=0,c=0;
    for(char i:str){
        if(i=='D'){
            mat[r][c]=-row[r];
            col[c]-=row[r];
            r++;
        }
        else{
            mat[r][c]=-col[c];
            row[r]-=col[c];
            c++;
        }
    }
    if(str.back()=='D')mat[r][c]=-row[r];
    else mat[r][c]=-col[c];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }


}

return 0;
}