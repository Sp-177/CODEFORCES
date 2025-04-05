#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string start, end;
    cin >> start >> end;
    long long k;
    cin >> k;

    if (k == 0) {
        if (start == end) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }

    long long n = end.length();
    long long mod = 1e9 + 7;

    // Generate all cyclic shifts of the target string 'end'
    string list_cyclic_string[n];
    for (int i = 0; i < n - 1; i++) {
        string front = end.substr(0, i + 1);
        string back = end.substr(i + 1);
        list_cyclic_string[i] = back + front;
    }
    list_cyclic_string[n - 1] = end;

    // Initialize dp array
    long long dp[n];
    memset(dp, 0, n * sizeof(long long));

    dp[n - 1] = 1LL;

    for (int i = 1; i <= k; i++) {
        long long sum = 0;

        // Compute the sum of all dp values
        for (int j = 0; j < n; j++) {
            sum += dp[j] % mod;
            sum %= mod;
        }

        // Update dp array using the sum and handle negative modulo
        for (int j = 0; j < n; j++) {
            dp[j] = (sum - dp[j] + mod) % mod; // Ensure non-negative values
        }
    }

    long long ans = 0;

    // Check if 'start' matches any of the cyclic shifts and add corresponding dp values
    for (int i = 0; i < n; i++) {
        if (start == list_cyclic_string[i]) {
            ans += dp[i] % mod;
            ans %= mod;
        }
    }

    cout << ans << endl;

    return 0;
}
