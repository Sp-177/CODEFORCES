
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
        string str;cin >> str;
        stack<char>st;
        st.push(str[0]);
        for(int i=1;i<str.size();i++){
            char c=str[i];
            bool fl=true;
            // cout<<c<<" ";
            while(st.size()&&(st.top()==c||st.top()=='$')){
                // cout<<c<<endl;
                fl=false;
                st.pop();
                if(st.size())c=st.top();
                else {st.push('$');break;}
            }
            if(fl)st.push(c);
        }
        cout<<st.size()<<endl;
    }

    return 0;
}