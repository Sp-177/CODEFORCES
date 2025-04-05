#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sol(int *a,int n){
    int ans=0;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1])ans++;
    }
    return ans;
}
int main(){

int t;cin>>t;
while(t--){
    int n;cin>>n;
    int a[n];
    for(int i=0; i<n; i++)cin>>a[i];
    int ans1=sol(a,n);
    int start=1,end=n-2;
    while(start<end&&end>=0&&start<n){
        if(a[start]==a[start-1]){
            swap(a[start],a[end]);
        }
        else if(a[end]==a[end+1]){
            swap(a[start],a[end]);
        }
        start++;end--;
    }
    int ans2=sol(a,n);
    cout<<min(ans1,ans2)<<endl;

}
return 0;
}