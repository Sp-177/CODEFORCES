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
        int ind=lower_bound(arr,arr+n,x)-arr;
        if(ind<n&&arr[ind]==x)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}