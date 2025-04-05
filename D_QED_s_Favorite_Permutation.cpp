#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,q;cin>>n>>q;
        
        int arr[n];
        bool sorted=true;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i!=0){
                if(arr[i]<arr[i-1])sorted=false;
            }
        }
        string str;cin>>str;
        set<int>s;
        int pre[n],suf[n];
        pre[0]=arr[0];
        suf[n-1]=arr[n-1];
        for(int i=1;i<n;i++)pre[i]=max(pre[i-1],arr[i]);
        for(int i=n-2;i>=0;i--)suf[i]=min(suf[i+1],arr[i]);
        for(int i=0;i<n-1;i++){
            if(str[i]=='L'&&str[i+1]=='R'&&pre[i]>suf[i+1]){s.insert(i);}
        }
        while(q--)
        {
            int x;cin>>x;
            x--;
            char old=str[x];
            char neww=old=='L'?'R':'L';
            str[x]=neww;

            if(x-1>=0){
                if(str[x-1]=='L'&&str[x]=='R'&&pre[x-1]>suf[x])s.insert(x-1);
                if(old=='R'&&str[x-1]=='L'&&neww=='L')s.erase(x-1);
            }
            if(x+1<n){
                if(str[x+1]=='R'&&str[x]=='L'&&pre[x]>suf[x+1])s.insert(x);
                if(old=='L'&&str[x+1]=='R'&&neww=='R')s.erase(x);
            }
            if(sorted||s.size()==0)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            
        }
        
    }

return 0;
}