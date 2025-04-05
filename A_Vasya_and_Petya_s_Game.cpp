

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t=1;
    // cin>>t;
    vector<int>prm(1001,1);
    for(int i=2;i*i<=1000;i++){
        if(prm[i])
            for(int j=i*i;j<=1000;j+=i)
                prm[j]=0;
    }
    vector<int>primes;
    for(int i=2;i<=1000;i++){
        if(prm[i])primes.push_back(i);
    }
    set<int>st;
    for(int i:primes){
        int num=i;
        while(num<=1000){
            st.insert(num);
            num*=i;
        }
    }
    
    
    while(t--){
        int n;cin>>n;
       vector<int>ans;
       for(auto i:st){
        if(i>n)break;
        ans.push_back(i);
       }
         cout<<ans.size()<<endl;
            for(auto x:ans)cout<<x<<" ";
            cout<<endl;

        
    }

    return 0;
}