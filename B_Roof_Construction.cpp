 #include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll 		long long
#define ull 		unsigned long long
#define f 		first
#define sec 		second
#define pb 		push_back
#define p 		push
#define vi		vector<int>
#define pii 		pair<int,int>
#define vpi		vector<pii>
#define vs		vector<string>
#define u_mi		unordered_map<int,int>
#define u_mc 		unordered_map<char,int>
#define u_ms		unordered_map<string,int>
#define u_si 		unordered_set<int>
#define u_sc		unordered_set<char>
#define u_ss		unordered_set<string>
#define ld		long double
#define dou		double
#define all(x)		x.begin(),x.end()
#define que_max		priority_queue<ll>
#define que_min		priority_queue<ll,vll,greater<ll>>
#define F(x,y,z,i)	for(ll i=x;i<y;i=i+z)
#define Fr(x,y,z,i)	for(ll i=x;i>y;i=i-z)
#define Fa(x,i)		for(auto i:x)
#define vvi		vector<vi>
#define vc      vector<char>
#define vvc     vector<vc>
#define vll		vector<ll>
#define vb      	vector<bool>
#define vvb     	vector<vb>
#define print(a,i)	for(auto i:a){cout<<i<<" ";}cout<<endl

long long power(long a, long b) {
long long mod=1e9+7;
        long res = 1;
        while (b) {
            if ((b & 1) == 1)res = (res * a) % mod;
            a = (a * a) % mod;
            b=b >> 1;
        }
        return res;
}

long long mul(long a, long b) {
long long mod=1e9+7;
        long res = 1;
        while (b) {
            if ((b & 1) == 1)res = (res + a) % mod;
            a = (a * 2) % mod;
            b=b >> 1;
        }
        return res;
}


void Solve(){
    int n;cin>>n;
    int max_pow=log2(n-1);
    int max_num=power(2,max_pow);
    Fr(n-1,max_num-1,1,i)cout<<i<<' ';
    F(0,max_num,1,i)cout<<i<<' ';
    cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t;
	cin>>t;
	while(t--){
        Solve();       
    	}
}