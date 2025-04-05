#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin >> t;
    while(t--){
int n;cin >> n;
map<int,int>m;
for(int i=0;i<n;i++){
    int x;cin >> x;
    if(x<=n)m[x]++;
}
long long ans=0;
for(int i=n;i>=1;i--){
    long long sum=0;
    for(int j=1;j<=sqrt(i);j++){
        if(i%j==0){
            sum+=m[j];
            if(i/j<=n &&j!=(i/j)){
                sum+=m[i/j];
            }
        }
    }
    ans=max(ans,sum);
}
cout<<ans<<endl;}
return 0;
}