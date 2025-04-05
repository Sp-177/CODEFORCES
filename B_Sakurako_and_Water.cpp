#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int t;cin>>t;
while(t--){
    int n;cin>>n;
    int ans=0;
    vector<vector<int>>v(n,vector<int>(n));
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>v[i][j];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0||j==0){
                int mini=INT_MAX;
                for(int x=i,y=j;x<n&&y<n;){
                    if(v[x][y]<0){mini=min(mini,v[x][y]);}
                    x++;y++;
                }
                // cout<<mini<<endl;
                if(mini<0){ans+=abs(mini);}
            }
        }
    }
    cout<<ans<<endl;
    
}

return 0;
}