#include<iostream>
#include<bits/stdc++.h>
#include <iomanip>
using namespace std;

pair<long,long> predicate_funt(long double arr[],long long n,long double mid,long long d){
    long double prefix[n];
    prefix[0]=arr[0]-mid;
    int left=-1;
    for(long long i=1;i<n;i++)prefix[i]=prefix[i-1]+arr[i]-mid;
    long double min_till_now=0;
    // for(auto i:prefix)cout<<i<<" ";
    // cout<<endl;
    for(int i=d-1;i<n;i++){
         
        if(i-d>=0&&min_till_now>prefix[i-d]){
            left=i-d;
            min_till_now=prefix[i-d];
        }
        if(prefix[i]-min_till_now>=0){
            return {left+1,i};
        }
       
    }
    return {-1,-1};
}
int main(){
long long n,d;cin>>n>>d;
long double arr[n];
pair<long ,long>ans;
for(long long i=0;i<n;i++)cin>>arr[i];
long double low=static_cast<long double>(0.0),high=static_cast<long double>(100.0);
for(int i=0;i<1000;i++){
    long double mid=(low+high)/2.0;
    pair<long ,long>p_f=predicate_funt(arr,n,mid,d);
    if(p_f.first!=-1){
        low=mid;
        ans=p_f;
    }
    else{
        high=mid;
    }
}
// cout<<low<<" "<<high<<endl;
cout<<ans.first+1<<" "<<ans.second+1<<endl;
return 0;
}