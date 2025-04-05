#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int t;cin >> t;
while(t--){
    int n;cin>>n;
    string st;cin >> st;
    if(st[0]=='1'||st[n-1]=='1'){cout<<"YES"<<endl;continue;}
    bool fact = false;
    for(int i=0;i<n-1;i++){
        if(st[i]=='1'&&st[i+1]=='1'){
            cout<<"YES"<<endl;
            fact=true;
            break;
        }
    }
    if(fact)continue;
    cout<<"NO"<<endl;
}

return 0;
}