#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool canCut(const vector<int>& ropes, int k, double length) {
    int count = 0;
    for (int rope : ropes) {
        count += static_cast<int>(rope / length);
        if (count >= k) return true; // Early exit if already feasible
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> ropes(n);
    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
    }

    double low = 0, high = *max_element(ropes.begin(), ropes.end()), error = 1e-7;
    while (high - low > error) {
        double mid = (low + high) / 2.0;
        if (canCut(ropes, k, mid)) {
            low = mid; // Try larger length
        } else {
            high = mid; // Try smaller length
        }
    }

    cout << fixed << setprecision(7) << low << endl; // Maximum feasible length
    return 0;
}
