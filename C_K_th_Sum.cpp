#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
long long n,k;cin>>n>>k;
long long a[n],b[n];
for(long long i=0;i<n;i++)cin>>a[i];
for(long long i=0;i<n;i++)cin>>b[i];
sort(a,a+n);sort(b,b+n);

function<long long(long long mid)>bsf=[&](long long mid){
long long sum=a[mid]+b[0];
long long pos=1LL;
cout<<mid+1<<endl;
for(long long i=0;i<mid;i++){
    long long rem=sum-a[i];
    int it=lower_bound(b,b+n,rem)-b;
    cout<<i<<" "<<it<<endl;
    if(a[i]+b[it]<sum){
        pos+=it+1;
    }
    else{
        pos+=it;
    }

}
cout<<pos<<endl;
return pos;



};

long long a_low=0LL,a_high=n-1LL;
while(a_low<=a_high){
    long long a_mid=(a_low+a_high)/2LL;
    long long a_pos=bsf(a_mid);
    if(a_pos<=k){
        a_low=a_mid+1;
    }
    else{
        a_high=a_mid-1;
    }
}
long long pos=bsf(a_high),b_index=0;
for(long long i=1;i<n;i++){
    pos++;
    if(pos==k){
        b_index=i;
        break;
    }
}
cout<<a[a_high]+b[b_index]<<endl;
return 0;
}