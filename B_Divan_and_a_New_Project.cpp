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
#define que_max		priority_queue<int>
#define que_min		priority_queue<int,vi,greater<int>>
#define F(x,y,z,i)	for(int i=x;i<y;i=i+z)
#define Fr(x,y,z,i)	for(int i=x;i>y;i=i-z)
#define Fa(x,i)		for(auto i:x)
#define vvi		vector<vi>
#define vc      vector<char>
#define vvc     vector<vc>
#define vll		vector<ll>
#define vb      	vector<bool>
#define vvb     	vector<vb>
#define print(a)	for(auto i:a){cout<<i<<" ";}cout<<endl
#define Print(a,x)	for(auto i:a){cout<<i.x<<" ";}cout<<endl

long long mod = 1000000007;

long long power(long a, long b) {
        long res = 1;
        while (b) {
            if ((b & 1) == 1)res = (res * a) % mod;
            a = (a * a) % mod;
            b=b >> 1;
        }
        return res;
}

long long mul(long a, long b) {
        long res = 1;
        while (b) {
            if ((b & 1) == 1)res = (res + a) % mod;
            a = (a * 2) % mod;
            b=b >> 1;
        }
        return res;
}
class Cmp{
    public:
    bool operator()(auto &a,auto &b){
        if(a>b)return true;
    else if(a==b)return a>b;
    return false;
    }
};

static const bool cmp(pii&a,pii&b){
    if(a.f>b.f)return true;
    else if(a.f==b.f)return a.sec>b.sec;
    return false;
}
void Solve(){
    ll n;cin>>n;
    vll ans(n+1);
    ans[0]=0;
    vpi v(n);
    F(0,n,1,i){
        int x;cin>>x;v[i]={x,i};
    }
    sort(all(v),cmp);
    ll pos=1,neg=-1, index=0;
    ll sum=0;
    // Print(m,f);
    // Print(m,sec);
    Fa(v,i){
        if(index&1){ans[i.sec+1]=neg;sum+=2*i.f*abs(neg);neg--;}
        else {ans[i.sec+1]=pos;sum+=2*i.f*abs(pos);pos++;}
        index++;
    }
    cout<<sum<<endl;
    print(ans);
}   
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t;
	cin>>t;
	while(t--){
        Solve();       
    	}
}