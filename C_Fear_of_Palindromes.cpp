#include <iostream>
#include <cstring>
using namespace std;

int dp[2001][2001][2];

int sol(string& str, int limit, int i, int j, int state) {
    if (i > j) return 0;  // Base case: invalid indices
    if (state == 0 && (i >= limit || j < limit)) return 0;  // Must cross boundary
    if (i == j) return 1;  // Single character is a palindrome

    if (dp[i][j][state] != -1) return dp[i][j][state];  // Use memoized result

    if (str[i] == str[j]) {
        return dp[i][j][state] = sol(str, limit, i + 1, j - 1, 1) + 2;
    }

    int num1 = sol(str, limit, i, j - 1, state);
    int num2 = sol(str, limit, i + 1, j, state);

    return dp[i][j][state] = max(num1, num2);  // Take the max of both cases
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;

        memset(dp, -1, sizeof(dp));  // Initialize memoization table
        
        string str = str1 + str2;
        int len = str.size(), lim = str1.size();

        int ans = sol(str, lim, 0, len - 1, 0);  // Start with initial state

        cout << ans << endl;
    }
    return 0;
}
