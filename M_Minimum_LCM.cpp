 #include<iostream>
#include<bits/stdc++.h>
#include <numeric> 
using namespace std;

#define ll 		long long
#define ull 	unsigned long long
#define f 		first
#define sec 	second
#define pb 		push_back
#define pu 		push
#define ins     insert
#define po      pop()
#define pob     pop_back()
#define pof     pop_front()
#define pf      push_front
#define is(x,i) x.find(i)!=x.end()  
#define e       empty()
#define vi		vector<int>
#define dqi     deque<int>
#define dqp     deque<pii>
#define pii 	pair<int,int>
#define vpi		vector<pii>
#define vs		vector<string>
#define u_mi	unordered_map<int,int>
#define u_mc 	unordered_map<char,int>
#define u_ms	unordered_map<string,int>
#define u_si 	unordered_set<int>
#define u_sc	unordered_set<char>
#define u_ss	unordered_set<string>
#define ld		long double
#define d		double
#define all(x)		x.begin(),x.end()
#define que_max		priority_queue<int>
#define que_min		priority_queue<int,vi,greater<int>>
#define F(x,y,z,i)	for(int i=x;i<y;i=i+z)
#define Fr(x,y,z,i)	for(int i=x;i>y;i=i-z)
#define Fa(x,i)		for(auto i:x)
#define vvi		vector<vi>
#define vc      vector<char>
#define vvc     vector<vc>
#define vll		vector<ll>
#define vb      vector<bool>
#define vvb     vector<vb>
#define print(a,i)	for(auto i:a){cout<<i<<" ";}cout<<endl

long mod = 1000000007;

long power(long a, long b) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
}

vi nD(ll n) 
{ 
   vi ans; 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
                if (n/i == i)ans.pb(i);
  
            else {ans.pb(i);ans.pb(n/i);} 
        } 
    }
    
return ans; 
} 


void Solve(){
    int n;cin>>n;
    int l=n-1;
    vi v=nD(n);
    // print(v,i);
    Fa(v,i)if(i!=n)l=min(l,n-i);
    cout<<n-l<<' '<<l<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t;
	cin>>t;
	while(t--){
        Solve();       
    	}
}