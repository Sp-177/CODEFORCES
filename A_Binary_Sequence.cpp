
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t=1;
    cin>>t;
    while(t--){
    int n;cin>>n;
    string str;cin>>str;
    int ans=n;
    int i=0,j=n-1;
    while(i<=j){
        if(str[i]==str[j])break;
        else if(str[i]!=str[j]){
            if(i==j)ans--;
            else ans-=2;
        }
        i++;
        j--;
    }   
    cout<<ans<<"\n";
        
    }

    return 0;
}