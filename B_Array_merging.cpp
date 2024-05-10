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

void Solve(){
    int n;cin>>n;
   
    int maxi=0;
    vi a(n),b(n);
    F(0,n,1,i)cin>>a[i];
    F(0,n,1,i)cin>>b[i];
    vi v1=a;
    vi v4=a;
    v1.insert(v1.end(),all(b));
    vi v2=b;
    vi v3=b;
    v2.insert(v2.end(),all(a));
    reverse(all(a));reverse(all(b));
    v4.insert(v4.end(),all(b));
    v3.insert(v3.end(),all(a));
    //F(0,2*n,1,i)cout<<v1[i]<<' '<<v2[i]<<' '<<v3[i]<<' '<<v4[i]<<endl;
    int len1=1,len2=1,len3=1,len4=1;
    F(0,2*n-1,1,i){
        if(v1[i]==v1[i+1])len1++;
        else len1=1;
        if(v2[i]==v2[i+1])len2++;
        else len2=1;
        if(v3[i]==v3[i+1])len3++;
        else len3=1;
        if(v4[i]==v4[i+1])len4++;
        else len4=1;
        
        maxi=max(maxi,max(max(len3,len4),max(len1,len2)));
    }
    cout<<maxi<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t;
	cin>>t;
	while(t--){
        Solve();       
    	}
}