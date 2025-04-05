
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
        int x,y;cin>>x>>y;
        auto s=[&](int a)->int{
            int sum=0;
            while(a!=0){
                sum+=a%10;
                a/=10;
            }
            return sum;
        };
        // cout<<x<<" "<<y<<endl;
        if(y>x){
            if(y-x==1||(x%9==0&&y==1))cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        else {
            int sum1=s(x),sum2=s(y);
            if(abs(sum1-sum2)==1)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;

        }
    }

    return 0;
}