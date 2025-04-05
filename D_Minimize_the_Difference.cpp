#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int t;cin >> t;
while(t--){
    long long n;cin>>n;
    long long arr[n];
    long long sum=0LL,low=LLONG_MAX,high=LLONG_MIN;
    for(int i=0;i<n;i++){cin>>arr[i];sum+=arr[i];low=min(low,arr[i]);high=max(high,arr[i]);}
    long long ans=high-low;
    // while(low<high){
    long long avg=sum/n +(sum%n?1:0);
    long long carry=0LL;
    long long total=n;
    for(int i=0;i<n;i++){
        total--;
        if(arr[i]+carry>=avg){
            carry+=arr[i]-avg;
            sum-=avg;
            arr[i]=avg;
        }
        else{
            arr[i]+=carry;
            sum-=arr[i];
            carry=0LL;
        if(total)avg=sum/total ;
            
        }

    }
    // cout<<"C"<<carry<<endl;
    // for(int i=0;i<n;i++)cout<<arr[i]<<' ';
    // cout<<endl;
    long long maxi=LLONG_MIN,mini=LLONG_MAX;
    for(int i=0;i<n;i++){maxi=max(maxi,arr[i]);mini=min(mini,arr[i]);}
    long long sub=maxi-mini;
    // if(sub<=ans){
    //     ans=min(ans,sub);
    //     low=avg+1;
    // }
    // else{
    //     high=avg-1;
    // }

    // }
    cout<<sub<<endl;

}

return 0;
}