#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
long long n,k;cin>>n>>k;
long long arr[n];
for(long long i=0;i<n;i++)cin>>arr[i];

auto predicate_function=[&](long long x){
    long long cnt=1,sum=0;
    for(long long i=0;i<n;i++){
        if(sum+arr[i]>x){cnt++;sum=0;}
        sum+=arr[i];
    }
    return (cnt<=k);
};

long long low=*max_element(arr,arr+n),high=1e14;
while(low<=high){
    long long mid=(low+high)/2;
    if(predicate_function(mid))high=mid-1;
    else low=mid+1;
}
cout<<low<<endl;
return 0;
}