#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define ll long long
const int MAXN = 200001;

ll arr[MAXN];
map<ll, vector<ll>> adj;
ll sub_tree[MAXN] = {0};
ll ans[MAXN] = {0};
ll n;

void dfs(ll u, ll parent) {
    sub_tree[u] = 1; // Start with the current node
    ans[u] = 0;

    for (ll v : adj[u]) {
        if (v != parent) {
            dfs(v, u); // Recursive DFS for children
            sub_tree[u] += sub_tree[v]; // Accumulate subtree size
            ans[u] += ans[v] + sub_tree[v] * (arr[u] ^ arr[v]);
        }
    }
}

void dfs2(ll u, ll parent, ll val) {
    ans[u] = val;

    for (ll v : adj[u]) {
        if (v != parent) {
            // Propagate the answer to the child
            ll new_val = val + (n - sub_tree[v]) * (arr[v] ^ arr[u]) - sub_tree[v] * (arr[v] ^ arr[u]);
            dfs2(v, u, new_val);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--) {
        cin >> n;

        // Reset structures
        adj.clear();
        fill(sub_tree, sub_tree + n + 1, 0);
        fill(ans, ans + n + 1, 0);

        for (ll i = 1; i <= n; i++) cin >> arr[i];

        for (ll i = 0; i < n - 1; i++) {
            ll u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, 0);
        dfs2(1, 0, ans[1]);

        for (ll i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
    