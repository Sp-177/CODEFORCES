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
long long n,m,s,A,B;cin>>n>>m>>s>>A>>B;
vector<long double>a(n);for(long long i=0;i<n;i++)cin>>a[i];
vector<long double>b(m);for(long long i=0;i<m;i++)cin>>b[i];
sort(a.rbegin(),a.rend());
sort(b.rbegin(),b.rend());
long long index_a=0,index_b=0,total_weight=0,total_value=0;
for(auto i:a)cout<<i<<" ";
cout<<endl;
for(auto i:b)cout<<i<<" ";
cout<<endl;
while(index_a<n&&index_b<m&&total_weight<=s){
    long double i1=a[index_a],i2=b[index_b];
    long double ratio1=i1*1.0/A,ratio2=i2*1.0/B;
    cout<<ratio1<<" "<<ratio2<<endl;
    if(ratio1>ratio2){
        if(total_weight+A<=s){
            total_weight+=A;
            total_value+=i1;
            index_a++;
        }
        else if(total_weight+B<=s){
            total_value+=B;
            total_value+=i2;
            index_b++;
        }
        else break;
    }
    else if(ratio1==ratio2){
        long long mini=max(A,B);
        if(total_weight+mini<=s){
            total_weight+=mini;
            total_value+=(mini==A?i1:i2);
            if(mini==A)index_a++;
            else index_b++;
        }
        else break;
    }
    else{
        if(total_weight+B<=s){
            total_weight+=B;
            total_value+=i2;
            index_b++;
        }
        else if(total_weight+A<=s){
            total_value+=A;
            total_value+=i1;
            index_a++;  
        }
        else break;
    }
}
while(index_a<n&&total_weight<=s){
    if(total_weight+A<=s){
        total_weight+=A;
        total_value+=a[index_a];
        index_a++;
    }
    else break;
}
while(index_b<n&&total_weight<=s){
    if(total_weight+B<=s){
        total_weight+=B;
        total_value+=b[index_b];
        index_b++;
    }else break;
}
cout<<total_value<<endl;
return 0;
}