#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll 		long long
#define f 		first
#define s 		second
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
#define u_sc		unordered_set<string>
#define u_ss		unordered_set<string>
#define ld		long double
#define d		double
#define all(x)		x.begin(),x.end()
#define que_max		priority_queue<int>
#define que_min		priority_queue<int,vi,greater<int>>
#define F(x,y,z,i)	for(int i=x;i<y;i=i+z)
#define fr(x,y,z,i)	for(int i=x;i>y;i=i-z)
#define Fa(x,i)		for(auto i:x)
#define vvi		vector<vi>
#define vc      vector<char>
#define vvc     vector<vc>
#define vb      	vector<bool>
#define vvb     	vector<vb>
#define print(a,i)	for(auto i:a){cout<<i<<" ";}cout<<endl

void Solve(){

}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t;
	cin>>t;
	while(t--){
        long long int n,a,b;
        cin>>a>>b>>n;
        int x=0;
        int y=0;
        long long int a1=a,b1=b;
        while(a1<=n){
            if(n%a1==0)x=x+1;
            a1*=a;
        }
        while(b1<=n){
            if(n%b1==0)y=y+1;
            b1*=b;
        }
    //   cout<<x<<y<<a<<b<<endl;
        u_si S;
        F(0,x+1,1,i){
            F(0,y+1,1,j){
                long long int d1=(pow(a,i));
                long long int d2=(pow(b,j));
                d2*=d1;
                // cout<<<<":";
                long long int aq=n/d2;
                
                if(aq>0){S.insert(aq);}
            }
        }
        cout<<S.size()<<endl;
        
    }
}