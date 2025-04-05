#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int c,r,q;cin>>c>>r>>q;
vector<vector<int>>grid(r,vector<int>(c));
for(int i=0;i<c;i++){
    for(int j=0;j<r;j++){
        cin>>grid[j][i];
    }
}
for(int i=0;i<r;i++){
    for(int j=1;j<c;j++)grid[i][j]|=grid[i][j-1];
}
// for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<grid[i][j]<<' ';cout<<endl;}
for(int i=0;i<q;i++){
    int m;cin>>m;
    bool check=true;
    int ans1=1,ans2=c+1;
    for(int i=0;i<m;i++){
        int reg,val;
        char op;
        cin>>reg>>op>>val;
        reg--;
        if(op=='<'){
            int ind=lower_bound(grid[reg].begin(),grid[reg].end(),val)-grid[reg].begin();
            ind--;
            if(ind<0)check=false;
            else{
                ans2=min(ans2,ind+1);
            }
        }else{
            int ind=upper_bound(grid[reg].begin(),grid[reg].end(),val)-grid[reg].begin();
            if(ind>=c)check=false;
            else{
                ans1=max(ans1,ind+1);
            }
        }
    }
    if(check&&ans1<=ans2)cout<<ans1<<endl;
    else cout<<-1<<endl;

}
return 0;
}