#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long query(long long l,long long r){
    cout<<"? "<<l<<" "<<r<<endl;
    long long index;cin >> index;
    return index;
}
int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
long long n;cin>>n;
long long sec=query(1,n);
auto left=[&](long long low,long long high)->long long{
    
    while(low<=high){
        long long mid=(low+high)/2;
        long long index=query(mid,sec);
        if(index==sec){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high;

};
auto right=[&](long long low,long long high)->long long{
    
    while(low<=high){
        long long mid=(low+high)/2;
        long long index=query(sec,mid);
        if(index==sec){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;

};
long long ans=0;
if(sec!=1&&query(1,sec)==sec)ans=left(1,sec-1);
else ans=right(sec+1,n);
cout<<"! "<<ans<<endl;
return 0;
}