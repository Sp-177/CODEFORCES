
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
        int grid[n][n];
        map<int,int>perm;
        set<int>st;
        for(int i=1;i<=2*n;i++){            
            st.insert(i);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>grid[i-1][j-1];
                int pos=i+j;
                perm[pos]=grid[i-1][j-1];
                st.erase(grid[i-1][j-1]);
            }
        }
        // for(auto i:perm){
        //     cout<<i.first<<" "<<i.second<<" "<<endl;
        // }
        vector<int>ans;
        for(int i=1;i<=2*n;i++){
            if(perm.find(i)==perm.end()){
                ans.push_back(*st.begin());
            }
            else{
                ans.push_back(perm[i]);
            }
        }
        for(int i:ans)cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}