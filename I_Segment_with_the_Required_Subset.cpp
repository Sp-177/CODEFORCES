#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, s;
    cin >> n >> s;
    long long arr[n];
    for (long long i = 0; i < n; i++) cin >> arr[i];

    vector<vector<int>>dp(n+1,vector<int>(s+1,INT_MAX));
    for(long long i = 0; i <= n; i++)dp[i][0]=i;

    for (long long i = n - 1; i >= 0; i--) {
        for (long long j = 1; j <= s; j++) {
            // cout<<dp[i][j]<<" -> "<<dp[i+1][j]<<" : ";
            if ((j - arr[i]) >= 0) {
                // cout<<dp[i+1][j-arr[i]]<<" ";
                dp[i][j] = dp[i+1][j-arr[i]];
            }
            // cout<<"XXX";
            dp[i][j] = min(dp[i][j], dp[i+1][j]);
        }
        // cout<<endl;
    }

    long long ans=INT_MAX;
    for(long long i=0;i<=n;i++){
        if(dp[i][s]!=(INT_MAX))ans=min(ans,dp[i][s]-i);
    }
    if(ans!=(INT_MAX)&&ans!=0)cout << ans << endl;
    else cout<<-1<<endl;
    return 0;
}
