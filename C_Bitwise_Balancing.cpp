#include<iostream>
#include<bits/stdc++.h>
using namespace std;



long long solve(){
     long long b,c,d;cin>>b>>c>>d;
     long long a=0LL;
     for(int i=0;i<63;i++){
        long long t_b=b&1,t_c=c&1,t_d=d&1;
        long long t_a=0LL;
        if(t_d==1){
            if(t_b==0){
                if(t_c==1)return -1;
                else t_a=1;
            }
            else{
                if(t_c==1)t_a=0;
                else t_a=1;
            }
        }
        else{
             if(t_b==0){
                if(t_c==1)t_a=1;
                else t_a=0;
            }
            else{
                if(t_c==1)t_a=1;
                else return -1;
            }

        }
        b>>=1;
        long long shift=t_a<<i;
        a|=shift;
        c>>=1;
        d>>=1;
     }
     return a;
        
}
int main(){
    int t;
    cin>>t;
    while(t--){
       cout<<1LL*solve()<<endl;

    }
}