
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int  main(){
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t=1;
    cin>>t;
    while(t--){
        ll  n;cin>>n;
        ll  root;
        map<ll ,vector<ll >>adj;
        ll  val[n+1];
        memset(val,0,sizeof(val));
        for(ll  i=1;i<=n;i++){
            ll  x;cin>>x;
            if(x==i){root=i;continue;}
            adj[x].push_back(i);
        }
        ll  p[n];
        for(ll  i=0;i<n;i++)cin>>p[i];
        val[p[0]]=0;
        ll total_sum=0;
        for(int i=1;i<n;i++){
            val[p[i]]=total_sum+1;
            total_sum+=val[p[i]];
        }
        bool flg=true;
        ll dist[n+1],lvl[n+1];
        memset(dist,0,sizeof(dist));
        memset(lvl,0,sizeof(lvl));
        dfs(root,0,0,0);
        
        function<void (ll ,ll,ll ,ll)>dfs=[&](ll  node,ll  par,ll dst,ll l){
            dist[node]=dst;
            lvl[node]=l;
            for(auto child:adj[node]){
                if(child!=par){
                    dfs(child,par,dst+val[child],l+1);
                }
            }
            
        };
        // cout<<root<<endl;
        // for(ll  i=1;i<=n;i++)cout<<val[i]<<" ";
        // cout<<endl;
        dfs(root,0,0,0);
        for(int i=1;i<n;i++){
            if(dist[p[i-1]]>=dist[p[i]]){flg=false;break;}
        }
        
        if(flg){
            for(ll  i=1;i<=n;i++)cout<<val[i]<<" ";
        }
        else cout<<-1;
        cout<<endl;
    }

    return 0;
}