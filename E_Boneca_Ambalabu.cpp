#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;++i)
            cin>>a[i];

        int c[30]={0};
        for(int i=0;i<n;++i)
            for(int b=0;b<30;++b)
                if((a[i]>>b)&1)
                    c[b]++;

        long long res=0;
        for(int i=0;i<n;++i){
            long long s=0;
            for(int b=0;b<30;++b){
                if((a[i]>>b)&1)
                    s+=(1LL*(n-c[b])<<b);
                else
                    s+=(1LL*c[b]<<b);
            }
            if(s>res)res=s;
        }
        cout<<res<<'\n';
    }
    return 0;
}
