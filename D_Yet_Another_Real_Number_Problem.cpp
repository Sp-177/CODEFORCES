#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long qpow(long  long a,long long b){
    long long mod=1e9+7;
	long long c=1;a%=mod;
	while(b){
		if(b&1)c=c*a%mod;
		a=a*a%mod;b>>=1;
	}
	return c;
}
int main(){
int t;cin >> t;
while(t--){
    int n;cin>>n;
    long long arr[n];
    long long mod=1e9+7;
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<long long>ans;
    ans.push_back(0LL);
    long long simple = 0LL,multi = 0LL;
    for(int i=0;i<n;i++){
        // cout<<simple<<"x"<<multi<<"   ";
        long long num=(arr[i]*qpow(2*1LL,multi));
        num+=simple;num;
       long  long num2=(ans.back());
       num2+=arr[i];
        
        ans.push_back(max(num%mod,num2%mod)%mod);
        cout<<num<<"-"<<num2<<"-"<<ans.back()<<endl;
        
        while(arr[i]%(2*1LL)==0LL){
            arr[i]>>=1LL;
            multi+=1LL;
            multi%=mod;
        }
        simple+=arr[i];
        simple%=mod;        
    }
    for(int i=1;i<ans.size();i++)cout<<ans[i]<<' ';
    cout<<endl;
}

return 0;
}