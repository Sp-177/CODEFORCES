#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n1, n2, n3, n4;

    // Input for caps
    cin >> n1;
    vector<long long> cap(n1);
    for (long long i = 0; i < n1; i++) cin >> cap[i];

    // Input for shirts
    cin >> n2;
    vector<long long> shirt(n2);
    for (long long i = 0; i < n2; i++) cin >> shirt[i];

    // Input for pants
    cin >> n3;
    vector<long long> pants(n3);
    for (long long i = 0; i < n3; i++) cin >> pants[i];

    // Input for shoes
    cin >> n4;
    vector<long long> shoes(n4);
    for (long long i = 0; i < n4; i++) cin >> shoes[i];

    // Sort all arrays
    sort(cap.begin(), cap.end());
    sort(shirt.begin(), shirt.end());
    sort(pants.begin(), pants.end());
    sort(shoes.begin(), shoes.end());

    auto predicate_func = [&](long long x) -> pair<bool, vector<long long>> {
        // Check with caps as the primary array
        for (long long i = 0; i < n1; i++) {
            long long upper_limit = cap[i] + x;

            auto shirt_it = lower_bound(shirt.begin(), shirt.end(), cap[i]);
            if (shirt_it == shirt.end() || *shirt_it > upper_limit) continue;

            auto pants_it = lower_bound(pants.begin(), pants.end(), cap[i]);
            if (pants_it == pants.end() || *pants_it > upper_limit) continue;

            auto shoes_it = lower_bound(shoes.begin(), shoes.end(), cap[i]);
            if (shoes_it == shoes.end() || *shoes_it > upper_limit) continue;

            return {true, {cap[i], *shirt_it, *pants_it, *shoes_it}};
        }

        // Check with shirts as the primary array
        for (long long i = 0; i < n2; i++) {
            long long upper_limit = shirt[i] + x;

            auto cap_it = lower_bound(cap.begin(), cap.end(), shirt[i]);
            if (cap_it == cap.end() || *cap_it > upper_limit) continue;

            auto pants_it = lower_bound(pants.begin(), pants.end(), shirt[i]);
            if (pants_it == pants.end() || *pants_it > upper_limit) continue;

            auto shoes_it = lower_bound(shoes.begin(), shoes.end(), shirt[i]);
            if (shoes_it == shoes.end() || *shoes_it > upper_limit) continue;

            return {true, {*cap_it, shirt[i], *pants_it, *shoes_it}};
        }

        // Check with pants as the primary array
        for (long long i = 0; i < n3; i++) {
            long long upper_limit = pants[i] + x;

            auto shirt_it = lower_bound(shirt.begin(), shirt.end(), pants[i]);
            if (shirt_it == shirt.end() || *shirt_it > upper_limit) continue;

            auto cap_it = lower_bound(cap.begin(), cap.end(), pants[i]);
            if (cap_it == cap.end() || *cap_it > upper_limit) continue;

            auto shoes_it = lower_bound(shoes.begin(), shoes.end(), pants[i]);
            if (shoes_it == shoes.end() || *shoes_it > upper_limit) continue;

            return {true, {*cap_it, *shirt_it, pants[i], *shoes_it}};
        }

        // Check with shoes as the primary array
        for (long long i = 0; i < n4; i++) {
            long long upper_limit = shoes[i] + x;

            auto shirt_it = lower_bound(shirt.begin(), shirt.end(), shoes[i]);
            if (shirt_it == shirt.end() || *shirt_it > upper_limit) continue;

            auto pants_it = lower_bound(pants.begin(), pants.end(), shoes[i]);
            if (pants_it == pants.end() || *pants_it > upper_limit) continue;

            auto cap_it = lower_bound(cap.begin(), cap.end(), shoes[i]);
            if (cap_it == cap.end() || *cap_it > upper_limit) continue;

            return {true, {*cap_it, *shirt_it, *pants_it, shoes[i]}};
        }

        return {false, {}};
    };

    long long low = 0, high = 1e5; // Adjust high as per constraints
    vector<long long> ans;

    // Binary search for the minimum x
    while (low <= high) {
        long long mid = (low + high) / 2;
        auto result = predicate_func(mid);
        if (result.first) {
            high = mid - 1;
            ans = result.second;
        } else {
            low = mid + 1;
        }
    }

    // Output the result
    if (!ans.empty()) {
        cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
    } else {
        cout << "No valid combination found." << endl;
    }

    return 0;
}
