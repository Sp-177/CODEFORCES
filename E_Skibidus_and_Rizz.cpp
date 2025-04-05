
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
        ll n,m,k;cin>>n>>m>>k;
        ll cnt0=n,cnt1=m,c0=0,c1=0;
        bool fl=(abs(n-m)<=k&&(n>=k||m>=k))?true:false;
        string str="";
        int last_i=0;
        for(int i=0;i<n+m;){
            if(cnt0>cnt1&&c0==0||(cnt1==0)){
            for(int j=0;j<min(k,cnt0);j++){
                str+="0";
                c0++;
                c1=0;
                i++;
            }
            cnt0-=min(k,cnt0);
            for(int j=0;j<min(k,cnt1);j++){
                str+="1";
                c1++;
                c0=0;
                i++;
            }
            cnt1-=min(k,cnt1);}
            else if(cnt1>cnt0&&c1==0||(cnt0==0)){
                
                for(int j=0;j<min(k,cnt1);j++){
                    str+="1";
                    c1++;
                    c0=0;
                    i++;
                }
                cnt1-=min(k,cnt1);
                for(int j=0;j<min(k,cnt0);j++){
                    str+="0";
                    c0++;
                    c1=0;
                    i++;
                }
                cnt0-=min(k,cnt0);
            }
            if(c0>k||c1>k||i==last_i){fl=false;break;}

        }
        if(fl)cout<<str<<endl;
        else cout<<-1<<endl;
    }

    return 0;
}