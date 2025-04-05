#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
long long k,n;cin>>k>>n;
long long grps[n];
for(int i=0;i<n;i++)cin>>grps[i];

auto predicate_function=[&](long long x){
    long long total=0,need=x*k;
    for(int i=0;i<n;i++){
        total+=min(x,grps[i]);
        if(total>=need)return true;
    }
    return false;
};
long long low=0,high=5LL*1e16;
while(low<=high){
    long long mid=(low+high)/2;
    if(predicate_function(mid)){
        low=mid+1;
    }
    else high=mid-1;
}
cout<<high<<endl;

return 0;
}