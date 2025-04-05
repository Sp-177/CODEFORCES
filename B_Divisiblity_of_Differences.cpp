
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int  main(){
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t=1;
    // cin>>t;
    while(t--){
        ll  n,k,m;cin>>n>>k>>m;
        map<ll ,vector<ll >>mp;
        for(ll  i=0;i<n;i++){
            ll  x;cin>>x;
            // cout<<x<<" "<<x%m<<endl;
            mp[x%m].push_back(x);
        }
        // for(auto x:mp){
        //     cout<<x.first<<" -> ";
        //     for(auto y:x.second){
        //         cout<<y<<' ';
        //     }
        //     cout<<endl;

        // }
        vector<ll >ans;
        for(auto i:mp){
            ll sz=i.second.size();
            if(sz>=k){
                for(ll  j=0;j<sz;j++){
                    if(ans.size()<k){
                    ans.push_back(i.second[j]);}
                }
                break;
            }
        }
        if(ans.size()<k)cout<<"No"<<endl;
        else{
            cout<<"Yes"<<endl;
            for(ll  i:ans)cout<<i<<' ';
            cout<<endl;
        }
}


    return 0;
}