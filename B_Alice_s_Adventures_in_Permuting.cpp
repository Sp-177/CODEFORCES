#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    long long t;cin>>t;
    while(t--){
        long long n,b,c;cin>>n>>b>>c;
       if(b==0){
            if(c<n-2)cout<<-1<<endl;
            else cout<<(c>=n?n:n-1)<<endl;
       }
       else{
        long long sub=n-c;
        long long cnt=0;
        if(c<n)cnt=sub/b+((sub%b!=0)?1:0);
        cout<<n-cnt<<endl;

       }
    }
    return 0;
}