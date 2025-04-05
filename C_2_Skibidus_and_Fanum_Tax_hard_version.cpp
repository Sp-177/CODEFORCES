
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t=1;
    cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        int a[n], b[m];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<m;i++)cin>>b[i];
        sort(b,b+m);
        int c[n];
        for(int i=0;i<n;i++)c[i]=a[i];
        bool fl=true;
        c[0]=min(b[0]-c[0],c[0]);
        for(int i=1;i<n;i++){
            
                int fnd=c[i-1]+c[i];
                int ind=lower_bound(b,b+m,fnd)-b;
                if(c[i-1]<=c[i]){
                    if(ind<m){
                        if((b[ind]-c[i])>=c[i-1])c[i]=min(c[i],b[ind]-c[i]);
                    }
                    else{
                        if((b[m-1]-c[i])>=c[i-1])c[i]=min(c[i],b[m-1]-c[i]);
                    }
                }
                else{
                    if(ind<m){
                        if((b[ind]-c[i])>=c[i-1])c[i]=b[ind]-c[i];
                    }
                    else{
                        if((b[m-1]-c[i])>=c[i-1])c[i]=b[m-1]-c[i];
                    }
                }
                
          
            if(c[i-1]>c[i]){
                fl=false;
                break;
            }
        }
        
        if(fl)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}