// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code here
    int n,q;cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    while(q--){
        int x;cin>>x;
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]<=x)low=mid+1;
            else high=mid-1;
        }
        cout<<high+1<<endl;
    }

    return 0;
}