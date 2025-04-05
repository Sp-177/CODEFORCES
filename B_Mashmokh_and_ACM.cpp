#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long mod=1e9+7, n, k; 
    cin >> n >> k;
    
  
    vector<vector<long long>> dp(n+1, vector<long long>(k+1, -1LL));
    
    function<long long(long long, long long)> sol = [&](long long i, long long j) {
        if (j == k) return 1LL;
        if (dp[i][j] != -1) return dp[i][j];
        
        long long t = 0;
        for (int l = (i==0?1:i); l <= n; l+=(i==0?1:i)) {
            if (i == 0 || l % i == 0) {
                t += sol(l, j + 1);
                t %= mod;
            }
        }
        return dp[i][j] = t;
    };
    
    cout << sol(0, 0) << endl;
    
    return 0;
}
