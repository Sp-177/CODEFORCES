#include <iostream>
#include <vector>

using namespace std;

#define ll long long
const int MAX_N = 200001;
const ll mod = 998244353;

ll fac[MAX_N], inv_fac[MAX_N];

ll binary_expo(ll base, ll pow) {
    ll res = 1;
    while (pow > 0) {
        if (pow & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        pow >>= 1;
    }
    return res;
}

void precompute_factorials() {
    fac[0] = 1;
    for (ll i = 1; i < MAX_N; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
    }
    inv_fac[MAX_N - 1] = binary_expo(fac[MAX_N - 1], mod - 2);
    for (ll i = MAX_N - 2; i >= 0; i--) {
        inv_fac[i] = (inv_fac[i + 1] * (i + 1)) % mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute_factorials();

    ll t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;
        ll n = str.length();

        ll ans = 0, total = 1, cnt = 1;
        bool toggle = false;
        for (int i = 1; i < n; i++) {
            if (str[i] == str[i - 1]) {
                cnt++;
                ans++;
            } else {
                total = (total *fac[cnt]) % mod;
                
                cnt = 1;
            }
        }
        
        total = (total * fac[cnt]) % mod;
        
        
        cout << ans << " " << total << endl;
    }

    return 0;
}
