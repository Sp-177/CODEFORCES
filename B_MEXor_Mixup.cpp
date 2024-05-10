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

int computeXOR(int n) 
{ 
	
// If n is a multiple of 4 
if (n % 4 == 0) 
	return n; 

// If n%4 gives remainder 1 
if (n % 4 == 1) 
	return 1; 

// If n%4 gives remainder 2 
if (n % 4 == 2) 
	return n + 1; 

// If n%4 gives remainder 3 
return 0; 
} 
void Solve(){
    int a,b;cin>>a>>b;
    ll xr=computeXOR(a-1);
    ll x=xr^b;
    if(xr==b)cout<<a<<endl;
    else if(x==a)cout<<a+2<<endl;
    else cout<<a+1<<endl;


}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t;
	cin>>t;
	while(t--){
        Solve();       
    	}
}