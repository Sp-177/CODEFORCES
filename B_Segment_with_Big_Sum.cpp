#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);

    long long n, s;
    cin >> n >> s;

    long long arr[n];
    for (long long i = 0; i < n; i++) cin >> arr[i];

    // Predicate function to check if a subarray of length 'mid' has a sum >= s
    auto predicate_num = [&](long long mid) -> bool {
        if (mid == 1) return (*max_element(arr, arr + n)) >= s;

        long long sum = 0;
        for (long long i = 0; i < mid; i++) sum += arr[i]; // First subarray sum
        if (sum >= s) return true;

        // Sliding window to calculate sum for subsequent subarrays
        for (long long i = mid; i < n; i++) {
            sum -= arr[i - mid];
            sum += arr[i];
            if (sum >= s) return true;
        }
        return false;
    };

    long long low = 1, high = n, ans = 0; // low starts at 1, not 0
    while (low <= high) {
        long long mid = (low + high) / 2; // Corrected division
        if (predicate_num(mid)) {
            high = mid - 1;
            ans = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << ((ans == 0) ? -1 : ans) << endl;

    return 0;
}
