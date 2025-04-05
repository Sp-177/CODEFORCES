#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
long long n;cin>>n;
long long arr[n];
map<long long,long long>mp;
for(int i=0;i<n;i++){cin >>arr[i];mp[abs(arr[i])]++;}
long long m=mp.size();
vector<long long> nums(m);
long long pre[m];
int j=0;
for(auto i:mp){
    nums[j]=i.first;
    pre[j]=i.second;
    if(j>0)pre[j]+=pre[j-1];j++;
}
long long ans=0;
// for(int i:nums)cout<<i<<" ";
// cout<<endl;
// for(int i:pre)cout<<i<<" ";
// cout<<endl;
for(long long i:nums){
    long long num=abs(i);
    long long not_num=2*num+1;
    auto it=lower_bound(nums.begin(),nums.end(),not_num);
    long long index1=lower_bound(nums.begin(),nums.end(),num)-nums.begin();
    if(it!=nums.end()){
        int index=it-nums.begin();
        ans+=(pre[index-1]-pre[index1])*(pre[index1]-(index1-1>=0?pre[index1-1]:0));;
    }
    else{
        
        ans+=(pre[m-1]-pre[index1])*(pre[index1]-(index1-1>=0?pre[index1-1]:0));
    }
    long long self=(pre[index1]-((index1-1)>=0?pre[index1-1]:0));
    ans+=(self*(self-1))/2;
    // cout<<index1<<endl;
}

cout<<ans<<endl;
return 0;
}