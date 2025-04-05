#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    long long t;cin>>t;
    while(t--){
        long long n;cin>>n;
        long long arr[n];
        map<long long,long long>m;
        for(int i=1;i<=n;i++){
            cin>>arr[i-1];
            m[arr[i-1]]=i;
        }
        long long cnt=0;
        for(auto i:m){
            
            int num1=i.first,ind1=i.second;
            int num2=i.second,ind2=m[i.second];
            // cout<<num1<<" "<<ind1<<" "<<num2<<" "<<ind2<<endl;
            if(num1==ind1)cnt++;
            else{
                if(num2==ind1&&ind2==num1&&(abs(num2-num1)==1))cnt++;
            }

        }
        if(cnt==n)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
        
    }

}