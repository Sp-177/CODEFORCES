#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, d;
    cin >> n >> m >> d;

    map<int, map<int, int>> adj;
    vector<pair<int, int>> can_reachable(n + 1, {static_cast<int>(-1), 0}); // Memoization

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
    }

    map<int, int> path;
    function<pair<int, int>(int, int)> traversal = [&](int node, int steps) {
        if (steps > d) return make_pair(INT_MAX, 0); // Exceeded allowed steps
        if (node == n) return make_pair(1, n); // Reached destination

        // if (can_reachable[node].first != -1) return can_reachable[node]; // Memoized result

        int ans = INT_MAX, next_node = 0;
        for (auto i : adj[node]) {
            auto p = traversal(i.first, steps + 1);

            if (p.first != INT_MAX) {
                if (ans > max(p.first, i.second)) {
                    ans = max(p.first, i.second);
                    next_node = i.first;
                }
            }
        }
        if (ans != INT_MAX) path[node] = next_node;

        return can_reachable[node] = {ans, node};
    };

    auto ans_p = traversal(1, 0);

    if (can_reachable[1].first == INT_MAX) {
        cout << -1 << endl;
    } else {
        vector<int> out;
        int node = 1;
        while (node != n && path.count(node)) {
            out.push_back(node);
            node = path[node];
        }
        out.push_back(n);
        cout << out.size() - 1 << endl;
        for (int i : out) cout << i << " ";
        cout << endl;
    }

    return 0;
}