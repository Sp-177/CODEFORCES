#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    string arr1[]={"","","","",""};
    char arr[]={'a','e','i','o','u'};
    int ind=0;
    for(int i=0;i<n;i++){
        arr1[ind]+=arr[ind];
        ind++;
        ind=ind%5;
    }
    string ans="";
    for(auto i:arr1){
        ans+=i;
    }
    cout<<ans<<endl;
}
int main(){
    int t;cin>>t;
    while(t--){solve();}
    return 0;
}