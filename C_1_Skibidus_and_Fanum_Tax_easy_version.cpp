
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
        int n,m;cin>>n>>m;
        int a[n],b;
        for(int i=0;i<n;i++)cin>>a[i];
        cin>>b;
        int c[n];
        for(int i=0;i<n;i++)c[i]=a[i];
        bool fl=true;
        c[0]=min(b-c[0],c[0]);
        for(int i=1;i<n;i++){
            if(c[i-1]<=c[i]){
                if((c[i]>b-c[i])&&(c[i-1]<=(b-c[i])))c[i]=b-c[i];
            }
            else{
                c[i]=b-c[i];
            }
            if(c[i-1]>c[i]){
                fl=false;
                break;
            }
        }
        
        if(fl)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}