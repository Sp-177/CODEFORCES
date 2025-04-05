#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);                      

    long long n, m;
    cin >> n >> m;

    long long a[n], b[m]; // Use vectors instead of fixed-size arrays
    for (long long i = 0; i < n; i++) cin >> a[i];
    for (long long j = 0; j < m; j++) cin >> b[j];

    long long ans = 0, index_a = 0, index_b = 0;
    while (index_a < n && index_b < m) {
        while (index_a < n && index_b < m && a[index_a] < b[index_b]) index_a++;
        while (index_b < m && index_a < n && b[index_b] < a[index_a]) index_b++;
        if (index_a >= n || index_b >= m) break;

        long long cnt_b = 0, cnt_a = 0, num = a[index_a];
        while (index_a < n && a[index_a] == num) { cnt_a++; index_a++; }
        while (index_b < m && b[index_b] == num) { cnt_b++; index_b++; }
        ans += cnt_a * cnt_b;
    }

    cout << ans << endl;

    return 0;
}
