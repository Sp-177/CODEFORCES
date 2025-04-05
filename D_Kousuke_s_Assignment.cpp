#include <iostream>
#include <map>
using namespace std;

void slv() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        map<long long, int> mp;
        mp[0] = 1;
        long long s = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            s += a[i];
            if (mp[s]) {
                cnt++;
                mp.clear();
                mp[0] = 1;
                s = 0;
            }
            mp[s]++;
        }
        cout << cnt << endl;
    }
}

int main() {
    slv();
    return 0;
}
