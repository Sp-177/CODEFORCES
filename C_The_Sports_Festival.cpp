#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);                      

    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));

    function<ll(ll, ll)> recur = [&](ll i, ll j) {
        if (i > j) return 0LL;
        if (dp[i][j] != -1LL) return dp[i][j];
        ll take_mini = recur(i + 1, j) + arr[j] - arr[i];
        ll take_maxi = recur(i, j - 1) + arr[j] - arr[i];
        return dp[i][j] = min(take_maxi, take_mini);
    };

    cout << recur(0, n - 1) << endl;
    return 0;
}
