#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string  row1,row2;cin>>row1>>row2;
        int ans=0;
        vector<int>r1(n,1),r2(n,1);
        for(int i=0;i<n;i++){
            int d1=0,d2=0,d3=0,d4=0;
            if(i-1>=0){
                if(r1[i-1]&&r1[i]&&r2[i-1])d1=(row1[i-1]=='A'?1:0)  + (row1[i]=='A'?1:0) + (row2[i-1]=='A'?1:0) ;
                if(r2[i-1]&&r1[i]&&r2[i])d2=(row2[i]=='A'?1:0)  + (row1[i]=='A'?1:0) + (row2[i-1]=='A'?1:0) ;
                if(r1[i-1]&&r1[i]&&r2[i])d3=(row1[i-1]=='A'?1:0)  + (row1[i]=='A'?1:0) + (row2[i]=='A'?1:0 );
                if(r1[i-1]&&r2[i]&&r2[i-1])d4=(row1[i-1]=='A'?1:0)  + (row2[i]=='A'?1:0) + (row2[i-1]=='A'?1:0) ;
                
            }
           
            // cout<<d1<<" "<<d2<<" "<<d3<<" "<<d4<<" "<<endl;
            if(d1==2){
                ans++;
                r1[i]=r1[i-1]=r2[i-1]=0;
                // cout<<"d1 ";
            }
            else if(d4==2){
                ans++;
                r2[i-1]=r2[i]=r1[i-1]=0;
                // cout<<"d4 ";
            }
            else if(d3==2){
                ans++;
                r1[i]=r1[i-1]=r2[i]=0;
                // cout<<"d3 ";
            }
            else if(d2==2){
                ans++;
                r1[i-1]=r2[i]=r1[i]=0;
                // cout<<"d2 ";
            }
            
            else if(d1==3){
                r1[i]=r1[i-1]=r2[i-1]=0;
                // cout<<"1 ";
            }
            else if(d4==3){
                ans++;
                r2[i-1]=r2[i]=r1[i-1]=0;
                // cout<<"4 ";
            }
            else if(d3==3){
                ans++;
                r1[i]=r1[i-1]=r2[i]=0;
                // cout<<"3 ";
            }
            else if(d2==3){
                ans++;
                r1[i-1]=r2[i]=r1[i]=0;
                // cout<<"2 ";
            }
          
            
        }
        cout<<ans<<endl;
    }

return 0;
}