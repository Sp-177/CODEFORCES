#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>

using namespace std;

#define ll long long

unordered_map<ll, unordered_map<ll, ll>> adj;
unordered_set<ll> candidates;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll dfs(ll node, ll par) {
    ll sum = 0;
    for (auto& child : adj[node]) {
        if (child.first != par) {
            sum += dfs(child.first, node);
        }
    }
    if (sum == 0 && adj[node][par] == 2) {
        candidates.insert(node);
        return 1;
    }
    if (sum > 0) return 1;
    return 0;
}

int main() {
    fastIO();
    
    ll t = 1;
    while (t--) {
        ll n;
        scanf("%lld", &n);

        adj.clear();
        candidates.clear();

        for (ll i = 0; i < n - 1; i++) {
            ll u, v, w;
            scanf("%lld %lld %lld", &u, &v, &w);
            adj[u][v] = w;
            adj[v][u] = w;
        }

        dfs(1, 0);

        printf("%lld\n", candidates.size());
        for (auto it : candidates) {
            printf("%lld ", it);
        }
        printf("\n");
    }

    return 0;
}
