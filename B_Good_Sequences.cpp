#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) cin >> arr[i];

    auto sieve=[&](int n)->set<int>{
        set<int>primes;
        bool vec[n+1];
        memset(vec, true, sizeof(vec));
        for(int i=2;i*i<=n;i++){
            for(int j=i*i;j<=n;j+=i)vec[j]=false;
        }
        for(int i=2;i<=n;i++)if(vec[i])primes.insert(i);

        return primes;
    };
    auto all_primes=sieve(arr[n-1]);
    map<int,vector<int>>multiples;
    for(int i=0;i<n;i++){
        int x=arr[i];
        for(int j=1;j*j<=x;j++){
            if((x%j)==0){
                int another=x/j;
                if(another!=j && all_primes.find(another)!=all_primes.end())multiples[i].push_back(another);
                if(all_primes.find(j)!=all_primes.end())multiples[i].push_back(j);
            }

        }
    }
    int dp[n];
    memset(dp, 0, sizeof(dp));
    map<int,int>max_of_multiple;
    for(int i=n-1;i>=0;i--){
        int maxi=1;
        for(int j:multiples[i]){
            maxi=max(maxi,max_of_multiple[j]+1);
        }
        dp[i]=maxi;
        for(int j:multiples[i]){
            max_of_multiple[j]=max(max_of_multiple[j],dp[i]);
        }
        
    }

    cout<<(*max_element(dp,dp+n))<<endl;

    return 0;
}
