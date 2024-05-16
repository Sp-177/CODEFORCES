#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll 		long long
#define ull 		unsigned long long
#define f 		first
#define sec 		second
#define pb 		push_back
#define pu 		push
#define ins     	insert
#define po      	pop()
#define pob     	pop_back()
#define pof     	pop_front()
#define pf      	push_front
#define is(x,i) 	x.find(i)!=x.end()  
#define e       	empty()
#define vi		vector<int>
#define dqi     	deque<int>
#define dqp     	deque<pii>
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
#define vc      	vector<char>
#define vvc     	vector<vc>
#define vll		vector<ll>
#define vb      	vector<bool>
#define vvb     	vector<vb>
#define p(a)		for(auto i:a){cout<<i<<" ";}cout<<endl
#define Pp(a,x)		for(auto i:a){cout<<i.x<<" ";}cout<<endl
#define pp(a)  		for(auto i:a){for(auto j:i){cout<<j<<' ';}cout<<endl;}cout<<endl
#define It(v) 		v::iterator
#define lb(x,i)        	lower_bound(all(x),i)
#define ub(x,i)      	upper_bound(all(x),i)



//Binary Expo
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

// Binary MUl
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

//nthRoot
ld nR(ll A, ll N)
{if(N==1)return A;
    if(A==1)return 1;
ld xPre = rand() % 10;
   ld eps = 1e-3;
      ld delX = INT_MAX;
      ld xK;
    while (delX > eps)
    {
          xK = ((N - 1.0) * xPre +
          (double)A/pow(xPre, N-1)) / (double)N;
        delX = abs(xK - xPre);
        xPre = xK;
    }
    return xK;
}

	
//xor first n numbers

int nX(int n) 
{ 
if (n % 4 == 0) 
	return n;  
if (n % 4 == 1) 
	return 1;  
if (n % 4 == 2) 
	return n + 1; 
return 0; 
} 


//Comparator Class -sets && maps

class Cmp{
public:
	const bool operator()(int&a,int&b){
	if(a>b)return true;
	else if(a==b)return a>b;
	return false;
}

};

// Compartor Func
static const bool cmp(int&a,int&b){
	if(a>b)return true;
	else if(a==b)return a>b;
	return false;
}

//cal nCr
ll nCr(ll n, ll r) {
        if (r > n) return 0;
   
    if (r == 0 || n == r) return 1;
        double res = 0;
       for (int i = 0; i < r; i++) {
          res += log(n-i) - log(i+1);
    }
    return (int)round(exp(res));
}

//Prime
bool isPrime(int n) 
{ 
    if (n <= 1) 
        return false; 
    for (int i = 2; i <= sqrt(n); i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 

//all divisors
vll nD(ll n) 
{ 
   vll ans; 
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
    string s;cin>>s;
    u_ss S;
    Fr(n-1,-1,1,i){
        string t=s.substr(i);
        S.insert(t);
        if(i+1<n){
            string t2=t.substr(0,1);
            string t3=t.substr(2);
            S.insert(t2+t3);
        }
    }
    cout<<S.size()<<endl;

}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t;
	cin>>t;
	while(t--){
        Solve();       
    	}
}