#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      

int t;cin>>t;
while(t--){
    int n;cin>>n;
    string s;
    cin>>s;
    int first_p=n,last_s=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='s')last_s=i;
        if(s[i]=='p')first_p=min(first_p,i);
    }


    if(last_s<first_p&&(last_s==-1||last_s==0||first_p==n||first_p==n-1))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
return 0;
}