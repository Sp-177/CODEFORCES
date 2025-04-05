#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool sol(  vector<vector<int>>&segs,int*arr,int q,int n,int mid){
    vector<int>v;
    for(int i=0;i<mid;i++)v.push_back(arr[i]);
    sort(v.begin(),v.end());
    // for(int i:v)cout<<i<<' ';
    // cout<<endl;
    for(auto i:segs){
            int l=i[0],r=i[1];
            int cnt1=r-l+1,cnt2=0;
            int ind1=lower_bound(v.begin(),v.end(),l)-v.begin();
            int ind2=lower_bound(v.begin(),v.end(),r)-v.begin();
            // cout<<ind1<<' '<<ind2<<endl;
            if(l<=v[ind1]&&v[ind1]<=r){
                if(ind2>=v.size()||v[ind2]>r)ind2--;
                if(l<=v[ind2]&&v[ind2]<=r)cnt2=ind2-ind1+1;
            }
            if(cnt1/2 +1<=cnt2)return true;
    }
    return false;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<vector<int>>segs(m);
        for(int i=0;i<m;i++){
            int x,y;cin>>x>>y;
            segs[i]={x,y};
        }
        int q;cin>>q;
        int arr[q];
        for(int i=0;i<q;i++)cin>>arr[i];
        int low =1,high=q;
        while(low<=high){
            int mid=(low+high)/2;
            bool check=sol(segs,arr,q,n,mid);
            if(check){
                high=mid-1;
            }
            else low=mid+1;
        }

        if(low>q)cout<<-1<<endl;
        else cout<<low<<endl;
    }


return 0;
}