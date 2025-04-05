#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>cmp;
static const bool cmp1(vector<int>&a,vector<int>&b){
    int num11=a[0],num12=a[1],num21=b[0],num22=b[1];
    int sum1=num11+num12,sum2=num21+num22;
    if(sum1<sum2)return true;
    else if(sum1==sum2){
        if(num11<num21)return true;
        else if(num12<num22)return true;
        
    }
    return false;
}

int main(){
int t;cin>>t;
while(t--){
    int n;cin>>n;
    vector<vector<int>>v(n);
    vector<int>arr;
    set<int>s;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        v[i]={x,y};
        if(s.find(x)==s.end()){arr.push_back(x);s.insert(x);}
         if(s.find(y)==s.end()){arr.push_back(y);s.insert(y);}
    }
    sort(arr.begin(),arr.end());
    for(int i:arr)cmp.push_back(i);

    sort(v.begin(),v.end(),cmp1);
   for(int i=0;i<n;i++){
    cout<<v[i][0]<<' '<<v[i][1]<<' ';
   }
   cout<<endl;
}
return 0;
}