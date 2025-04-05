// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code here
    int n,q;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    cin>>q;
    sort(arr,arr+n);
    while(q--){
        int a,b;cin>>a>>b;
        int x=min(a,b),y=max(a,b);
        int ind1=lower_bound(arr,arr+n,x)-arr,ind2=upper_bound(arr,arr+n,y)-arr;
        if(ind2>=n||arr[ind2]>y)ind2--;
        // ind1=max(0,ind1);ind2=max(0,ind2);
        // cout<<ind1<<" "<<ind2<<endl;
        // if(ind1>ind2)cout<<0<<" ";
        cout<<ind2-ind1+1<<" ";

    }cout<<endl;

    return 0;
}