#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

int t;cin >> t;
while(t--){
    long long n,m,k;
    cin >> n >> m >> k;
    if(k==1){cout<<1<<endl;}
    else if(k>=4){cout<<0<<endl;}
    else if(k==2){
        cout<<min(m,((m/n) + n -1))<<endl;
    }
    else{
        cout<<max(0LL,m - n- (m/n) +1)<<endl;
    }
}
return 0;
}