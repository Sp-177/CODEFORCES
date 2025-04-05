#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>  // Include this for iota

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int total_test_cases;
    cin >> total_test_cases;

    while (total_test_cases--) {
        int n;
        cin >> n;
        vector<string> adj;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            adj.push_back(s);
        }

        vector<int> ans(n);  // Initialize the vector with the size of n
        iota(ans.begin(), ans.end(), 0);  // iota will now work correctly

        sort(ans.begin(), ans.end(), [&adj](int i, int j) {
            if (i < j) {
                return adj[i][j] == '1';
            } else {
                return !(adj[i][j] == '1');
            }
            return false;
        });

        for (int i : ans) cout << i + 1 << ' ';
        cout << "\n";
    }

    return 0;
}
