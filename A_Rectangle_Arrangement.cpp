#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){

int t;cin>>t;
while(t--){
    int n;cin>>n;
    vector<vector<int> > v;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),greater<vector<int> >());
    long long ans=0;
    long long last_x=v[0][0],last_y=v[0][1];
    
    ans+=2*last_x+2*last_y;
    for(int i=1;i<v.size();i++){
        if(v[i][1]>last_y){
            ans+=2*(abs(v[i][1]-last_y));
            last_y=v[i][1];
        }
    }
    cout<<ans<<endl;

}
return 0;
}