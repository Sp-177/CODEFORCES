#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
int t;cin>>t;
while(t--){
    int n;cin>>n;string str;cin>>str;
    map<char,char>m;
    for(int i=0;i<n;i++){
        int ind=str[i]-'a';
        bool check=false;
        for(auto j:m){if(j.second==str[i]){check=true;break;}}
        if(check==false){
        for(int j=0;j<26;j++){
            if(ind!=j){
                char c=j+'a';

                if(m.find(c)==m.end()){
                    bool check1=false;
                    
                    // cout<<c<<"  "<<char(ind+'a')<<endl;
                }
            }
        }
        }
    }
    for(auto i:str){
        for(auto j:m)if(j.second==i)cout<<j.first;
    }
    cout<<endl;
}

return 0;
}