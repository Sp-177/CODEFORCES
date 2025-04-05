#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int t;cin>>t;
while(t--){
    long long n,m,x,y;
    cin>>n>>m>>x>>y;
    cout<<((n-x)*m+(n-x)*(m-1)+(m-y))<<endl;
}

return 0;
}