#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
int t;cin>>t;

while(t--){
    int n;cin>>n;
    if(n==1||n==2||n==3){
        if(n&1)cout<<-1<<endl;
        else cout<<66<<endl;
    }
    else if(n&1){
        for(int i=0;i<n-4;i++)cout<<3;
        cout<<6366<<endl;

    }else{
        for(int i=0;i<n-2;i++)cout<<3;
        cout<<66;
        cout<<endl;
    }

}

return 0;
}