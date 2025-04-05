#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sol(long long &x,long long &y,long long&d,long long sign){
    long long fact=min(y-x,d);
    if(sign>0){
        x+=fact;
        d-=fact;
    }
    else{
     y-=fact;
     d-=fact;   
    }
}
void solve(){
    long long n;cin>>n;
    long long a[n],b[n];
    for(long long i=0;i<n;i++)cin>>a[i];
    for(long long i=0;i<n;i++)cin>>b[i];
    long long sum1=0,sum2=0,ans1=0,ans2=0;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]){
            if(a[i]==1)sum1+=1;
            else if(a[i]==-1)sum2+=1;
        }
        else if(a[i]>b[i]){
            ans1+=a[i];
        }
        else ans2+=b[i];
    }
    if(ans1<ans2)sol(ans1,ans2,sum1,1);
    else if(ans2<ans1) sol(ans2,ans1,sum1,1);
    if(sum1&1){
        ans1+=(sum1/2 +1);
    }
    else{
        ans1+=sum1/2;
    }
    ans2+=(sum1/2);

     if(ans1<ans2)sol(ans1,ans2,sum2,-1);
    else if(ans2<ans1) sol(ans2,ans1,sum2,-1);
    if(sum2&1){
        ans1-=(sum2/2 +1);
    }
    else{
        ans1-=sum2/2;
    }
    ans2-=(sum2/2);

    cout<<min(ans1,ans2)<<endl;
}
int main(){
    long long t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}