#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll 		long long
#define f 		first
#define s 		second
#define pb 		push_back
#define p 		push
#define vi		vector<ll>
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
#define Fa(x,i)		for(auto i:x)
#define vvi		vector<vi>
#define vc      vector<char>
#define vvc     vector<vc>
#define vb      	vector<bool>
#define vvb     	vector<vb>
#define print(a,i)	for(auto i:a){cout<<i<<" ";}cout<<endl



int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t;
	cin>>t;
	while(t--){
       long long n,m;
       cin>>n>>m;
       
       vi arr(n);
       F(0,n,1,i){cin>>arr[i];}
       string removal;cin>>removal;
       int start=0,end=n-1;
       for(char c:removal){
        if(start==end)break;
        if(c=='L'){
            start++;
        }
        else end--;
       }
       vi ans;
       int ind=n-2;
       long long pro=arr[start]%m;
       ans.push_back(pro);
       while(start>=0&&end<n&&ind>=0){
            if(removal[ind]=='L'){
                start--;
                pro*=arr[start];
                
            }
            else{
                end++;
                pro*=arr[end];
            }
            pro%=m;
            ans.push_back(pro);
            ind--;
       }
       for(int i=ans.size()-1;i>=0;i--)cout<<ans[i]<<" ";
       cout<<endl;
    }
	return 0;
}
