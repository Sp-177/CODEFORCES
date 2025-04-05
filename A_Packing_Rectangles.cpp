#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool predicate_funct(long long w,long long h,long long n,long long len){
    long long r=len/w;
    long long c=len/h;
    return (c>0&&(r>=((n+c-1)/c)));

}
int main(){
long long w,h,n;cin >> w >> h >> n;
long long low=0,high=(w>h?1LL*w*n:1LL*h*n);
while(low<=high){
    long long mid=(low+high)/2LL;
    if(predicate_funct(w,h,n,mid))high=mid-1;
    else low=mid+1;
}
cout<<low<<endl;
return 0;
}