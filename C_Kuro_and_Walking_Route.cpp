#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x, y;
    cin >> n >> x >> y;

    map<ll,vector<ll>> adj;

    for (ll i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll sizeY = 0,sizeX = 0;

    function<ll(ll, ll)> dfs = [&](ll node, ll parent) {
        ll cnt = 1;
        for (auto child : adj[node]) {
            
            if (child != parent && child!=x) {
                cnt += dfs(child, node);
            }
        }
        if (node == y&&parent!=-1) sizeY = cnt;
        return cnt;
    };

    dfs(x, -1);
    sizeX = n-dfs(y, -1);

    ll invalidPairs = sizeX * sizeY,total=n*(n-1);

    cout << total-invalidPairs << endl;

    return 0;
}
