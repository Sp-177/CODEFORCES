#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long m, n;
    cin >> m >> n;

    auto query = [&](long long mid) -> int {
        cout << mid << endl;
        int x;
        cin >> x;
        return x;
    };

    auto answer = [&](long long ind) -> void {
        cout << ind << endl;
    };

    // Initialize the sequence to store the first `n` responses
    vector<int> seq(n + 1, -1);

    // Handle the first `n` queries to populate the `seq` array
    for (int i = 1; i <= n; i++) {
        int pos = query(i);
        seq[i] = pos;  // Store the result in the sequence
        if (pos == 0) {  // If answer is found, terminate
            answer(i);
            return 0;
        }
    }

    // Replace remaining `-1` in `seq` with a default value of `0`
    for (int i = 1; i <= n; i++) {
        if (seq[i] == -1) seq[i] = 0;
    }

    // Binary search over the range [n+1, m]
    long long low = n + 1, high = m;
    int cnt = 0;  // Counter to iterate through `seq`

    while (low <= high) {
        if (cnt >= n) cnt %= n;  // Wrap `cnt` to loop through `seq`
        long long mid = (low + high) / 2;
        cnt++;

        int pos = query(mid);  // Query the midpoint
        if (pos == 0) {  // If the correct number is found
            answer(mid);
            return 0;
        }

        // Adjust search range based on the value of `seq[cnt]`
        if (seq[cnt] == 0) {  // The `cnt`-th response indicated "lie"
            if (pos == 1) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {  // The `cnt`-th response indicated "truth"
            if (pos == 1) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    // If no valid number is found
    cout << "-1" << endl;
    return 0;
}
