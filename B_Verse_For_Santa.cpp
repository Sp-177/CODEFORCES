#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void solve(){
    int n,s;cin>>n>>s;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    priority_queue<vector<int>>pq;
    long long sum=0; 
    bool check=0;
    int ans=0;
    for(int i=0;i<n;i++){
        // cout<<sum<<" ";
        if(sum+arr[i]>s){
            if(check)break;
            if(pq.size()&&pq.top()[0]>arr[i]){
            sum-=pq.top()[0];
            ans=pq.top()[1]+1;
            check=1;}
            else{
                ans=i+1;
                check=1;
                continue;
            }
        }
        sum+=arr[i];
        pq.push({arr[i],i});
    }
    cout<<ans<<endl;
}
int main(){
    int t;cin>>t;while(t--){solve();}
    return 0;
}