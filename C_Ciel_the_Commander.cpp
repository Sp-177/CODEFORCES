#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int N = 1e5 + 5;  // Adjust N as per problem constraints
vector<int> adj[N];
int size_sub[N];
int visited[N];
char ans[N];

// DFS to compute subtree sizes
void dfs(int node, int parent) {
    size_sub[node] = 1;
    for (int child : adj[node]) {
        if (child != parent && !visited[child]) {
            dfs(child, node);
            size_sub[node] += size_sub[child];
        }
    }
}

// Find centroid of current component
int find_centroid(int node, int parent, int total_size) {
    for (int child : adj[node]) {
        if (child != parent && !visited[child] && size_sub[child] > total_size / 2) {
            return find_centroid(child, node, total_size);
        }
    }
    return node;
}

// Divide & Conquer (Centroid Decomposition)
void decompose(int node, int parent, int depth_char) {
    dfs(node, parent);
    int centroid = find_centroid(node, parent, size_sub[node]);

    ans[centroid] = 'A' + depth_char;
    visited[centroid] = 1;

    for (int child : adj[centroid]) {
        if (!visited[child]) {
            decompose(child, centroid, depth_char + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    decompose(1, -1, 0);

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}
