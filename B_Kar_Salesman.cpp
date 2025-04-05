#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int t;cin>>t;
while(t--){
    long long n,x;cin>>n>>x;
    vector<long long>v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    long long ans1=*max_element(v.begin(),v.end());
    long long total=accumulate(v.begin(),v.end(),0LL);
    long long ans2=1LL*(((total+x-1)*1LL)/(x*1LL));
    cout<<max(ans1,ans2)<<endl;
    
    }

return 0;
}