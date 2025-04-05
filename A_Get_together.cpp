#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

bool predicate_funct(const vector<pair<double, double>>& v, long long n, double mid) {
    double l = -1e18, r = 1e18; // Initial bounds
    for (int i = 0; i < n; i++) {
        double dist = v[i].second * mid;
        double l_dist = v[i].first - dist;
        double r_dist = v[i].first + dist;
        l = max(l, l_dist); // Update global left boundary
        r = min(r, r_dist); // Update global right boundary
        if (r < l) return false; // If no overlap, gathering is impossible
    }
    return true;
}

int main() {
    long long n;
    cin >> n;
    vector<pair<double, double>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    double low = 0.0, high = 1e9, error = 1e-7;
    for(int i=0;i<=60;i++){
        double mid = (low + high) / 2.0;
        if (predicate_funct(v, n, mid)) {
            high = mid; // Feasible time, try smaller
        } else {
            low = mid; // Infeasible, try larger
        }
    }

    cout << fixed << setprecision(7) << high << endl;
    return 0;
}
