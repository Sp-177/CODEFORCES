#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 200007
#define MAX_VAL 1000007  // The range of ai is 1 to 10^6

// Query class to store the queries
class Query {
public:
    int l, r, block, index;
};

// Global variables
int n, m;
vector<int> a;
vector<Query> q;
vector<ll> ans;
ll sum = 0;
int s = 0, e = 0;  // Changed from start and end to s and e
ll freq[MAX_VAL] = {0};  // Frequency array to store frequency of each element

// Function to process frequency updates
void check(ll num, ll val) {
    ll last_fq = freq[num];
    ll old_calc = last_fq * last_fq * num;
    sum -= old_calc;
    freq[num] += val;
    ll new_fq = freq[num];
    ll new_calc = new_fq * new_fq * num;
    sum += new_calc;
}

// Fast I/O - Reading input
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

// Function to solve the problem
vector<ll> solve() {
    int root = sqrt(n);
    
    // Process queries and prepare them
    for (int i = 0; i < m; i++) {
        int x = q[i].l, y = q[i].r;
        x--; y--;  // 0-based index
        q[i].index = i;
        q[i].l = x;
        q[i].r = y;
        q[i].block = x / root;
    }

    // Sort queries: By block number and then by right endpoint (r)
    sort(q.begin(), q.end(), [](const Query &a, const Query &b) {
        if (a.block != b.block) return a.block < b.block;
        return a.r < b.r;
    });

    // Process each query
    for (const auto &query : q) {
        int l = query.l, r = query.r, index = query.index;

        // Move the `e` pointer to the right position
        while (e <= r) {
            check(a[e], 1);
            e++;
        }
        while (e > r + 1) {
            e--;
            check(a[e], -1);
        }

        // Move the `s` pointer to the right position
        while (s < l) {
            check(a[s], -1);  // Fixed this line (was a[e] by mistake)
            s++;
        }
        while (s > l) {
            s--;
            check(a[s], 1);
        }

        // Store the result of the current query
        ans[query.index] = sum;
    }

    return ans;
}

// Main function
int main() {
    fast_io();  // Fast I/O initialization

    // Read inputs using scanf for fast I/O
    scanf("%d %d", &n, &m);
    a.resize(n);
    q.resize(m);
    ans.resize(m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &q[i].l, &q[i].r);
    }

    // Solve the queries
    vector<ll> result = solve();

    // Output the result using printf for fast I/O
    for (ll res : result) {
        printf("%lld\n", res);
    }

    return 0;
}
