#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);                      
    
    long double c;
    cin >> c;

    auto predicate_func = [&](long double val) -> long double {
        long double sq = val * val, root = sqrt(val);
        return (sq + root);
    };

    long double low = 0.0, high = c, error = 1e-7;
    while (high - low > error) {
        long double mid = (low + high) / 2.0;
        long double func = predicate_func(mid);
        
        if (abs(func - c) <= error) {
            cout << fixed << setprecision(6) << mid << endl;
            return 0;
        } else if (func > c) {
            high = mid;
        } else {
            low = mid;
        }
    }

    cout << fixed << setprecision(6) << (low + high) / 2.0 << endl;

    return 0;
}
