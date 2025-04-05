#include <iostream>
#include <vector>
#include <cmath>
#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")

using namespace std;

#define ll long long

const int MAX_N = 200005; // Constraint upper bound
const int MAX_LVL = 20;   // Log base 2 of MAX_N (~log2(2*10^5))

vector<vector<ll>> adj[MAX_N];
ll a_sum[MAX_N], b_sum[MAX_N], depth[MAX_N];
ll parent[MAX_N][MAX_LVL]; // Binary Lifting Table

void dfs(ll node, ll par, ll sum, ll mode, ll dpth) {
    depth[node] = dpth;
    parent[node][0] = par;
    if (mode) a_sum[node] = sum;
    else b_sum[node] = sum;

    for (auto child : adj[node]) {
        if (child[0] != par) {
            dfs(child[0], node, sum + (mode == 1 ? child[1] : child[2]), mode, dpth + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        // Reset adjacency list and data arrays
        for (ll i = 1; i <= n; i++) {
            adj[i].clear();
            a_sum[i] = 0;
            b_sum[i] = 0;
            depth[i] = 0;
        }

        // Reset parent array manually (Avoid memset)
        for (ll i = 1; i <= n; i++) {
            for (ll j = 0; j < MAX_LVL; j++) {
                parent[i][j] = 0;
            }
        }

        for (ll i = 2; i <= n; i++) {
            ll u, a, b;
            cin >> u >> a >> b;
            adj[u].push_back({i, a, b});
            adj[i].push_back({u, a, b});
        }

        ll max_lvl = ceil(log2(n)) + 1;

        dfs(1, 0, 0, 0, 0);
        dfs(1, 0, 0, 1, 0);

        for (ll i = 1; i < max_lvl; i++) {
            for (ll j = 2; j <= n; j++) {
                if (parent[j][i - 1] != 0) {
                    parent[j][i] = parent[parent[j][i - 1]][i - 1];
                }
            }
        }

        string result; // Using string buffer for faster output

        for (ll i = 2; i <= n; i++) {
            if (a_sum[i] >= b_sum[i]) {
                result += to_string(depth[i]) + " ";
            } else {
                ll node = i;
                for (ll j = max_lvl - 1; j >= 0; j--) {
                    ll par = parent[node][j];
                    if (a_sum[i] < b_sum[par]) {
                        node = par;
                    }
                }
                result += to_string(depth[parent[node][0]]) + " ";
            }
        }
        cout << result << '\n'; // Print all output in one go
    }

    return 0;
}
