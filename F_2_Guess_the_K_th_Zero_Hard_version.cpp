#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
long long n,t;cin >> n >> t;
long long cache[n];
memset(cache,-1,sizeof(cache));

for(long long i=0;i<t;i++){
long long k;cin>>k;
long long low=1,high=n;
 auto query=[&](long long l,long long r)->long long{
    cout<<"? "<<l<<" "<<r<<endl;
    long long sum;cin >> sum;
    return sum;
 };
 auto answer=[&](long long index)->void{
    cout<<"! "<<index<<endl;
 };
 long long index=k-1;
if(i!=0){
    long long cnt=0,index2=0;
    for(long long j=0;j<n;j++){
        if(cache[j]==-1)cnt++;
        else if(cache[j]!=-1&&cnt<k){
            low=max(low,cache[j]+1);
            index2=j;
        }
        else if(cache[j]!=-1&&cnt>=k){
            high=min(high,cache[j]-1);
            break;
        }
        if(cnt==k)index=j;
    }
    long long cnt1=0;
    for(long long j=0;j<index2;j++){
        if(cache[j]==-1)cnt1++;
    }
    k-=cnt1;
    // cout<<index2<<endl;
}
// cout<<k<<endl;
 while(low<=high){
    long long mid=(low+high)/2;
    long long sum=query(low,mid);
    long long maxi=mid-low+1,zeroes=maxi-sum;
    if(zeroes>=k){
        high=mid-1;
    }
    else{
        k-=zeroes;
        low=mid+1;
    }
 }
 answer(low);
 cache[index]=low;
//  for(auto j:cache)cout<<j<<" ";
//  cout<<endl;
}
return 0;
}