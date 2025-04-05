#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
string str;cin >> str;
 long long b_have,s_have,c_have;cin>>b_have>>s_have>>c_have;
 long long p_b,p_s,p_c;cin>>p_b>>p_s>>p_c;
 long long budget;cin >> budget;
 long long b_need=0,s_need=0,c_need=0;
for(auto i:str){
    if(i=='B')b_need++;
    else if(i=='S')s_need++;
    else c_need++;
}

if(b_need==0&&s_need==0&&c_need==0){cout<<0<<endl;return 0;}

auto predicate_function=[&]( long long burgers){
 long long total_b=max(0LL,b_need*burgers-b_have) , total_c=max(0LL,c_need*burgers-c_have),total_s=max(0LL,s_need*burgers-s_have);
 long long cost=0;
cost+=p_b*total_b;
cost+=p_c*total_c;
cost+=p_s*total_s;
return (cost<=budget);
};



long long low=0,high=1e15;
while(low<=high){
      long long mid=(low+high)/2LL;
    if(predicate_function(mid)){
        low=mid+1;
    }
    else high=mid-1;
}
cout<<high<<endl;

return 0;
}