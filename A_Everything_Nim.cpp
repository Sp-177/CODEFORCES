#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    set<int>s;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        s.insert(x);
    }
    if(s.size()==1){cout<<"Alice"<<endl;return;}
    if(s.size()==2){
        auto it=s.begin();
        if(*it==1)cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
        return;
    }
    int cnt=s.size();
    int ply=0;
   
    for(auto i:s){
        cout<<i<<' ';
    }
    cout<<endl;
    int sum=0;
    while(s.size()){
        cout<<sum<<' ';
        int x=*s.begin();
        s.erase(s.begin());
        cnt--;
        if(!cnt)break;

        ply=!ply;
        if(x==1){
            sum+=1;
            continue;
        }
        x-=sum;
       if(x==1){
            sum+=1;
            continue;
        }
        int y=*s.begin();
         y-=sum;
        
        if(cnt==1){
            if(x!=1){s.insert(1);sum+=(x-1);continue;}
        }
        if(y-x!=1){
            sum+=(x-1);
            s.insert(1);
        }else{
            if(cnt&1){sum+=(x-1);s.insert(1);}
            else sum+=x;}
        
    }
    cout<<endl;
    if(!ply)cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}
int main() {
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}