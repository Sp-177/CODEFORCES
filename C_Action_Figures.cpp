#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int t;cin>>t;
while(t--){
    int n;cin>>n;
    string str;cin>>str;
    vector<int>zero,one;
    for(int i=0;i<n;i++){
        if(str[i]=='0')zero.push_back(i);
        else one.push_back(i);
    }
    long long ans=0;
    int o_ind=one.size()-1,z_ind=zero.size()-1;
    set<int>s;
    while(z_ind>=0&&o_ind>=0){
        while(zero[z_ind]>one[o_ind])z_ind--;
        if(z_ind<0)break;
        int index_z=zero[z_ind],index_o=one[o_ind];
        s.insert(index_o);
        one.pop_back();
        z_ind--;o_ind--;
    }
    int start=0,end=one.size()-1;
    while(start<end){
        int index_o_s=one[start],index_o_e=one[end];
        s.insert(index_o_e);
        end--;
        start++;
    }
    for(int i=0;i<n;i++){
        if(s.find(i)==s.end())ans+=i+1;
    }
    cout<<ans<<endl;
}

return 0;
}