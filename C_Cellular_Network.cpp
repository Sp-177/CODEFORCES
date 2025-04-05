#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
long long n,t;cin >> n >> t;

vector<long long> cities(n),towers(t);
for(int i=0;i<n;i++)cin>>cities[i];
for(int i=0;i<t;i++)cin>>towers[i];
// sort(cities.begin(),cities +n);sort(towers,towers +t);
long long low=0,high=1e18;
function <bool(long long )>predicate_func=[&](long long mid){
    long long cnt=0;
    for(int i=0;i<n;i++){
        long long l=cities[i]-mid,r=cities[i]+mid;
        auto i1=lower_bound(towers.begin(),towers.end(),l);
        auto i2=lower_bound(towers.begin(),towers.end(),r);
        if(i1!=towers.end()&&abs(*i1-cities[i])<=mid)cnt++;
        else if(i2!=towers.end()&&abs(*i2-cities[i])<=mid)cnt++;

        // if(mid==2)cout<<*i1<<" "<<*i2<<endl;
    }
    return cnt==n;
};
while(low<=high){
    long long mid=(low+high)/2LL;
    if(predicate_func(mid)){
        high=mid-1;
    }
    else low=mid+1;
}
cout<<low<<endl;

return 0;
}