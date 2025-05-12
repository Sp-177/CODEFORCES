
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t=1;
    // cin>>t;
    while(t--){
        int n;cin>>n;
        vector<string>vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        vector<int>indegree(26,0);
        unordered_map<int,vector<int>>mp;
        bool flag=true;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<vec[i].size();j++){
                if(j>=vec[i+1].size()){
                    // cout<<i<<" "<<j<<endl;   
                    flag=false;
                    break;
                }
                if(vec[i][j]!=vec[i+1][j]){
                    mp[vec[i][j]-'a'].push_back(vec[i+1][j]-'a');
                    indegree[vec[i+1][j]-'a']++;
                    break;
                }
            }
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<26;i++){
            if(indegree[i]==0){
                pq.push(i);
            }
        }
        string ans="";
        while(pq.size()){
            int x=pq.top();
            pq.pop();
            ans+=x+'a';
            for(auto it:mp[x]){
                indegree[it]--;
                if(indegree[it]==0){
                    pq.push(it);
                }
            }
        }
        if(ans.size()!=26||(flag==false)){
            cout<<"Impossible"<<endl;
        }
        else{
            cout<<ans<<endl;
        }


    }

    return 0;
}