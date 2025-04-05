#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
long long t;cin >> t;
while(t--){
    auto query=[&](long long l,long long r)->long long{
        cout<<"? "<<(r-l+1)<<" ";
        for(long long i=l; i<=r; i++)cout<<i<<" ";
        cout<<endl;
        long long sum;cin >> sum;
        return sum; 
    };
    auto answer=[&](long long index)->void{cout<<"! "<<index<<endl;};
    long long n;cin>>n;
    long long piles[n];
    for(long long i=0; i<n; i++)cin>>piles[i];
    long long prefix[n+1];
    prefix[0]=0;
    for(long long i=1; i<=n; i++)prefix[i]=prefix[i-1]+piles[i-1];
    long long low=1,high=n;
    while(low<=high){
     long long mid=(low+high)/2;
     long long prefix_sum=prefix[mid]-prefix[low-1];
     long long query_sum=query(low,mid);
    //  cout<<prefix_sum<<" "<<query_sum<<endl;
     if(query_sum==prefix_sum)low=mid+1;
     else high=mid-1;   
    }
    answer(low);
    }

return 0;
}