#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
class Solution{
    public:
        bool sol(ull ans){
            ull x=(sqrt(ans));
            if(ans==x*x)return true;
            return false;
        }
};
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int b;cin>>b;
        ull v=0;
        for(int j=0;j<b;j++){
            ull temp;cin>>temp;
            v+=temp;
        }
        Solution s;
        bool x=s.sol(v);
        if(x)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}