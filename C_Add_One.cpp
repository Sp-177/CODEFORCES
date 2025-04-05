#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
long long t,mod=1e9+7;
cin>>t;
int move=2*1e5;
vector<vector<long long>>dp(10,vector<long long>(move+1,0LL));
 for(int i=0;i<=9;i++)dp[i][0]=1;
    for(int moves=1;moves<=move;moves++){
        for(int i=0;i<=9;i++){
            if(i==9){
                dp[i][moves]=(dp[1][moves-1]+dp[0][moves-1])%mod;
            }
            else{
                dp[i][moves]=dp[i+1][moves-1]%mod;
            }
        }
    }
while(t--){
    long long n,m;cin>>n>>m;
    long long ans=0;
    

    while(n>0){
        long long digit=n%10;
        ans+=dp[digit][m]%mod;
        ans%=mod;
        n/=10;
    }
    cout<<ans<<endl;
}

return 0;
}