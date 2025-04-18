
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
        string p,s;cin>>p>>s;
        int np=p.size(),ns=s.size();
        int i_p=0,i_s=0;
        bool ans=true;
        while(i_p<np&&i_s<ns){
            int cnt_l_p=0,cnt_r_p=0,cnt_l_s=0,cnt_r_s=0;
            while(i_p<np&&p[i_p]=='L'){
                cnt_l_p++;
                i_p++;
            }
            while(i_s<ns&&s[i_s]=='L'){
                cnt_l_s++;
                i_s++;
            }
            if(cnt_l_s<cnt_l_p || cnt_l_s>2*cnt_l_p){
                ans=false;
                break;
            }

            cnt_l_p=0;cnt_l_s=0;
            while(i_p<np&&p[i_p]=='R'){
                cnt_r_p++;
                i_p++;
            }
            while(i_s<ns&&s[i_s]=='R'){
                cnt_r_s++;
                i_s++;
            }
            if(cnt_r_s<cnt_r_p || cnt_r_s>2*cnt_r_p){
                ans=false;
                break;
            }
            cnt_r_p=0;cnt_r_s=0;

        }
        if(ans&&(i_p==np&&i_s==ns))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}