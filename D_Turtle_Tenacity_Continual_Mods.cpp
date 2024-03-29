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
#define Fr(x,y,z,i)	for(int i=x;i>y;i=i-z)
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
        int n;cin>>n;
        vi v(n);
        vi v1(n);
        vi v2(n);
        priority_queue<int>q;
        cin>>v[0];
        int j=1;
        v1[0]=v[0];
        v2[0]=v[0];
        F(1,n,1,i){
            int x;cin>>x;
            if(v[j-1]==x)q.push(x);
            else {v[j++]=x;}
            v1[i]=x;
            v2[i]=x;
        }
        sort(all(v2));
        sort(v.begin(),v.begin()+j-1);
        while(!q.empty()){v[j++]=q.top();q.pop();}
        
        int ans=v[0];
        int k1=v1[0];
        int k3=v2[0];
        F(1,n,1,i){
            ans=ans%v[i];
            k1=k1%v1[i];
            k3=k3%v2[i];
    
        }
        int ans1=v[n-1];
        int k2=v1[n-1];
        int k4=v2[n-1];
        Fr(n-2,-1,1,i){
            // cout<<v[i]<<"x";
            ans1=ans1%v[i];
            k2=k2%v1[i];
            k4=k4%v2[i];
        }
        // cout<<ans<<ans1<<endl;
        if(ans!=0|| ans1!=0 ||k1!=0||k2!=0 ||k3!=0 ||k4!=0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

	}
	return 0;
}