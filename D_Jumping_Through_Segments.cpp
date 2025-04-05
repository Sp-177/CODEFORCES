#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool predicate_funct(int a[],int b[],int n,long long mid){
    long long start=0,end=0;
    for(int i=0;i<n;i++){
        long long x=a[i],y=b[i];
        start=max(start-mid,x);
        end=min(end+mid,y);
        if(end<start)return false;
    }
    return true;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++){cin>>a[i];cin>>b[i];}
        long long low=0,high=1e9;
        while(low<=high){
            long long mid=(low+high)/2LL;
            if(predicate_funct(a,b,n,mid)){
                high=mid-1;
            }
            else low=mid+1;
        }cout<<low<<endl;
    }
    

return 0;
}