#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        int arr[n];
        for(int i=0;i<n;i++)cin >> arr[i];
        set<int>st;
        st.insert(-1);
        for(int i=0;i<n;i++){
            if(st.find(i-1)!=st.end()){
                st.insert(arr[i]+i);
            }
            if(st.find(i-arr[i]-1)!=st.end()){
                st.insert(i);
            }
            
        }
        if(st.find(n-1)!=st.end())cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}