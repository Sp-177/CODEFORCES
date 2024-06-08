#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll 		long long
#define ull 		unsigned long long
#define fs		first
#define pi		pair<ll,ll>
#define pa(x,y)		pair<x,y>
#define sec 		second
#define pb 		push_back
#define pu 		push
#define ins     	insert
#define po      	pop()
#define pob     	pop_back()
#define pof     	pop_front()
#define pf      	push_front
#define fr		front()
#define ba		back()
#define fi(x,i) 	x.find(i)!=x.end()
#define emp       	empty()
#define vi		vector<ll>
#define dqi     	deque<ll>
#define dqp     	deque<pi>
#define vpi		vector<pi>
#define vs		vector<string>
#define u_mi		unordered_map<ll,l>
#define u_mc 		unordered_map<char,int>
#define u_ms		unordered_map<string,int>
#define u_si 		unordered_set<ll>
#define u_sc		unordered_set<char>
#define u_ss		unordered_set<string>
#define ld		long double
#define db		double
#define all(x)		x.begin(),x.end()
#define que_max		priority_queue<ll>
#define que_min		priority_queue<ll,vll,greater<ll>>
#define F(x,y,z,i)	for(ll i=x;i<y;i=i+z)
#define Fr(x,y,z,i)	for(ll i=x;i>y;i=i-z)
#define Fa(x,i)		for(auto i:x)
#define vvi		vector<vi>
#define vc      	vector<char>
#define vvc     	vector<vc>
#define vb      	vector<bool>
#define vvb     	vector<vb>
#define pr(a)		for(auto i:a){cout<<i<<" ";}cout<<endl
#define ppr(a,x)		for(auto i:a){cout<<i.x<<" ";}cout<<endl
#define pp(a)  		for(auto i:a){for(auto j:i){cout<<j<<' ';}cout<<endl;}cout<<endl
#define lb(x,i)        	lower_bound(all(x),i)
#define ub(x,i)      	upper_bound(all(x),i)




//Binary Expo

long long power(long a, long b)
{long long mod=1e9+7;long long res = 1;while (b) {if ((b & 1) == 1)res = (res * a) % mod;a = (a * a) % mod;b=b >> 1;}return res;}

// Binary MUl

long long mul(long a, long b)
{long long mod=1e9+7;long res = 1;while (b) {if ((b & 1) == 1)res = (res + a) % mod;a = (a * 2) % mod;b=b >> 1;}return res;}

//nthRoot

long double nR(ll A, ll N)
{if(N==1)return A;if(A==1)return 1;long double xPre =rand()%10;long double eps =1e-3;long double delX=INT_MAX;long double xK;
while(delX > eps){xK = ((N - 1.0)*xPre +(double)A/pow(xPre, N-1)) / (double)N;delX = abs(xK - xPre);xPre = xK;}return xK;}

	
//xor first n numbers

int nX(int n) 
{if(n % 4 == 0)return n;if(n % 4 == 1)return 1;if(n % 4 == 2)return n + 1;return 0;} 


//Comparator Class -> sets && maps && priority queue

class Cmp{public:const bool operator()(int&a,int&b){

	if(a>b)return true;
	else if(a==b)return a>b;
	return false;
}};

// Compartor Func

static const bool cmp(int&a,int&b){

	if(a>b)return true;
	else if(a==b)return a>b;
	return false;
}

//cal nCr

long long nCr(long long n, long long r)
{if (r > n) return 0;if (r == 0 || n == r) return 1;long double res = 0;for (int i = 0; i < r; i++) {res += log(n-i) - log(i+1);}
return (long long)round(exp(res));
}

//Prime

bool isPrime(int n) 
{if (n <= 1) return false; for (int i = 2; i <= sqrt(n); i++){if(n % i == 0)return false;}return true; 
} 

//all divisors

vector<long long> nD(ll n) 
{ vector<long long>ans;for (int i=1; i<=sqrt(n); i++) { if (n%i == 0) { if (n/i == i){ans.push_back(i);}else{ans.push_back(i);ans.push_back(n/i);} }}return ans; 
} 

//BinaryString

string dB(int n)
{string ans="";for (int i = 31; i >= 0; i--){int k = n >> i;if (k & 1)ans="1"+ans;else ans="0"+ans;}reverse(ans.begin(),ans.end());return ans;}

//String to Decimal

long long sD(string s){
reverse(s.begin(),s.end());long long ans=0;long p=0;for(char i:s){if(i=='1'){long fac=pow(2,p);ans+=fac;}p++;}return ans;}


//Trie Class

class Node{
    public:
    Node* arr[26];
    bool end;
    Node(){
        end=false;
        for (int i = 0; i < 26; i++) {
            arr[i] = NULL;
        }
    }
    Node* getNode(char c){
        return arr[c-'a'];
    }
};
class Trie{
    public:
    Node*root;
    Trie(){root=new Node();}
    void insert(string s){
        Node* node=root;
        for(char i:s){
            if(node->getNode(i)==NULL){
                Node* new_node=new Node();
                node->arr[i-'a']=new_node;
            }
            node=node->getNode(i);
            
        }
        node->end=true;

    }
    bool search(string s){
        Node* node=root;
        for(char i:s){
            if(node->getNode(i)==NULL){
                return false;
            }
            node=node->getNode(i);
            
        }
        return node->end;
    }
};


//Disjoint Set

class Ds{
	public:
	vector<int>par;
	int up(int node){
		if(par[node]==node){return node;}
        return par[node]=up(par[node]);
	}
	void ds(int n1,int n2){
	int p1=up(n1);
	int p2=up(n2);
	par[n2]=p1;
	par[p2]=p1;
	}
};



//LeetCode booster

// auto init=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return ' ';}();

void Solve()
{

    int n;cin>>n;
    vi v(n);
    ll g=1;
    F(0,n,1,i){
        cin>>v[i];
        g=(g*v[i])/__gcd(v[i],g);
        // cout<<g;
        
    }
    // cout<<g<<endl;
    int sum=0;
    vi ans(n);
    F(0,n,1,i){
        sum+=g/v[i];
        ans[i]=g/v[i];
    }
    if(sum>=g){cout<<-1<<endl;}
    else {
        pr(ans);
    }



}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t=1;
	cin>>t;
	while(t--){Solve();}
}