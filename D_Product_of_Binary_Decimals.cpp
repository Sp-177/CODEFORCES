// Online C++ compiler to run C++ program online
#include<iostream>
#include<bits/stdc++.h>
#include<unordered_set>
#include<string>
#include<vector>
using namespace std;
void sol1(int size,vector<int>&ans,string output){
    if(size>5 && stoi(output)>1e5)return;
    ans.push_back(stoi(output));
    sol1(size+1,ans,output+'1');
    sol1(size+1,ans,output+'0');
}
void sol2(int i,vector<int>&ans,unordered_set<int>&Ans,int product,int n,bool&say){
    if(i==ans.size() || product>1e5)return;
    Ans.insert(product);
    if(Ans.find(n)!=Ans.end()){say=true;return;}
    sol2(i,ans,Ans,product*ans[i],n,say);
    sol2(i+1,ans,Ans,product,n,say);
}
int main() {
    // Write C++ code here
    vector<int>ans;
    unordered_set<int>Ans;
    sol1(1,ans,"1");
    int t;cin>>t;while(t--){
    int n;cin>>n;
    bool say=false;
    sol2(1,ans,Ans,1,n,say);
    if(say)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    }

    return 0;
}