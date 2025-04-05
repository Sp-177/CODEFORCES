#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll 		    long long
#define ull 	    unsigned long long
#define ld		    long double
#define db		    double
#define fs		    first
#define sec 	    second
#define pb 		    push_back
#define pu 		    push
#define ins         insert
#define all(x)		x.begin(),x.end()
#define po      	pop()
#define pob     	pop_back()
#define pof     	pop_front()
#define pf      	push_front
#define fr		    front()
#define ba		    back()
#define fi(x,i) 	x.find(i)!=x.end()
#define emp       	empty()
#define sz		size()
#define pa          pair
#define pi          pa<int,int>
#define vec	        vector
#define vi		    vec<int>
#define vpi		    vec<pi>
#define vvi		    vec<vi>
#define vs		    vec<string>
#define vl		vec<ll>
#define vc      	vec<char>
#define vb      	vec<bool>
#define dq          dequeue
#define mc		map<char,int>
#define mi		map<int,int>
#define mpi		map<pi,int>
#define um          unordered_map
#define umi		    um<int,int>
#define umc 		um<char,int>
#define ums		    um<string,int>
#define si		set<int>
#define spi		set<pi>
#define sc		set<char>
#define sv		set<vi>
#define us          unordered_set
#define usi 		us<int>
#define usc		    us<char>
#define uss		    us<string>
#define pq          priority_queue
#define que_max		pq<int>
#define que_min		pq<int,vi,greater<int>>
#define que         pq<pi,vpi>
#define que_get	    pq<pq,vpi,greater<pi>>
#define inp(x)	for(int i=0;i<x.size();i++){cin>>x[i];}
#define F(x,y,z,i)	for(int i=x;i<y;i=i+z)
#define Fr(x,y,z,i)	for(int i=x;i>y;i=i-z)
#define Fa(x,i)		for(auto i:x)
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


//cal nCr

long long nCr(long long n, long long r)
{if (r > n) return 0;if (r == 0 || n == r) return 1;long double res = 0;for (int i = 0; i < r; i++) {res += log(n-i) - log(i+1);}return (long long)round(exp(res));}

//Prime

bool isPrime(int n) 
{if (n <= 1) return false; for (int i = 2; i <= sqrt(n); i++){if(n % i == 0)return false;}return true;} 

//all divisors

vector<long long> nD(ll n){
vector<long long>ans;for (int i=1; i<=sqrt(n); i++) { if (n%i == 0) { if (n/i == i){ans.push_back(i);}else{ans.push_back(i);ans.push_back(n/i);} }}return ans; } 

//BinaryString

string dB(int n)
{string ans="";for (int i = 31; i >= 0; i--){int k = n >> i;if (k & 1)ans="1"+ans;else ans="0"+ans;}reverse(ans.begin(),ans.end());return ans;}

//String to Decimal

long long sD(string s){
reverse(s.begin(),s.end());long long ans=0;long p=0;for(char i:s){if(i=='1'){long fac=pow(2,p);ans+=fac;}p++;}return ans;}


// Sieve Prime

vector<bool>sieve(int n){
vector<bool>p(n+1,true);p[0]=p[1]=false;for(int i=2;i<=sqrt(n);i++){if(p[i]){for(int j=i*i;j<=n;j+=i){p[j]=false;}}}return p;}


// Compartor Func

static const bool cmp(int&a,int&b){ 		// 	EDIT HERE 	!!!

	if(a>b)return true;
	else if(a==b)return a>b;
	return false;
}

//Comparator Class ->						 sets && maps && priority queue

class Cmp{public:const bool operator()(int&a,int&b){		// 	EDIT HERE 	!!!

	if(a>b)return true;
	else if(a==b)return a>b;
	return false;
}};

//Trie Class

class Node{
    public:
    Node* arr[26];				//	EDIT HERE 	!!!
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


//Segment Tree

class St{
	public:

	vector<int>tree;

	vector<int>arr;
	
	vector<int>lazy;

	St(int n)
	{
	arr.resize(n);
	tree.resize(4*n);
	lazy.resize(4*n);
	}
	
	void build(int node,int st,int end,vector<int>&arr)
	{
		if(st==end){
			tree[node]=arr[st];
			return;
		}
		int mid=(st+end)/2;
		build(2*node+1,st,mid,arr);
		build(2*node+2,mid+1,end,arr);

		tree[node]=tree[2*node+1]+tree[2*node+2]; 			// 	EDIT HERE	!!!
	}

	int query(int node,int st,int end,int low,int high)
	{
		if(lazy[node]!=0){
			tree[node]=(end-st+1)*lazy[node];
			if(st!=end){
			lazy[2*node+1]=lazy[node];
			lazy[2*node+2]=lazy[node];
			}
			lazy[node]=0;
		}
		if(st>high||end<low){return 0;}
		else if(low<=st&&end<=high){return tree[node];}					
		int mid=(st+end)/2;
		return query(2*node+1,st,mid,low,high)+query(2*node+2,mid+1,end,low,high);		// 	EDIT 	HERE	
	}
	
	void update(int node,int st,int end,int low,int high,int val){
		if(lazy[node]!=0){
			tree[node]=(end-st+1)*lazy[node];
			if(st!=end){	
				lazy[2*node+1]=lazy[node];
				lazy[2*node+2]=lazy[node];

			}
			lazy[node]=0;
		}
		if(st>high||end<low){return ;}
		if(low<=st&&end<=high){
			tree[node]=(end-st+1)*val;
			if(st!=end){
				lazy[2*node+1]=val;
				lazy[2*node+2]=val;	
			}
			
		}
		int mid=(st+end)/2;
		update(2*node+1,st,mid,low,high,val);
		update(2*node+2,mid+1,end,low,high,val);
		tree[node]=tree[2*node+1]+tree[2*node+2];			// 		EDIT HERE
		
		

	}
	

};


// Fenwick Tree 

class Ft{
	public:
	vector<int>arr;		
	Ft(int n){
	arr.resize(n+1,0);
	}
	
	void update(int ind,int val)			//		UPDATE
	{						// FOR NEW CONSTRUCTION UPDATE EVERY VALUE
	ind++;
	while(ind<arr.size()){
		arr[ind]+=val;				// 	EDIT 	HERE 	
		ind+=(ind&(-ind));
	}
	}
	int sum(int ind){
	int ans=0;
	ind++;
	while(ind>0){
	ans+=arr[ind];
	ind-=(ind&(-ind));
	}
        return ans;
    }
	
	
	int query(int l,int r)					//	QUERY RANGE 	FT
	{
		return sum(r)-sum(l-1);
	}

	int lowb(int sumRange){					// LOWER 	BOUND 		FT
	int curr=0,presum=0;
	for(int i=log2(arr.size());i>=0;i--){
	if(arr[curr+(1<<i)]+presum<sumRange){
		curr=curr+(1<<i);
		presum+=arr[curr];
		}
	}
	return curr+1;
	}
	
};

auto init=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return ' ';}();

void Solve()
{
    int n;cin>>n;
    string s=to_string(n);
    cout<<(s[0]-'0'+s[1]-'0')<<endl;


}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t=1;
	cin>>t;
	while(t--){Solve();}
}

