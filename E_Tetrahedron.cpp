#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long mod = 1e9 + 7;
    long long dp[4];
    memset(dp, 0, sizeof(dp));
    dp[3] = 1LL;

    for (int i = 1; i <= n; i++) {
        long long curr_arr[4];
        memset(curr_arr, 0, sizeof(curr_arr));

        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (j != k) {
                    curr_arr[j] += dp[k] % mod;
                }
            }
            curr_arr[j] %= mod;
        }

        // Copy curr_arr to dp
        for (int j = 0; j < 4; j++) {
            dp[j] = curr_arr[j];
        }
    }

    long long ans = dp[3];
    cout << ans << endl;

    return 0;
}
