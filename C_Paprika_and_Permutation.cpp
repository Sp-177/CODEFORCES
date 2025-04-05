#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int t;cin>>t;
while(t--){
    int n;cin>>n;
    set<int>s;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(x>=1&&x<=n&&s.find(x)==s.end())s.insert(x);
        else v.push_back(x);
    }
    sort(v.begin(),v.end());
    int p=1;
    int ind=0;
    while(p<=n&&ind<v.size()){
        // cout<<p<<endl;
        while(s.find(p)!=s.end())p++;
        if(v[ind]==2)break;
        else if((v[ind]/2 -(v[ind]%2^1))>=p){ind++;s.insert(p);p++;}
        else break;
    }
    while(s.find(p)!=s.end())p++;
    if(p>n)cout<<ind<<endl;
    else cout<<-1<<endl;
    
}

return 0;
}