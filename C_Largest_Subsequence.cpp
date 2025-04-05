#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Compare {
    public:
       bool operator()(pair<char,int>&a,pair<char,int>&b){
           if(a.first > b.first)return false;
           if(a.first==b.first){
            return a.second>b.second;
           }
           return true;
      }
};
int main(){
int t;cin>>t;
while(t--){
    int n;cin>>n;
    string str;cin>>str;
    string sorted_str=str;
    sort(sorted_str.begin(), sorted_str.end());
    if(str==sorted_str){
        cout<<0<<endl;continue;
    }
    priority_queue<pair<char,int>,vector<pair<char,int>>,Compare>pq;
    for(int i=0;i<n;i++){
        pq.push({str[i],i});
    }
    int index=INT_MIN;
    vector<char>sub;
    vector<int>indices;
    while(!pq.empty()){
        char c=pq.top().first;
        int ind=pq.top().second;
        pq.pop();
        if(ind>index){
            sub.push_back(c);
            indices.push_back(ind);
            index=ind;
        }
    }
    int cnt=0;
    bool ans=true;
    int ind_sub=sub.size()-1;
    for(int i=sub.size()-1;i>=0;i--){
        if(sub[i]!=sub[0])cnt++;
        else break;
    }
    map<int,char>ma;
    for(int i:indices){
        ma[i]=sub[ind_sub];
        ind_sub--;
    }
    for(int i=0;i<n;i++){
        if(ma.find(i)!=ma.end()){
            if(ma[i]!=sorted_str[i]){ans=false;break;}
        }
        else {
            if(str[i]!=sorted_str[i]){ans=false;break;}
        }
    }
    if(ans)cout<<cnt<<endl;
    else cout<<-1<<endl;
    // for(auto i:sub)cout<<i<<" ";
    // cout<<endl;
    // for(auto i:indices)cout<<i<<" ";
    // cout<<endl;
    // for(auto i:ma){
    //     cout<<i.first<<" "<<i.second<<" ";
    // }
    // cout<<endl;
}

return 0;
}