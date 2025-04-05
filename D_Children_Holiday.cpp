      #include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
long long m,n;
cin >> m >> n;
long long persons[n][3];
for(long long i = 0; i < n; i++)cin >> persons[i][0] >> persons[i][1] >> persons[i][2];
long long low = 0, high = 1e18;

// Function to determine how many balloons each assistant can inflate within `mid` time
auto predicate_funt = [&](long long mid) -> vector<long long> {
    vector<long long> ans(n, 0);
    long long sum = 0;

    for (long long i = 0; i < n; i++) {
        long long ti = persons[i][0], zi = persons[i][1], yi = persons[i][2];
        long long cycle_time = ti * zi + yi;
        long long full_cycles = mid / cycle_time;
        long long remaining_time = mid % cycle_time;
  
        long long balloons = full_cycles * zi;
        balloons += min(zi, remaining_time / ti);

        ans[i] = balloons;
        sum += balloons;
        if (sum >= m) return ans; // Early exit if we meet the requirement
    }

    return ans;
};

// Function to count total balloons inflated from a vector
auto count_balloons = [&](vector<long long>& arr) -> long long {
    long long sum = 0;
    for (long long i : arr) sum += i;
    return sum;
};

// Binary search for the minimum time required
while (low <= high) {
    long long mid = (low + high) / 2;
    vector<long long> arr = predicate_funt(mid);
    long long cnt = count_balloons(arr);
    if (cnt >= m) high = mid - 1;
    else low = mid + 1;
}

cout << low << endl;
vector<long long> arr = predicate_funt(low);

// Adjust the distribution to ensure exactly `m` balloons are inflated
long long inflated_balloons = 0;
for (long long i = 0; i < n; i++) inflated_balloons += arr[i];
for (long long i = 0; i < n && inflated_balloons > m; i++) {
    long long excess = min(inflated_balloons - m, arr[i]);
    arr[i] -= excess;
    inflated_balloons -= excess;
}

for (long long i = 0; i < n; i++) cout << arr[i] << " ";
cout << endl;
return 0;
}
