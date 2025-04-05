#include <iostream>
#include <vector>

using namespace std;

#define ll long long

ll n;
ll color[200005], sub_tree[200005], ans[200005];

// Fast input function using getchar()
inline ll fastInput() {
    ll num = 0, sign = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') sign = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
        c = getchar();
    }
    return num * sign;
}

// Fast output function using putchar()
inline void fastOutput(ll num) {
    if (num < 0) {
        putchar('-');
        num = -num;
    }
    char buffer[20];
    int i = 0;
    do {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    } while (num);
    while (i--) putchar(buffer[i]);
    putchar(' ');
}

ll dfs1(ll node, ll par, vector<ll> adj[]) {
    ll colr = color[node] ? 1LL : -1LL;
    sub_tree[node] = colr;
    for (ll child : adj[node]) {
        if (child != par) {
            ll diff = dfs1(child, node, adj);
            if (diff > 0) sub_tree[node] += diff;
        }
    }
    return sub_tree[node];
}

void dfs2(ll node, ll par, vector<ll> adj[]) {
    if (node != 1) {
        ans[node] = max(sub_tree[node], ans[par] + ((sub_tree[node] < 0) ? -1LL : 0));
    }
    for (ll child : adj[node]) {
        if (child != par) {
            dfs2(child, node, adj);
        }
    }
}

int main() {
    n = fastInput();
    for (ll i = 1; i <= n; i++) {
        color[i] = fastInput();
    }
    vector<ll> adj[n + 1];
    for (ll i = 0; i < n - 1; i++) {
        ll u = fastInput(), v = fastInput();
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1LL, 0LL, adj);
    ans[1] = sub_tree[1];
    dfs2(1LL, 0LL, adj);
    for (ll i = 1; i <= n; i++) {
        fastOutput(ans[i]);
    }
    putchar('\n');
    return 0;
}
