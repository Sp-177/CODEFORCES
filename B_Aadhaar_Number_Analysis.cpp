#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
const int SQRT_MAX_N = 31622;

vector<int> spf(SQRT_MAX_N + 1);

void sieve() {
    for (int i = 2; i <= SQRT_MAX_N; i++) spf[i] = i;
    for (int i = 2; i * i <= SQRT_MAX_N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= SQRT_MAX_N; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        ll grt = 1;
        vector<pair<ll, ll>> v;

        // Prime factorization
        for (ll fac = 2; fac * fac <= n; fac++) {
            if (n % fac == 0) {
                ll cnt = 0;
                while (n % fac == 0) {
                    cnt++;
                    n /= fac;
                }
                v.push_back({fac, cnt});
            }
        }
        if (n > 1) v.push_back({n, 1});  // If any prime factor > sqrt(n)

        for (auto i : v) grt *= i.first;

        sort(v.begin(), v.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
            return a.second < b.second;
        });

        ll ans = 0, minus = 0;
        for (auto i : v) {
            if (i.second - minus < 0) break;
            ans += grt * (i.second - minus);
            grt /= i.first;
            minus += (i.second - minus);
        }
        cout << ans << endl;
    }

    return 0;
}
