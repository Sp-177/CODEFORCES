#include <iostream>
#include <cstring>
#include <array>
#include <sstream>

using namespace std;

#define ll long long
const ll MOD = 998244353;
const int MAX_N = 200005;

std::array<std::array<std::array<ll, 3>, MAX_N>, 2> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    stringstream output;  // Use stringstream for faster appending of results

    while (t--) {
        ll n;
        cin >> n;

        array<ll, MAX_N> arr;
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }

        for (ll num_truth = 0; num_truth <= n; num_truth++) {
            dp[n % 2][num_truth][0] = 1;
            dp[n % 2][num_truth][1] = 1;
            dp[n % 2][num_truth][2] = 1;
        }

        for (ll i = n - 1; i >= 0; i--) {
            for (ll num_truth = 0; num_truth <= i; num_truth++) {
                for (ll last = 0; last < 3; last++) {
                    ll t = 0, l = 0;

                    if (i == num_truth + arr[i]) {
                        t = dp[(i + 1) % 2][num_truth + 1][1];
                    }
                    if (last != 2) {
                        l = dp[(i + 1) % 2][num_truth][2];
                    }

                    dp[i % 2][num_truth][last] = (t + l) % MOD;
                }
            }
        }

        output << dp[0][0][0] << '\n';  // Add result directly to the output buffer
    }

    cout << output.str();  // Output all results at once

    return 0;
}
