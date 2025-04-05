#include <iostream>
#include <vector>

using namespace std;

#define ll long long

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<vector<ll>> a;
vector<ll> edges;
ll root;

bool dfs(ll node, ll par) {
    if (node != root) {
        if (a[node].size() > 2) return false; 
        if (a[node].size() == 1) {
            edges.push_back(node);
            return true;
        }
    }
    for (auto child : a[node]) {
        if (child != par) {
            if (!dfs(child, node)) return false;
        }
    }
    return true;
}

int main() {
    fastIO();

    ll t = 1;
    // cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        
        if (n == 1) {  // Handling single node tree
            cout << "Yes\n0\n";
            continue;
        }

        a.assign(n + 1, vector<ll>());
        edges.clear();

        for (ll i = 1; i < n; i++) {
            ll u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }

        root = 1;
        ll edge_size = a[1].size();
        for (ll i = 2; i <= n; i++) {
            if ((long(a[i].size())) > edge_size) {
                root = i;
                edge_size = a[i].size();
            }
        }

        if (dfs(root, -1)) {  // Fix: Use -1 as parent
            cout << "Yes\n" << edges.size() << "\n";
            for (auto e : edges) {
                cout << root << " " << e << "\n";
            }
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
