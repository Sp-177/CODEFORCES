#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool sol(map<int,int>&m,int num,int diff){
    // cout<<num<<" "<<endl;
    if(m[num]>0){
        m[num]--;
        if(m[num]==0){m.erase(num);}
        return true;
    }
    for(auto i:m){
        if(i.second>0){
        int low=i.first;
        if(low>num){return false;}
        if((num-low)%diff==0){
            m[low]--;
            if(m[low]==0){m.erase(low);}
            // cout<<low<<endl;
            return true;
        }
        }
    }
    return false;

}
int main(){
    int t;cin>>t;
    while(t--){
        int n,y;cin>>n>>y;
        map<int,int>m;
        int ans=0;
        int i=0;
        vector<int> arr(n);

        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr.begin(),arr.end());
        set<int>s(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++){
            
            int num=arr[i];
            if(ans>num){
                m[num%y]++;
            }
            if(s.find(ans)!=s.end()){
                s.erase(i);
                ans++;
                continue;
            }
            else{
                if(num<ans){
                   if(m[ans%y]>0){
                    m[ans%y]--;
                    if(m[ans%y]==0){m.erase(ans%y);}
                    ans++;
                   } 
                }
                if(num>ans)break;
                
            }
        }
        cout<<ans<<endl;
    }
}