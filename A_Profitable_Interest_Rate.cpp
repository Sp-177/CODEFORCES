#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int t;cin >> t;
while(t--){
    int a,b;cin>>a>>b;
    if(a>=b)cout<<a<<endl;
    else if(b>2*(a)){
        cout<<0<<endl;
    }
    else{
        int req=b-a;
        cout<<a-req<<endl;
    }
}

return 0;
}