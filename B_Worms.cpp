#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
long long n;
cin>>n;
long long worms[n];
for(int i=0; i<n; i++)cin>>worms[i];
long long nums[n];
nums[0]=worms[0];
for(int i=1;i<n;i++)nums[i]=nums[i-1]+worms[i];
long long q;cin>>q;
long long query[q];
for(int i=0;i<q;i++){
    int num;cin>>num;
    int index=lower_bound(nums,nums+n,num)-nums;
    cout<<index+1<<endl;

}

return 0;
}