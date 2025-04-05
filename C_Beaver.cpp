
#include<iostream>
#include<bits/stdc++.h>


using namespace std;

#define ll long long

//Hash

class Hsf {
    private:
        ll size = 1;
        vector<ll> modArr = {1000000007LL, 1000000019LL, 1000000037LL, 1000000039LL};

        vector<ll> pArr = {29, 31, 37, 41 };
        vector<vector<ll>> prefix;
    
        ll ctoi(char c) {
            if(c=='_')return 27;
            return c - 'a' + 1;
        }
    
        ll calc(ll p, ll pow, ll mod) {

            ll result = 1;
            while (pow > 0) {
                if (pow & 1) result = (result * p) % mod;
                pow >>= 1;
                p = (p * p) % mod;
            }
            return result;
        }
    
        void hash_func(const string& s) {
            ll n = s.size();
            
            prefix.resize(size, vector<ll>(n, 0));
    
            for (ll i = 0; i < size; i++) {
                ll mod = modArr[i], p = pArr[i];
                ll H = 0;
                ll p_pow = 1;
    
                for (ll j = 0; j < n; j++) {
                    ll num = ctoi(s[j]);
                    H = (H + (num * p_pow) % mod) % mod;
                    prefix[i][j] = H;
                    p_pow = (p_pow * p) % mod;
                }
            }
        }
    
    public:
        Hsf(const string& s) {
            
                hash_func(s);
            
        }
    
        vector<ll> hf(ll l, ll r) {
            vector<ll> ans(size, 0);
    
            for (ll i = 0; i < size; i++) {
                ll mod = modArr[i], p = pArr[i];
    
                ll h1 = prefix[i][r];
                ll h2 = (l - 1 < 0) ? 0 : prefix[i][l - 1];
                ll div=calc(p,l,mod);
                ll inv_mod=calc(div,mod-2,mod);
                ll h3 = (((h1 - h2 + mod) % mod) *inv_mod) % mod;
                ans[i] = h3;
            }
            return ans;
        }
    };
    
int main(){
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll mod=1e9+7;
    ll t=1;
    // cin>>t;
    while(t--){
        string s;cin>>s;
        Hsf *obj=new Hsf(s);
        ll n=s.length();
        ll q;cin>>q;
        map<ll,vector<ll>>ivt;
        while(q--){
            string str;cin>>str;
            Hsf *small_obj=new Hsf(str);
            ll len=str.length();
            ll str_hash=small_obj->hf(0,len-1)[0];
            for(ll i=0;i<=n-len;i++){
                ll hash_val=obj->hf(i,i+len-1)[0];
                if(hash_val==str_hash){
                    ivt[i].push_back(i+len-1);
                }
                // cout<<s.substr(i,len)<<" "<<str<<endl;
                // cout<<hash_val<<" "<<str_hash<<endl;
            }
        }
        // cout<<hashes.size()<<endl;
        ll ans=0,index=0;
        // cout<<n<<endl;
        for(auto i:ivt)sort(i.second.begin(),i.second.end());
        for(ll i=0;i<=n;i++){
            cout<<i<<' ';
            if(ivt.find(i)!=ivt.end()){
                for(auto j:ivt[i])cout<<j<<' ';
            }
            cout<<endl;
        }
        for(ll i=0;i<n;i++){
           
        }

        cout<<ans<<" "<<index<<endl;
        
    }

    return 0;
}