
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
        int n;cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
       vector<vector<int>>subarr;
       for(int i=0;i<n;i++){
           vector<int>temp;
        for(int j=i;j<n;j++){
            temp.push_back(arr[j]);
            subarr.push_back(temp);
        }
       }
       int size=1;
       for(auto vec:subarr){
        int cnt=1;
        for(int i=1;i<vec.size();i++){
            if(vec[i]-vec[i-1]!=vec[1]-vec[0])break;
            cnt++;
            size=max(size,cnt);

        }
       }
       cout<<n-size<<endl;
    }

    return 0;
}