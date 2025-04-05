#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
long long t;cin>>t;
while(t--){
    long long n;cin>>n;
    long long arr[n][2];
    for(long long i=0;i<n;i++)cin>>arr[i][0]>>arr[i][1];
    // for(long long i=0;i<n;i++)cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
    
    auto predicate_funct =[&](long long persons)->bool{
        // cout<<t<<" ->"<<persons<<endl;
        long long rich=persons-1;
        long long poor=0,total=0;
        for(long long i=0;i<n;i++){
            
            if(arr[i][0]>=rich&&arr[i][1]>=poor){
                total++;
                rich--;
                poor++;
            }
            
            if(total==persons)return true;
        }

        return false;
    };

    long long low=1,high=n;
    while(low<=high){
        long long mid=(low+high)/2;
        if(predicate_funct(mid)){
            low=mid+1;
        }
        else high=mid-1;
    }
    cout<<high<<endl;

}

return 0;
}