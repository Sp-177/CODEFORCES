#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int t;cin>>t;
while(t--){
    int n,d,j;cin>>n>>d>>j;
    map<int,vector<int>>in_time,out_time;
    int cnt=1;
    for(int i=0;i<j;i++){
        int x,y;cin>>x>>y;
        in_time[x].push_back(cnt);
        out_time[y].push_back(cnt);
        cnt++;
    }
    int bro_ans=1;
    int bro_job=0;
    set<int>bro;
    for(int i=1;i<=d;i++){
        if(in_time[i].size()){
            for(int j:in_time[i])bro.insert(j);
        }
    }
    bro_job=bro.size();
    
    for(int i=2;i<=n-d+1;i++){
        int last=i+d-1;
        if(in_time[last].size()){
            for(int j:in_time[last])bro.insert(j);
        }
        if(out_time[i-1].size()){
        for(int j:out_time[i-1])bro.erase(j);
        }
        if(bro.size()>bro_job){
            bro_job=bro.size();
            bro_ans=i;
        }
    }
        int mom_ans=1;
    int mom_job=0;
    set<int>mom;
    for(int i=1;i<=d;i++){
        if(in_time[i].size()){
            for(int j:in_time[i])mom.insert(j);
        }
    }
    mom_job=mom.size();
    
    for(int i=2;i<=n-d+1;i++){
        int last=i+d-1;
        if(in_time[last].size()){
            for(int j:in_time[last])mom.insert(j);
        }
        if(out_time[i-1].size()){
        for(int j:out_time[i-1])mom.erase(j);
        }
        if(mom.size()<mom_job){
            mom_job=mom.size();
            mom_ans=i;
        }
    
    


    }cout<<bro_ans<<" "<<mom_ans<<endl;

}

return 0;
}