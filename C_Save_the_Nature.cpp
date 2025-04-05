#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        long long arr[n];
        for (long long i = 0; i < n; i++) cin >> arr[i];

        long long x, a, y, b, k;
        cin >> x >> a >> y >> b >> k;

        sort(arr, arr + n, greater<long long>());

        if (x < y) {
            swap(x, y);
            swap(a, b);
        }

        auto predicate_functions = [&](long long mid) -> bool {
            long long sum = 0;
            long long mul = (a * b) / (__gcd(a, b));
            long long mul_per = x + y;

            vector<long long> contrib;

            for (long long i = 1; i <= mid; i++) {
                if (i % mul == 0)
                    contrib.push_back(mul_per);
                else if (i % a == 0)
                    contrib.push_back(x);
                else if (i % b == 0)
                    contrib.push_back(y);
            }

            sort(contrib.rbegin(), contrib.rend());

            for (long long i = 0; i < contrib.size(); i++) {
                sum += (arr[i] * contrib[i]) / 100;
                if (sum >= k) return true;
            }

            return false;
        };

        long long low = 1, high = n, answer = -1;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (predicate_functions(mid)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
