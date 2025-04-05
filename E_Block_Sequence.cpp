#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long dp[2*100000 +1]; // Maximum size (adjust if necessary)

int main(){
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        
        long long arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Ensure dp array is initialized to zero
        memset(dp, 0, sizeof(dp));
        
        // Start DP from the end of the array
        for (int i = n - 1; i >= 0; i--) {
            // r is the case where you don't jump, just move forward 1 step
            long long r = dp[i + 1] + 1;
            // nr is the case where you can jump to i + arr[i] + 1
            long long nr = LLONG_MAX;
            if (i + arr[i] < n) {
                nr = dp[i + arr[i] + 1];
            }
            // Store the minimum value of the two
            dp[i] = min(r, nr);
        }

        // Output the result
        cout << dp[0] << endl;
    }

    return 0;
}
