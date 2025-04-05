#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        vector<ll> process(n), cold(k), hot(k);
        
        for (ll i = 0; i < n; i++) cin >> process[i];
        for (ll i = 0; i < k; i++) cin >> cold[i];
        for (ll i = 0; i < k; i++) cin >> hot[i];

        vector<vector<ll>> dp(n+1,vector<ll>(k+1,-1));
        function<ll(ll,ll)>recur=[&](ll i,ll prev){
            if(i==n)return 0LL;
            if(dp[i][prev]!=-1)return dp[i][prev];
            if(i==0)return recur(i+1,prev)+cold[process[i]-1];
            else if(process[i]==process[i-1])return dp[i][prev]=hot[process[i]-1]+recur(i+1,prev);
            else if(process[i]==prev)return dp[i][prev]=hot[process[i]-1]+recur(i+1,process[i-1]);
            // else if(prev==0)return dp[i][prev]=cold[process[i]-1]+recur(i+1,process[i-1]);
            return dp[i][prev]=min(recur(i+1,prev),recur(i+1,process[i-1]))+cold[process[i]-1];
        };

        cout<<recur(0,0)<<endl;
    
    }

    return 0;
}
