#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t = 1;
    // cin>>t;
    ll spf[100001];
    
    for (int i = 1; i <= 100000; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i <= 100000; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= 100000; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    while (t--) {
        ll n, m;
        cin >> n >> m;
        ll a[n + 1] = {0};  // Ensure it's large enough
        map<int, int> mp;

        while (m--) {
            string sign, num;
            cin >> sign >> num;
            ll x = stoi(num);

            if (sign == "+") {
                if (a[x] == 1) {
                    cout << "Already on" << endl;
                } else {
                    bool check = true;
                    ll number = x;
                    ll conflict_with = -1;

                    // Check all prime factors of x
                    while (number > 1) {
                        ll prime = spf[number];
                        if (mp.find(prime) != mp.end()) {
                            check = false;
                            conflict_with = mp[prime];
                            break;
                        }
                        while (number % prime == 0) number /= prime;
                    }

                    if (check) {
                        // Turn it on and store all its prime factors
                        number = x;
                        while (number > 1) {
                            ll prime = spf[number];
                            mp[prime] = x;
                            while (number % prime == 0) number /= prime;
                        }
                        a[x] = 1;
                        cout << "Success" << endl;
                    } else {
                        cout << "Conflict with " << conflict_with << endl;
                    }
                }
            } else {  // sign == "-"
                if (a[x] == 0) {
                    cout << "Already off" << endl;
                } else {
                    cout << "Success" << endl;
                    a[x] = 0;

                    // Remove all prime factors from mp
                    ll number = x;
                    while (number > 1) {
                        ll prime = spf[number];
                        mp.erase(prime);
                        while (number % prime == 0) number /= prime;
                    }
                }
            }
        }
    }

    return 0;
}
