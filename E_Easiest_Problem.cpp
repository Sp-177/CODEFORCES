
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
        
        string s;cin>>s;
        vector<int>ind1,ind0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')ind1.push_back(i);
            else ind0.push_back(i);
        }
        int ans1=0,ans2=0;
        for(int i=1;i<ind1.size();i++){
            int last_ind=ind1[i-1];
            int curr=ind1[i];
            int cnt=curr-last_ind;
            if(cnt>=4)ans1+=cnt-2;
            else ans1++;


        }
        int c0=0;
        if(ind1.size())for(int i=ind1.back();i<n;i++)if(s[i]=='0')c0++;
        if(c0>1)ans1+=c0-1;
        for(int i=1;i<ind0.size();i++){
            int last_ind=ind0[i-1];
            int curr=ind0[i];
            int cnt=curr-last_ind;
            if(cnt>=4)ans2+=cnt-2;
            else ans2++;


        }
        int c1=0;
        if(ind0.size())for(int i=ind0.back();i<n;i++)if(s[i]=='1')c1++;
        if(c1>1)ans2+=c1-1;
        cout<<max(ans1,ans2)<<endl;
    }

    return 0;
}