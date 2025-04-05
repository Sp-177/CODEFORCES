#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int  main() {
    ll n;cin>>n;
    ll arr[n+1];
    arr[0]=0;
    for(ll i=1;i<=n;i++)cin>>arr[i];
    map<ll,vector<ll>>adj;
    for(ll i=1;i<n;i++){
        ll u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll total=0;
    for(auto i:arr)total+=i;
    // cout<<total<<endl;
    ll sub_tree_sum[n+1];
    ll ans[n+1];
    ans[0]=0;
    sub_tree_sum[0]=0;
    memset(ans,0,sizeof(ans));
    function<void(ll,ll,ll)>dfs1=[&](ll node,ll parent,ll depth){
        sub_tree_sum[node]=arr[node];
        ans[1]+=(depth)*arr[node];
        for(ll child:adj[node]){
            if(child!=parent){
                dfs1(child,node,depth+1);
                sub_tree_sum[node]+=sub_tree_sum[child];
            }
        }
        
    };
    
    function<void(ll,ll)>dfs2=[&](ll node,ll parent){
        if(node!=1){
            ans[node]=ans[parent]+total-2*sub_tree_sum[node];
        }
        for(ll child:adj[node]){
            if(child!=parent){
                dfs2(child,node);
            }
        }

    };
    dfs1(1,0,0);
    dfs2(1,0);
    // for(ll  i:sub_tree_sum)cout<<i<<" ";
    // cout<<endl;
    // for(ll  i:ans)cout<<i<<" ";
    // cout<<endl;
    cout<<*max_element(ans,ans+n+1)<<endl;
    return 0;
}
