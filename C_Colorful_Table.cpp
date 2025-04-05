#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int t;cin>>t;
while(t--){
    int n,k;cin>>n>>k;
    map<int,vector<int>>ma;
    int arr[n];
    for(int i=0;i<n;i++){cin>>arr[i];ma[arr[i]].push_back(i);}
    vector<int>ans(k+1,0);
    int mini=INT_MAX,maxi=INT_MIN;
    for(int i=k;i>=1;i--){
        if(ma[i].size()){
            mini=min(mini,ma[i][0]);
            maxi=max(maxi,ma[i].back());
            ans[i]=2*(maxi-mini+1);
        }
    }
    for(int i=1;i<=k;i++)cout<<ans[i]<<' ';
    cout<<endl;
}

return 0;
}