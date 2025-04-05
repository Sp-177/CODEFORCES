#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool solve(){
     int n,m,q;cin>>n>>m>>q;
        int people[n],slides[m];
        for(int i=0;i<n;i++){
            cin>>people[i];
        }
        for(int j=0;j<m;j++)cin>>slides[j];
        set<int>s;
        int j=0;
        for(int i=0;i<n&&j<m;i++){
            // cout<<slides[j]<<" "<<people[i]<<endl;
            if(people[i]!=slides[j]){
                if(s.size()==0||s.find(slides[j++])==s.end()){return false;}
                i--;
            }
            else{
                s.insert(people[i]);
                j++;
            }
        }
        return true;
}
int main(){
    int t;cin>>t;
    while(t--){
       bool ans=solve();
        if(ans)cout<<"YA"<<endl;
        else cout<<"TIDAK"<<endl;
    }
}
