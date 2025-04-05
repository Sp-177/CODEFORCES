#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
long long t;cin >> t;
while(t--){
    long long n;cin>>n;
    long long ans=0;
    for(long long a=1;a<=sqrt(2LL*n-1);a++){
        long long b=(a*a -1 )/2;
        long long c=b+1;
        
            if(a*a +b*b==c*c){
                if(c==a*a-b){
                    ans++;
                }
            }
        
    }
    cout<<ans-1<<endl;
}

return 0;
}