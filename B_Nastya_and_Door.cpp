#include<iostream>
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/pb_ds/priority_queue.hpp>
// using namespace __gnu_pbds;	
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using namespace std;

int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
int t;cin>>t;
while(t--){
    int n,k;cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int prefix[n+1];
    memset(prefix,0,sizeof(prefix));
    for(int i=1;i<n-1;i++){
        if(arr[i-1]<arr[i]&&arr[i]>arr[i+1])prefix[i]=1;
        prefix[i]+=prefix[i-1];
    }
    // for(int i:prefix)cout<<i<<" ";
    // cout<<endl;
    int num_peaks=0,index=0;
    for(int i=k-1;i<n;i++){
        int last=i-k+1;
        int cnt=prefix[i-1]-(last<0?0:prefix[last])+1;
        if(cnt>num_peaks){
            num_peaks=cnt;
            index=last;
        }
    }
    cout<<num_peaks<<" "<<(index+1)<<endl;
}

return 0;
}