#include<iostream>
#include<vector>
#include<set>
#include<numeric> // for gcd

using namespace std;

// Function to calculate GCD of two numbers
long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false); // Fast input/output
    cin.tie(0); // Fast input/output

    int t; 
    cin >> t; // Number of test cases
    
    while(t--) {
        int n; 
        cin >> n; // Number of elements in the array
        
        vector<long long> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Use a set to store unique elements
        set<long long> s(arr.begin(), arr.end());

        if (s.size() == 1) {
            // All elements are already equal, no operations needed
            cout << 1 << '\n';
            continue;
        }

        // Calculate the GCD of the differences between adjacent elements
        long long dif = *s.rbegin() - *s.begin(); // Max difference
        
        // Iterate through the set and compute GCD of differences
        long long last = *s.begin();
        for(auto i : s) {
            dif = gcd(dif, i - last);
            last = i;
        }

        // Finding an+1 (new element that minimizes operations)
        long long a_n_1 = *s.rbegin() - dif;
        while(s.find(a_n_1) != s.end()) {
            a_n_1 -= dif;
        }

        long long great = *s.rbegin();
        long long ans = min((long long)n, (great - a_n_1) / dif);

        // Calculating total operations
        for(auto i : s) {
            ans += (great - i) / dif;
        }

        // Output the result
        cout << ans << '\n';
    }

    return 0;
}
