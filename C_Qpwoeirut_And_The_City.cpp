#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long heights[n];
        for (int i = 0; i < n; i++) cin >> heights[i];

        long long diff[n - 2];
        int index = 0;
        for (int i = 1; i < n - 1; i++) {
            long long d1 = max(0LL, heights[i - 1] - heights[i] + 1);
            long long d2 = max(0LL, heights[i + 1] - heights[i] + 1);
            diff[index++] = max(d1, d2);
        }
        long long ans=0;
        if(n&1){
            for(int i=0;i<n-2;i+=2)ans+=diff[i];
        }else{

        }
        cout<<ans<<"\n";
    }

    return 0;
}
