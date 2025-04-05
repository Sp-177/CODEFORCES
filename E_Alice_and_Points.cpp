 #include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;cin>>n;
    set<vector<long long>>s;
    map<long long,long long>x,y;
    for(long long i=0;i<n;i++){
        long long a,b;cin>>a>>b;
        x[a]++;
        y[b]++;
        s.insert({a,b});
    }
    long long ans=0;
    for(auto i:s){
        long long a=i[0],b=i[1];
        ans+=linex*liney;
        long long linex=x[a]-1;
        long long liney=y[b]-1;
        
    }
    cout<<ans<<endl;


return 0;
}