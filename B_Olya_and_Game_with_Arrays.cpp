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
static const bool cmp(vi&a,vi&b){
    if(a[0]>b[0])return true;
    else if(a[0]==b[0])return a[1]>b[1];
    return false;
}
void Solve(){
    int n;cin>>n;
    vvi v(n,vi(1));
    vvi v1(n,vi(2));
    F(0,n,1,i){
        int x;cin>>x;
        v[i].resize(x);
        F(0,x,1,j)cin>>v[i][j];
        sort(all(v[i]));
        v1[i][0]=(v[i].size()>1)?v[i][1]:0;
        v1[i][1]=v[i][0];
    }
    if(n==1)cout<<v[0][0]<<endl;
    else{
    sort(all(v1),cmp);
    ll ans=0;
    // cout<<" xx"<<endl;
    // F(0,n,1,i)cout<<v1[i][0]<<' '<<v1[i][1]<<endl;
    F(0,n-1,1,i){
        if(v1[i][0]==0)ans+=v1[i][1];
        else if(i!=n-1)ans+=v1[i][0];
    }
    int mini=INT_MAX;
    F(0,n,1,i)mini=min(mini,v1[i][1]);
    cout<<ans+mini<<endl;}

}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t;
	cin>>t;
	while(t--){
        Solve();       
    	}
}