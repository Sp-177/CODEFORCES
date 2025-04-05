#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        bool check=true;
        int x=n;
        while(x>0){
            int ind=x-1;
            while(ind>=0&&(arr[ind]%(ind+2)==0)){ind--;}
            if(ind<0)break;
            arr.erase(arr.begin()+ind);
            x--;
        }
        if(x==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

return 0;
}