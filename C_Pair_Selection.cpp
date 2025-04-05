#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

bool predicate_funt(const vector<long double> &a, const vector<long double> &b, int n, int k, long double mid) {
    vector<long double> adjusted(n);
    for (int i = 0; i < n; i++) {
        adjusted[i] = a[i] - b[i] * mid;
    }

    sort(adjusted.rbegin(), adjusted.rend()); 

    long double sum = 0;
    for (int i = 0; i < k; i++) {
        sum += adjusted[i];
    }

    return sum >= 0;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<long double> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    long double low = 0.0, high = 100000.0;
    

    for(int i=0;i<60;i++) { 
        long double mid = (low + high) / 2.0;
        if (predicate_funt(a, b, n, k, mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << fixed << setprecision(10) << low << endl;

    return 0;
}
