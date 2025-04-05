#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<long long>> dp1(n + 1, vector<long long>(m + 1, 0));
    vector<vector<long long>> dp2(n + 1, vector<long long>(m + 1, 0));
    vector<vector<long long>> dp3(n + 1, vector<long long>(m + 1, 0));
    vector<vector<long long>> dp4(n + 1, vector<long long>(m + 1, 0));

    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp1[i][j] = a[i][j];
            if (i > 1) dp1[i][j] += dp1[i - 1][j];
            if (j > 1) dp1[i][j] = max(dp1[i][j], dp1[i][j - 1] + a[i][j]);
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            dp2[i][j] = a[i][j];
            if (i < n) dp2[i][j] += dp2[i + 1][j];
            if (j > 1) dp2[i][j] = max(dp2[i][j], dp2[i][j - 1] + a[i][j]);
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            dp3[i][j] = a[i][j];
            if (i < n) dp3[i][j] += dp3[i + 1][j];
            if (j < m) dp3[i][j] = max(dp3[i][j], dp3[i][j + 1] + a[i][j]);
        }
    }

  
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            dp4[i][j] = a[i][j];
            if (i > 1) dp4[i][j] += dp4[i - 1][j];
            if (j < m) dp4[i][j] = max(dp4[i][j], dp4[i][j + 1] + a[i][j]);
        }
    }

   
    long long max_gain = 0;
    for (int i = 2; i < n; i++) {
        for (int j = 2; j < m; j++) {
           
            long long gain=dp1[i][j]+dp2[i][j]+dp3[i][j]+dp4[i][j]-4*a[i][j];
            max_gain = max(max_gain, gain);
        }
    }

    cout << max_gain << endl;
    return 0;
}
