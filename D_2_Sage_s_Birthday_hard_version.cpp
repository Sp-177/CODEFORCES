#include<iostream>
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/pb_ds/priority_queue.hpp>
// using namespace __gnu_pbds;	

using namespace std;

int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
int n;cin>>n;
int arr[n];
for(int i=0; i<n; i++)cin>>arr[i];
sort(arr,arr+n);

vector<int> ans(n,-1);
set<int>index;
for(int i=0;i<n;i++)index.insert(i);
int ind1=0;
for(int i=1;i<n;i+=2){
    ans[i]=arr[ind1];
    index.erase(ind1);
    ind1++;
}
for(int i=0;i<n;i++){
    if(ans[i]==-1){
        ans[i]=arr[*index.begin()];
        index.erase(*index.begin());
    }
}

int sum=0;
for(int i=1;i<n-1;i++){
    if(ans[i-1]>ans[i]&&ans[i]<ans[i+1])sum++;
}
cout<<sum<<endl;
for(int i:ans)cout<<i<<" ";
cout<<endl;
return 0;
}