#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int t;cin >> t;
while(t--){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){cin>>arr[i];arr[i]--;}
    int count=0;
    // for(int i=0;i<n;i++)cout<<arr[i]<<endl;
    for(int i=0;i<n;i++){
        int nex=arr[i];
        if(nex==i||arr[nex]==i){continue;}
        else {
            if(nex>=i)count++;
            // cout<<i+1<<" "<<arr[nex]<<endl;
        }
    }

    cout<<(count-1)/2<<endl;
}

return 0;
}