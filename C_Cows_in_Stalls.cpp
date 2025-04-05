#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
long long n,k;cin>>n>>k;
long long stalls[n];
for(long long i=0;i<n;i++)cin>>stalls[i];

auto predicate_function =[&](long long diff){
long long cnt = 1;
long long curr=stalls[0];
for(int i=1;i<n;i++){
    if(stalls[i]-curr>=diff){
        curr=stalls[i];
        cnt++;
    }
}

return cnt>=k;


};


long long low=0,high=1e9;
while(low<=high){
    long long mid=(low+high)/2;
    if(predicate_function(mid))low=mid+1;
    else high=mid-1;
}
cout<<high<<endl;

return 0;
}