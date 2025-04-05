#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int t;cin>>t;
while(t--){
    long long a,b;cin>>a>>b;
    long long arr[a];
    for(int i=0;i<a;i++)cin>>arr[i];
    sort(arr,arr+a);
    if(a>=b)cout<<b<<endl;
    else{
        long long ans=0;
        long long already=0;
        long long ind=0;
        while(b>0&&ind<a){
            if((a-ind)*(arr[ind]-already)>=b){
                ans+=b;
                b=0;
            }
            else{
                ans+=(arr[ind]-already)*(a-ind) +1;
                b-=(a-ind)*(arr[ind]-already);
               
            } 
            already+=(arr[ind]-already);ind++;
        }
        cout<<ans<<endl;
    }
}

return 0;
}