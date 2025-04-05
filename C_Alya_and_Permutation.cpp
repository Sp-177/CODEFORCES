#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int t;cin>>t;
while(t--){
    int n;cin>>n;
    
    if(n&1){
        cout<<n<<endl;
        cout<<2<<' '<<1<<' ';
        for(int i=3;i<=n;i++)cout<<i<<' ';
    }
    else{
        int dig=log2(n);
        int ans=(1<<(dig+1))-1;
        cout<<ans<<endl;
        int need=ans^n;
        if(need+1==n){
            cout<<2<<' '<<1<<' ';
            for(int i=3;i<=n;i++)cout<<i<<' ';
        }else{
            for(int i=1;i<n;i++){
                if(i==need||i==need+2)continue;
                cout<<i<<' ';
            }
            cout<<need+2<<" "<<need<<" "<<n;
        }
        
    }
    
    cout<<endl;
}

return 0;
}