#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = 1e6 + 1;
ll spf[MAXN];  // move to global to avoid reallocation and stack issues

void computeSPF() {
    for(ll i = 0; i < MAXN; i++) spf[i] = i;
    for(ll i = 2; i * i < MAXN; i++) {
        if(spf[i] == i) {
            for(ll j = i * i; j < MAXN; j += i) {
                spf[j] = min(i, spf[j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // computeSPF();  // call SPF once

    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());
        ll Number = a[0] * a.back();
        
    }

    return 0;
}