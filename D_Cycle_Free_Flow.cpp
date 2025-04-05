#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <climits>

using namespace std;

#define ll long long

// Depth-First Search to initialize depth and parent arrays
void dfs(ll node, ll par, ll dpth, vector<ll>& depth, vector<vector<pair<ll, ll>>>& parent, map<ll, ll> adj[]) {
    parent[node][0].first = par;
    depth[node] = dpth;
    for (auto it : adj[node]) {
        if (it.first != par) {
            parent[it.first][0].second = it.second;
            dfs(it.first, node, dpth + 1, depth, parent, adj);
        }
    }
}

// Function to "lift" a node up by a given distance
pair<ll, ll> lift(ll node, ll dist, ll k, vector<vector<pair<ll, ll>>>& parent) {
    ll min_edge = LLONG_MAX;
    for (ll i = k - 1; i >= 0; i--) {
        if (dist & (1 << i)) {
            min_edge = min(min_edge, parent[node][i].second);
            node = parent[node][i].first;
            if (node == 0) return {0LL, 0LL};
        }
    }
    return {node, min_edge};
}

// Function to find the Lowest Common Ancestor and minimum edge weight on the path
ll LCA(ll u, ll v, ll k, vector<ll>& depth, vector<vector<pair<ll, ll>>>& parent) {
    ll d1 = depth[u], d2 = depth[v];
    if (d1 < d2) {
        swap(u, v);
        swap(d1, d2);
    }

    auto pr = lift(u, d1 - d2, k, parent);
    u = pr.first;
    ll min_u = pr.second;
    ll min_v = LLONG_MAX;

    if (u == v) return min_u;

    for (ll i = k - 1; i >= 0; i--) {
        if (parent[u][i].first != parent[v][i].first) {
            min_u = min(min_u, parent[u][i].second);
            min_v = min(min_v, parent[v][i].second);
            u = parent[u][i].first;
            v = parent[v][i].first;
        }
    }

    min_u = min(min_u, parent[u][0].second);
    min_v = min(min_v, parent[v][0].second);

    return min(min_u, min_v);
}

int main() {
    ll n, e;
    cin >> n >> e;

    map<ll, ll> adj[n + 1];
    while (e--) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }

    ll m;
    cin >> m;

    ll k = ceil(log2(n)) + 1;
    vector<ll> depth(n + 1, 0);
    vector<vector<pair<ll, ll>>> parent(n + 1, vector<pair<ll, ll>>(k + 1, {0, LLONG_MAX}));

    // Initialize depth and parent arrays using DFS
    dfs(1, 0, 0, depth, parent, adj);

    // Precompute the sparse table for parent and minimum edge weights
    for (ll i = 1; i < k; i++) {
        for (ll j = 2; j <= n; j++) {
            parent[j][i].first = parent[parent[j][i - 1].first][i - 1].first;
            parent[j][i].second = min(parent[j][i - 1].second, parent[parent[j][i - 1].first][i - 1].second);
        }
    }

    // Process each query
    while (m--) {
        ll u, v;
        cin >> u >> v;
        ll ans = LCA(u, v, k, depth, parent);
        cout << ans << endl;
    }

    return 0;
}
