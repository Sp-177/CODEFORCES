#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 200007

// Custom GCD function
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

inline ll fastRead() {
    ll x = 0, c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x;
}

inline void fastWrite(ll x) {
    if (x == 0) {
        putchar('0');
        putchar('\n');
        return;
    }
    char buf[20];
    int i = 0;
    while (x > 0) {
        buf[i++] = (x % 10) + '0';
        x /= 10;
    }
    while (i--) putchar(buf[i]);
    putchar('\n');
}

ll spf[MAXN];
vector<ll>semi_prime;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = fastRead();

    iota(spf, spf + MAXN, 0);
    for (ll i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (ll j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
    
    for (ll i = 2; i < MAXN; i++) {
        if (spf[i]!= i && spf[spf[i]] == spf[spf[i]]) semi_prime.push_back(i);
    }

    while (t--) {
        ll n = fastRead();
        map<ll, ll> frq;

        for (ll i = 0; i < n; i++) {
            ll x = fastRead();
            frq[x]++;
        }

        ll ans = 0;
        for(ll  i:semi_prime) {
            if (spf[i] != i) {
                ll f1 = spf[i], f2 = i / spf[i];
                if (spf[f2] == f2) {
                    if (frq.count(f1) && frq.count(f2) && f1 != f2) {
                        ans += frq[f1] * frq[f2];
                    }
                    if (frq.count(f1) && frq.count(i)) {
                        ans += frq[f1] * frq[i];
                    }
                    if (frq.count(f2) && f1 != f2 && frq.count(i)) {
                        ans += frq[f2] * frq[i];
                    }
                    if (frq.count(i)) {
                        ans += frq[i] * (frq[i] + 1) / 2;
                    }
                }
            }
        }
        

        fastWrite(ans);
    }

    return 0;
}
