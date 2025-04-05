#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
long long n,t;cin >> n >> t;
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
 for(int i=0;i<20&&(low<=high);i++){
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

return 0;
}