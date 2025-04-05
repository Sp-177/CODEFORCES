#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

unordered_set<ll>visit;
ll recur(ll num, map<ll, ll>& dp, const vector<ll>& nums) {
    if (num == 0) return 0;
    if (dp.find(num) != dp.end()) return dp[num];

    ll res = LLONG_MAX;
    
    for (ll i : nums) {
        if (num < i) break;
        if(visit.find(i) == visit.end()){
            visit.insert(i);
            
        res = min(res, recur(num - i, dp, nums) + 1);
        visit.erase(i);
    }}

    dp[num] = res;
    return dp[num];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    cin >> t;

    vector<ll> fac(16, 1);
    for (int i = 1; i <= 15; i++) {
        fac[i] = fac[i - 1] * i;
    }

    vector<ll> nums;
    for (ll i = 1; i <= 15; i++) nums.push_back(fac[i]);
    for (ll i = 2; i <= 40; i++) {
        ll num = 1LL << i;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    while (t--) {
        ll n;
        cin >> n;
        map<ll, ll> dp;
        cout << recur(n, dp, nums) << endl;
    }

    return 0;
}
