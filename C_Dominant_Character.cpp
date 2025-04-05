#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n;cin>>n;
    string s;
    cin>>s;
   
    long long ans=LLONG_MAX;
   vector<long long>ind;
   for(long long i=0;i<n;i++){
    if(s[i]=='a')ind.push_back(i);
   }
    // cout<<ind.size()<<endl;
    if (ind.size() < 2) {
        cout << -1 << endl;
        return;
    }

    for(long long i=0;i<ind.size()-1;i++){
        long long start=ind[i];
        long long end=ind[i+1];
        // cout<<start<<end<<endl;
        vector<long long>freq(3,0);
        for(long long j=start;j<=end;j++){
            freq[s[j]-'a']++;
        }
        if(freq[0]>freq[1]&&freq[0]>freq[2]){
            if(ans>end-start+1){ans=end-start+1;}
        }
        if(i+2<ind.size()){
            long long end1=ind[i+2];
            for(long long j=end+1;j<=end1;j++){
            freq[s[j]-'a']++;
            if(freq[0]>freq[1]&&freq[0]>freq[2]){
            if(ans>end1-start+1){ans=end1-start+1;}
        }
        }
        }
    }
    
    cout<<(ans==LLONG_MAX?-1:ans)<<endl;
}
int main(){
    long long t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}