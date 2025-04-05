#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int t;cin>>t;
while(t--){
    int n;cin>>n;
    long long a[n],b[n],pre[n],dist[n];
    for(int i=0;i<n;i++){cin>>a[i];dist[i]=LLONG_MAX;}
    pre[0]=a[0];
    for(int i=0;i<n;i++){cin>>b[i];if(i-1>=0)pre[i]=pre[i-1]+a[i];}
    dist[0]=0LL;
    priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>>pq;
    
    pq.push({0,0});
    while(pq.size()>0){
        long long node = pq.top()[1];
        long long dis = pq.top()[0];
        dist[node]=min(dist[node],dis);
        long long next=b[node]-1;
        pq.pop();
        if(dis+a[node]<dist[next]){
        if(node-1>=0 &&dis<dist[node-1]){
            pq.push({dis+a[node],next});
        }
            pq.push({dis,node-1});
        }
        
    }
    long long ans=0;
    for(int i=0;i<n;i++){
    ans=max(ans,pre[i]-dist[i]);
    }
    cout<<ans<<endl;
    

   

}

return 0;
}