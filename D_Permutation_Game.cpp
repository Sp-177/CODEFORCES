 #include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll 		long long
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
#define d		double
#define all(x)		x.begin(),x.end()
#define que_max		priority_queue<int>
#define que_min		priority_queue<int,vi,greater<int>>
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

void Solve(){
    ll k;
    int n,x,y;cin>>n>>k>>x>>y;
    x--;y--;
    vi v1(n);F(0,n,1,i){cin>>v1[i];v1[i]--;}
    vi v2(n);F(0,n,1,i)cin>>v2[i];
    ll ans1=0,ans2=0;
    vb b(n),s(n);
    ll sb=0,ss=0;
    while(!b[x]){
        b[x]=true;
        ans1+=v2[x];
        sb++;
        if(v2[v1[x]]>=v2[x])x=v1[x];
    }
    while(!s[y]){
        s[y]=true;
        ans2+=v2[y];
        ss++;
        if(v2[v1[y]]>=v2[y])y=v1[y];
    }
    ll B=(k-sb)*v2[x];
    ll S=(k-ss)*v2[y];
    ans1+=B;
    ans2+=S;
    if(ans1>ans2)cout<<"Bodya"<<endl;
    else if(ans1==ans2)cout<<"Draw"<<endl;
    else cout<<"Sasha"<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t;
	cin>>t;
	while(t--){
        Solve();       
    	}
}