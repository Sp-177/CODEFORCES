#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
long long tc;cin>>tc;
while(tc--){
    long double h,c,t;cin>>h>>c>>t;
    if(t==h){cout<<1<<endl;continue;}
    long double dif=(2*t-(h+c));
    if(dif<=0){cout<<2<<endl;continue;}
    long long k=(h-t)/(2*t-h-c);
    // cout<<k<<endl;
    long long k_l=k-1,k_r=k+1;
    long double d1=abs(t- ((k_l+1)*h+k_l*c)/(2*k_l+1)),d=abs(t- ((k+1)*h+k*c)/(2*k+1)),d2=abs(t- ((k_r+1)*h+k_r*c)/(2*k_r+1));
    long double mini=min({d1,d2,d});
    cout<<(mini==d1?2*k_l+1:mini==d?2*k+1:2*k_r+1)<<endl;
}

return 0;
}