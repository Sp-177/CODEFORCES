#include <iostream>
#include <vector>
#include <algorithm>  // for sort
#include <functional>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    
    vector<long long> arr(n);  // Use vector instead of raw array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Function to check if we can afford exactly `mid` items
    std::function<pair<long long, long long>(long long)> p_f = [&](long long mid) {
        if (mid == 0) return make_pair(0LL, 0LL); // If mid is 0, we can always afford 0 item
        vector<long long> b(n);
        
        // Calculate the adjusted cost of each item and store it in the array
        for (long long i = 0; i < n; i++) {
            long long cost = arr[i] + (i + 1)*mid;  // Adjust cost with index-based increase
            b[i] = cost;
        }
        
        long long sum = 0, cnt = 0;
        // Sort the costs to minimize the total sum of selected items
        sort(b.begin(), b.end());
        
        // Try to buy `mid` items within the budget
        for (int i = 0; i<mid; i++) {
            if (sum + b[i] > k) break;
            sum += b[i];
            cnt++;
        }
        
        return make_pair(cnt, sum);  
    };
    
    long long low = 0, high = n;
    
    // Perform binary search to find the maximum number of items we can afford
    while (low <= high) {
        long long mid = (low + high) / 2;
        auto pr = p_f(mid);
        if (pr.first >= mid && pr.second <= k) {
            low = mid + 1;  // Try to buy more items
        } else {
            high = mid - 1;  // Try to buy fewer items
        }
    }
    
    // Output the result
    cout << high << " " << p_f(high).second << endl;
    
    return 0;
}
