#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 7;
class Query {
public:
    int l, r, block, index;
};
Query q[MAXN];

vector<int> solve(int n, int m, vector<int> a, vector<vector<int>> query) {
    auto cmp = [&](Query &a, Query &b) -> bool {
        if (a.block != b.block) return a.block < b.block;
        return a.r < b.r;
    };
    int root_n = sqrt(n);
    for (int i = 0; i < m; i++) {
        q[i].index = i;
        q[i].l = --query[i][0];
        q[i].r = --query[i][1];
        q[i].block = q[i].l / root_n;
    }
    sort(q, q + m, cmp);

    unordered_map<int, int> fq;
    int start = 0, end = 0, cnt = 0;
    vector<int> ans(m);

    auto check = [&](int num, int val) -> void {
        if (fq[num] == num) cnt--;
        fq[num] += val;
        if (fq[num] == num) cnt++;
    };

    for (int i = 0; i < m; i++) {
        int l = q[i].l, r = q[i].r;
        while (end <= r) {
            check(a[end], 1);
            end++;
        }
        while (end > r + 1) {
            end--;
            check(a[end], -1);
        }
        while (start < l) {
            check(a[start], -1);
            start++;
        }
        while (start > l) {
            start--;
            check(a[start], 1);
        }
        ans[q[i].index] = cnt;
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> query(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> query[i][0] >> query[i][1];
    }

    vector<int> result = solve(n, m, a, query);

    for (int res : result) {
        cout << res << "\n";
    }

    return 0;
}
