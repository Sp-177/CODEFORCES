#include<iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
int  main(){
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    ll  t; cin >> t;
    while(t--) {
        ll  n; cin >> n;
        vector<ll > arr(n);
        for(ll  i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        
        map<ll , ll > mp;
        for(ll  i = 0; i < n; i++) mp[arr[i]]++;
        
        ll  cnt_quad = 0, cnt_doub = 0;
        
        for(auto it: mp) {
            if(it.second >= 4) cnt_quad++;
            else if(it.second >= 2) cnt_doub++;
        }

        if(cnt_quad) {
            for(auto it: mp) {
                if(it.second >= 4) {
                    cout << it.first << " " << it.first << " " << it.first << " " << it.first << endl;
                    break;
                }
            }
            continue;
        }
        else if(cnt_doub >= 2) {
            ll  l = -1, b = -1; 
            for(auto it: mp) {
                if(it.second >= 2 && l == -1) {
                    l = it.first;
                } else if(it.second >= 2) {
                    b = it.first;
                    break;
                }
            }
            cout << l << " " << l << " " << b << " " << b << endl;
            continue;
        }
        
        bool check = false;    
        // cout<<"XX"<<endl;
        ll  big=-1;
        for(auto it: mp) {
            if(it.second >= 2 && it.first > big) {
                big = it.first;
            }
        }
        mp[big]-=2;
        ll  small1=-1,small2=-1;
        vector<int>ans;
        ans.push_back(big);
        ans.push_back(big);
        for(int i=0;i<n-1;i++){
            if(mp[arr[i]]>0 && mp[arr[i+1]]>0){
                if(arr[i]==arr[i+1] ){
                    if(mp[arr[i]]>=2){
                        ans.push_back(arr[i]);
                        ans.push_back(arr[i+1]);
                        check=true;
                        break;
                    }
                }
                else{
                    if(2*big>arr[i+1]-arr[i]){
                        ans.push_back(arr[i]);
                        ans.push_back(arr[i+1]);
                        check=true;
                        break;
                    }
                }

            }
        }
       
        if(!check) cout << -1 << endl; 
        else{
            sort(ans.begin(), ans.end());
            for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
            cout << endl;
        }
    }

    return 0;
}
