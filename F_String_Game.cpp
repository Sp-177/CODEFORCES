#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
string t,p;cin>>t>>p;
long long t_len=t.length(),p_len=p.length();
long long arr[t_len];
for(long long i=0;i<t_len;i++){cin>>arr[i];}


auto  predicate_func=[&](long long mid)->bool{
    long long ind_p=0;
    set<long long>deleted_ind;
    for(long long i=0;i<mid;i++)deleted_ind.insert(arr[i]-1);
    for(long long i=0;i<t_len;i++){
        if(deleted_ind.find(i)==deleted_ind.end()){

            if(t[i]==p[ind_p])ind_p++;
            if(ind_p>=p_len)return true;
        }
    }
    
    return false;
};

long long low=0,high=abs(t_len-p_len);
while(low<=high){
    long long mid=(low+high)/2;
    if(predicate_func(mid)){
    low=mid+1;
    }
    else high=mid-1;
}
cout<<high<<endl;

return 0;
}