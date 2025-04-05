#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
int t;cin>>t;
while(t--){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0)cnt++;
    }
    if(cnt==n){
        cout<<0<<endl;
        continue;
    }
    int start=-1,end=n;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){start=i;break;}
    }
    for(int i=n-1;i>=0;i--){
        if(arr[i]!=0){end=i;break;}
        
    }
    bool yes=true;
    for(int i=start;i<=end;i++){
        if(arr[i]==0){
            yes=false;break;
        }
    }
    if(yes){cout<<1<<endl;continue;}

    cout<<2<<endl;
}

return 0;
}