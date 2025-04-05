
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t=1;
    cin>>t;
    while(t--){
     int n;cin>>n;
     map<int,int>mp;
     for(int i=0;i<n;i++){
        int x;cin>>x;
        mp[x]++;
     }
     bool flg=true;
     for(int i=1;i<=1000;i++){
         if(mp.find(i)==mp.end())continue;
        int freq=mp[i];
        int num=i;
        if(freq==1){
            flg=false;
            break;
        }
        else if(freq>2){
            mp[num+1]+=freq-2;
        }

     }

     if(flg)cout<<"Yes";
     else cout<<"No";
     cout<<"\n";
    }

    return 0;
}